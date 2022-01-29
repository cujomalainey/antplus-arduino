#include <MainClasses/ANTPLUS_AntPlusRouter.h>
#include <MainClasses/ANTPLUS_CallbackWorkAround.h>
#include <ANTPLUS_PrivateDefines.h>

AntPlusRouter::AntPlusRouter() {

}

AntPlusRouter::AntPlusRouter(BaseAntWithCallbacks* driver) {
    setDriver(driver);
}

AntPlusRouter::AntPlusRouter(BaseAntWithCallbacks* driver, const uint8_t* key) {
    setDriver(driver);
    setAntPlusNetworkKey(key);
}

uint8_t AntPlusRouter::setDriver(BaseAntWithCallbacks* driver) {
    // Synchronous locking nature needed to gurantee all configs were recieved
    RequestMessage rm;
    Capabilities cap;
    _ant = driver;
    // register callbacks
    _ant->onPacketError(onPacketErrorCallback, (uintptr_t)this);
    _ant->onAcknowledgedData(onAcknowledgedDataCallback, (uintptr_t)this);
    _ant->onAdvancedBurstData(onAdvancedBurstDataCallback, (uintptr_t)this);
    _ant->onBroadcastData(onBroadcastDataCallback, (uintptr_t)this);
    _ant->onBurstTransferData(onBurstTransferDataCallback, (uintptr_t)this);
    _ant->onAdvancedBurstCapabilitiesConfiguration(onAdvancedBurstCapabilitiesConfigurationCallback, (uintptr_t)this);
    _ant->onAntVersion(onAntVersionCallback, (uintptr_t)this);
    _ant->onCapabilities(onCapabilitiesCallback, (uintptr_t)this);
    _ant->onChannelEventResponse(onChannelEventResponseCallback, (uintptr_t)this);
    _ant->onChannelIdResponse(onChannelIdResponseCallback, (uintptr_t)this);
    _ant->onChannelStatus(onChannelStatusCallback, (uintptr_t)this);
    _ant->onEncryptionModeParameters(onEncryptionModeParametersCallback, (uintptr_t)this);
    _ant->onEventFilter(onEventFilterCallback, (uintptr_t)this);
    _ant->onSelectiveDataUpdateMaskSetting(onSelectiveDataUpdateMaskSettingCallback, (uintptr_t)this);
    _ant->onStartUpMessage(onStartUpMessageCallback, (uintptr_t)this);
    if (resetRadio(ANTPLUS_RESET_WAIT_FOR_STARTUP)) {
        return ANTPLUS_RESET_RADIO_FAILED;
    }
    pushNetworkKey();
    rm.setRequestedMessage(CAPABILITIES);
    _ant->send(rm);
    if (_ant->waitFor(cap, ANTPLUS_DRIVER_REQUEST_TIMEOUT)) {
        return ANTPLUS_MAX_CHANNEL_CHECK_FAILED;
    }
    _ant->getResponse().getCapabilitiesMsg(cap);
    onCapabilities(cap);
    return 0;
}

void AntPlusRouter::pushNetworkKey() {
    if (_ant && _networkKey) {
        SetNetworkKey snk = SetNetworkKey(ANTPLUS_NETWORKKEY_INDEX, (uint8_t*)_networkKey);
        send(snk);
    }
}

void AntPlusRouter::setAntPlusNetworkKey(const uint8_t* key) {
    _networkKey = key;
    pushNetworkKey();
}

void AntPlusRouter::setProfile(uint8_t channel, BaseProfile* profile) {
    // restrict user to maximum number of channels
    if (channel >= ANTPLUS_MAX_CHANNELS_POSSIBLE)
        return;
    removeProfileByChannel(channel);
    profile->setChannelNumber(channel);
    _profiles[channel] = profile;
    profile->setRouter(this);
}

void AntPlusRouter::removeProfile(const BaseProfile *profile) {
    for (uint8_t i = 0; i < ANTPLUS_MAX_CHANNELS_POSSIBLE; i++) {
        if (_profiles[i] == profile) {
            removeProfileByChannel(i);
        }
    }
}

