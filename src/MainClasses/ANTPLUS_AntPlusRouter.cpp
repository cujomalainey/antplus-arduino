#include <MainClasses/ANTPLUS_AntPlusRouter.h>

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
    // TODO
    _ant = driver;
    // register callbacks
    resetRadio(ANTPLUS_RESET_WAIT_FOR_STARTUP);
    delay(1000); // TODO replace with lock waiting for startup
    pushNetworkKey();
    // get max channels
    // check if network key is set, if yes, push network key
    // check if any profiles set, push if found to corresponding channels
    return 0;
}

void AntPlusRouter::pushNetworkKey() {
    if (_ant && _networkKey) {
        SetNetworkKey snk = SetNetworkKey(ANTPLUS_NETWORKKEY_INDEX, (uint8_t*)_networkKey);
        _ant->send(snk);
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
}

void AntPlusRouter::send(AntRequest& msg) {
    // TODO
}

/**
 * Returns the maximum number of channels the radio
 * connected can support
 */
uint8_t AntPlusRouter::getMaxChannels() {
    return _maxChannels;
}

void AntPlusRouter::loop() {
    // TODO
}

void AntPlusRouter::reset() {
    _ant = NULL;
}

void AntPlusRouter::resetRadio(uint8_t waitForStartup) {
    ResetSystem rs;
    _ant->send(rs);
    for (uint8_t i = 0; i < ANTPLUS_MAX_CHANNELS_POSSIBLE; i++) {
        _profiles[i] = NULL;
    }
    _radioStarted = ANTPLUS_DRIVER_STATE_UNKNOWN;
}

void AntPlusRouter::onPacketError(uint8_t error, uintptr_t data) {
    // TODO
}

void AntPlusRouter::onAcknowledgedData(AcknowledgedData& msg, uintptr_t data) {
    uint8_t channel = msg.getChannelNumber();
    if (_profiles[channel]) {
        _profiles[channel]->onAcknowledgedData(msg);
    }
}

void AntPlusRouter::onAdvancedBurstData(AdvancedBurstData& msg, uintptr_t data) {
    uint8_t channel = msg.getChannelNumber();
    if (_profiles[channel]) {
        _profiles[channel]->onAdvancedBurstData(msg);
    }
}

void AntPlusRouter::onBroadcastData(BroadcastData& msg, uintptr_t data) {
    uint8_t channel = msg.getChannelNumber();
    if (_profiles[channel]) {
        _profiles[channel]->onBroadcastData(msg);
    }
}

void AntPlusRouter::onBurstTransferData(BurstTransferData& msg, uintptr_t data) {
    uint8_t channel = msg.getChannelNumber();
    if (_profiles[channel]) {
        _profiles[channel]->onBurstTransferData(msg);
    }
}

void AntPlusRouter::onAdvancedBurstCapabilitiesConfiguration(AdvancedBurstCapabilitiesConfiguration& msg, uintptr_t data) {
    // TODO
}

void AntPlusRouter::onAntVersion(AntVersion& msg, uintptr_t data) {
    // TODO
}

void AntPlusRouter::onCapabilities(Capabilities& msg, uintptr_t data) {
    // TODO
}

void AntPlusRouter::onChannelEventResponse(ChannelEventResponse& msg, uintptr_t data) {
    // TODO
}

void AntPlusRouter::onChannelIdResponse(ChannelIdResponse& msg, uintptr_t data) {
    // TODO
}

void AntPlusRouter::onChannelStatus(ChannelStatus& msg, uintptr_t data) {
    // TODO
}

void AntPlusRouter::onEncryptionModeParameters(EncryptionModeParameters& msg, uintptr_t data) {
    // TODO
}

void AntPlusRouter::onEventFilter(EventFilter& msg, uintptr_t data) {
    // TODO
}

void AntPlusRouter::onSelectiveDataUpdateMaskSetting(SelectiveDataUpdateMaskSetting& msg, uintptr_t data) {
    // TODO
}

void AntPlusRouter::onStartUpMessage(StartUpMessage& msg, uintptr_t data) {
    // TODO
}
