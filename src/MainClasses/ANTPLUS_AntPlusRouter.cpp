#include <MainClasses/ANTPLUS_AntPlusRouter.h>
#include <MainClasses/ANTPLUS_CallbackWorkAround.h>

AntPlusRouter::AntPlusRouter() {
    // TODO
}

AntPlusRouter::AntPlusRouter(BaseAntWithCallbacks* driver) {
    setDriver(driver);
}

AntPlusRouter::AntPlusRouter(BaseAntWithCallbacks* driver, const uint8_t* key) {
    setDriver(driver);
    setAntPlusNetworkKey(key);
}

uint8_t AntPlusRouter::setDriver(BaseAntWithCallbacks* driver) {
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
    resetRadio(ANTPLUS_RESET_WAIT_FOR_STARTUP);
    delay(1000); // TODO replace with lock waiting for startup
    pushNetworkKey();
    // get max channels
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
    channel = min(channel, _maxChannels - 1);
    // TODO close channel to make sure it hasn't been randomly replaced
    _profiles[channel] = profile;
    profile->setRouter(this);
}

void AntPlusRouter::send(AntRequest& msg) {
    _ant->send(msg);
}

uint8_t AntPlusRouter::getMaxChannels() {
    return _maxChannels;
}

void AntPlusRouter::loop() {
    _ant->loop();
}

void AntPlusRouter::reset() {
    _ant = NULL;
    _networkKey = NULL;
    // TODO
    // disconnect profiles
    // Reset max channels
    // reset system state
}

void AntPlusRouter::resetRadio(uint8_t waitForStartup) {
    ResetSystem rs;
    send(rs);
    for (uint8_t i = 0; i < ANTPLUS_MAX_CHANNELS_POSSIBLE; i++) {
        _profiles[i] = NULL;
    }
    _radioStarted = ANTPLUS_DRIVER_STATE_UNKNOWN;
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
    // TODO
}

void AntPlusRouter::onChannelIdResponse(ChannelIdResponse& msg) {
    // TODO
}

void AntPlusRouter::onChannelStatus(ChannelStatus& msg) {
    // TODO
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
    // TODO
}