void AntPlusRouter::removeProfileByChannel(uint8_t channel) {
    if (channel >= ANTPLUS_MAX_CHANNELS_POSSIBLE) {
        return;
    }
    if (_profiles[channel]) {
        _profiles[channel]->stop();
        _profiles[channel]->setChannelNumber(0);
        _profiles[channel]->setRouter(NULL);
        _profiles[channel] = NULL;
        UnAssignChannel uc;
        uc.setChannel(channel);
        send(uc);
    }
}

void AntPlusRouter::removeAllProfiles() {
    for (uint8_t i = 0; i < ANTPLUS_MAX_CHANNELS_POSSIBLE; i++) {
        removeProfileByChannel(i);
    }
}

void AntPlusRouter::send(AntRequest& msg) {
    if (_ant) {
        _ant->send(msg);
    }
}

uint8_t AntPlusRouter::getMaxChannels() {
    return _maxChannels;
}

uint8_t AntPlusRouter::addProfileToNextChannel(BaseProfile* profile) {
    for (uint8_t i = 0; i < _maxChannels; i++) {
        if (!_profiles[i]) {
            setProfile(i, profile);
            return i;
        }
    }
    return ANTPLUS_NO_MORE_CHANNELS;
}

void AntPlusRouter::loop() {
    _ant->loop();
}

void AntPlusRouter::stopAllProfiles() {
    for (uint8_t i = 0; i < ANTPLUS_MAX_CHANNELS_POSSIBLE; i++) {
        if (_profiles[i]) {
            _profiles[i]->stop();
        }
    }
}

void AntPlusRouter::flushMessages() {
    // purge buffer of any left over messages
    do {
        _ant->readPacket();
    } while (_ant->getResponse().isAvailable());
}

void AntPlusRouter::reset() {
    resetRadio(ANTPLUS_RESET_WAIT_FOR_STARTUP);
    _ant = NULL;
    _networkKey = NULL;
    _maxChannels = 0;
    for (uint8_t i = 0; i < ANTPLUS_MAX_CHANNELS_POSSIBLE; i++) {
        if (_profiles[i]) {
            // profile stopped in resetRadio
            _profiles[i]->setChannelNumber(0);
            _profiles[i]->setRouter(NULL);
            _profiles[i] = NULL;
        }
    }
}

uint8_t AntPlusRouter::resetRadio(uint8_t waitForStartup) {
    ResetSystem rs;
    stopAllProfiles();
    flushMessages();
    send(rs);
    _radioStarted = ANTPLUS_DRIVER_STATE_UNKNOWN;
    if (waitForStartup == ANTPLUS_RESET_WAIT_FOR_STARTUP) {
        StartUpMessage sm;
        if (_ant->waitFor(sm, ANTPLUS_DRIVER_RESET_TIMEOUT)) {
            onStartUpMessage(sm);
        } else {
            return ANTPLUS_RESET_RADIO_FAILED;
        }
    }
    return 0;
}

void AntPlusRouter::startRxSearch(void(*callback)(uint16_t, uint8_t, uint8_t, uint8_t)) {
    UnAssignChannel uc;
    AssignChannel ac;
    ChannelId ci;
    ChannelRfFrequency crf;
    LibConfig lb;
    OpenRxScanMode osm;
    _searchCallback = callback;
    stopAllProfiles();
    uc.setChannel(OPEN_RX_SCAN_MODE_CHANNEL);
    send(uc);
    ac.setChannel(OPEN_RX_SCAN_MODE_CHANNEL);
    ac.setChannelType(CHANNEL_TYPE_UNIDIRECTIONAL_RECEIVE);
    ac.setChannelNetwork(ANTPLUS_NETWORKKEY_INDEX);
    send(ac);
    ci.setChannel(OPEN_RX_SCAN_MODE_CHANNEL);
    ci.setDeviceNumber(0);
    ci.setDeviceType(0);
    ci.setPairingBit(false);
    ci.setTransmissionType(0);
    send(ci);
    crf.setChannel(OPEN_RX_SCAN_MODE_CHANNEL);
    crf.setRfFrequency(ANTPLUS_CHANNEL_FREQUENCY);
    send(crf);
    lb.setConfig(LIB_CONFIG_RSSI | LIB_CONFIG_CHANNEL_ID);
    send(lb);
    send(osm);
}

