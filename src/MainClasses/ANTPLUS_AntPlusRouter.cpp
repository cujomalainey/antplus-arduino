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
    RequestMessage rm = RequestMessage();
    Capabilities cap = Capabilities();
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
    // channel = min(channel, _maxChannels - 1); TODO, wait till we set this
    // TODO close channel to make sure it hasn't been randomly replaced
    _profiles[channel] = profile;
    profile->setRouter(this);
}

void AntPlusRouter::removeProfile(BaseProfile *profile) {
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

void AntPlusRouter::reset() {
    _ant = NULL;
    _networkKey = NULL;
    _maxChannels = 0;
    resetRadio(ANTPLUS_RESET_WAIT_FOR_STARTUP);
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
    for (uint8_t i = 0; i < ANTPLUS_MAX_CHANNELS_POSSIBLE; i++) {
        if (_profiles[i]) {
            _profiles[i]->stop();
        }
    }
    send(rs);
    _radioStarted = ANTPLUS_DRIVER_STATE_UNKNOWN;
    if (waitForStartup == ANTPLUS_RESET_WAIT_FOR_STARTUP) {
        StartUpMessage sm = StartUpMessage();
        if (_ant->waitFor(sm, ANTPLUS_DRIVER_RESET_TIMEOUT)) {
            onStartUpMessage(sm);
        } else {
            return ANTPLUS_RESET_RADIO_FAILED;
        }
    }
    return 0;
}

void AntPlusRouter::onPacketError(uint8_t error) {
    // TODO
}

void AntPlusRouter::onAcknowledgedData(AcknowledgedData& msg) {
    uint8_t channel = msg.getChannelNumber();
    if (_profiles[channel]) {
        _profiles[channel]->onAcknowledgedData(msg);
    }
}

void AntPlusRouter::onAdvancedBurstData(AdvancedBurstData& msg) {
    uint8_t channel = msg.getChannelNumber();
    if (_profiles[channel]) {
        _profiles[channel]->onAdvancedBurstData(msg);
    }
}

void AntPlusRouter::onBroadcastData(BroadcastData& msg) {
    uint8_t channel = msg.getChannelNumber();
    if (_profiles[channel]) {
        _profiles[channel]->onBroadcastData(msg);
    }
}

void AntPlusRouter::onBurstTransferData(BurstTransferData& msg) {
    uint8_t channel = msg.getChannelNumber();
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