void AntPlusRouter::stopRxSearch() {
    LibConfig lb;
    CloseChannel cc;
    UnAssignChannel uc;
    cc.setChannel(OPEN_RX_SCAN_MODE_CHANNEL);
    send(cc);
    lb.setConfig(0);
    send(lb);
    flushMessages();
    uc.setChannel(OPEN_RX_SCAN_MODE_CHANNEL);
    send(uc);
    // No need to reapply config as it will be sent on next begin call
    _searchCallback = NULL;
}

void AntPlusRouter::doSearchCallback(AntRxDataResponse& msg) {
    if ((msg.getFlagByte() & LIB_CONFIG_RSSI) &&
        (msg.getFlagByte() & LIB_CONFIG_CHANNEL_ID)) {
        _searchCallback(
                msg.getDeviceNumber(),
                msg.getDeviceType(),
                msg.getTransmissionType(),
                msg.getRSSIValue());
    }
}

void AntPlusRouter::onPacketError(uint8_t error) {
    // TODO
}

void AntPlusRouter::onAcknowledgedData(AcknowledgedData& msg) {
    uint8_t channel = msg.getChannelNumber();

    if (_searchCallback) {
        doSearchCallback(msg);
        return;
    }

    if (_profiles[channel]) {
        _profiles[channel]->onAcknowledgedData(msg);
    }
}

void AntPlusRouter::onAdvancedBurstData(AdvancedBurstData& msg) {
    uint8_t channel = msg.getChannelNumber();

    if (_searchCallback) {
        doSearchCallback(msg);
        return;
    }

    if (_profiles[channel]) {
        _profiles[channel]->onAdvancedBurstData(msg);
    }
}

void AntPlusRouter::onBroadcastData(BroadcastData& msg) {
    uint8_t channel = msg.getChannelNumber();

    if (_searchCallback) {
        doSearchCallback(msg);
        return;
    }

    if (_profiles[channel]) {
        _profiles[channel]->onBroadcastData(msg);
    }
}

void AntPlusRouter::onBurstTransferData(BurstTransferData& msg) {
    uint8_t channel = msg.getChannelNumber();

    if (_searchCallback) {
        doSearchCallback(msg);
        return;
    }

    if (_profiles[channel]) {
        _profiles[channel]->onBurstTransferData(msg);
    }
}

void AntPlusRouter::onAdvancedBurstCapabilitiesConfiguration(AdvancedBurstCapabilitiesConfiguration& msg) {
    // TODO
}

void AntPlusRouter::onAntVersion(AntVersion& msg) {
    // TODO
}

void AntPlusRouter::onCapabilities(Capabilities& msg) {
    _maxChannels = msg.getMaxChannels();
}

void AntPlusRouter::onChannelEventResponse(ChannelEventResponse& msg) {
    if (msg.getResponseMsgId() == ANTPLUS_CHANNELEVENT_MESSAGECODE) {
        uint8_t channel = msg.getChannelNumber();
        if (_profiles[channel]) {
            _profiles[channel]->onChannelEventResponse(msg);
        }
    } else {
        // TODO
    }
}

void AntPlusRouter::onChannelIdResponse(ChannelIdResponse& msg) {
    uint8_t channel = msg.getChannelNumber();
    if (_profiles[channel]) {
        _profiles[channel]->onChannelIdResponse(msg);
    }
}

void AntPlusRouter::onChannelStatus(ChannelStatus& msg) {
    uint8_t channel = msg.getChannelNumber();
    if (_profiles[channel]) {
        _profiles[channel]->onChannelStatus(msg);
    }
}

void AntPlusRouter::onEncryptionModeParameters(EncryptionModeParameters& msg) {
    // TODO
}

void AntPlusRouter::onEventFilter(EventFilter& msg) {
    // TODO
}

void AntPlusRouter::onSelectiveDataUpdateMaskSetting(SelectiveDataUpdateMaskSetting& msg) {
    // TODO
}

void AntPlusRouter::onStartUpMessage(StartUpMessage& msg) {
    _radioStarted = ANTPLUS_DRIVER_STATE_STARTED;
    // TODO handle radio crash
}
