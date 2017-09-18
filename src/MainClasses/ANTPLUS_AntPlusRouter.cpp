#include <MainClasses/ANTPLUS_AntPlusRouter.h>
#include <ANTPLUS_defines.h>

AntPlusRouter::AntPlusRouter() {
    // TODO
}

AntPlusRouter::AntPlusRouter(BaseAntWithCallbacks& driver) {
    setDriver(driver);
}

AntPlusRouter::AntPlusRouter(BaseAntWithCallbacks& driver, const uint8_t* key) {
    setDriver(driver);
    setAntPlusNetworkKey(key);
}

uint8_t AntPlusRouter::setDriver(BaseAntWithCallbacks& driver) {
    // TODO
    // register callbacks
    resetRadio(ANTPLUS_RESET_WAIT_FOR_STARTUP);
    // get max channels
    // check if network key is set, if yes, push network key
    // check if any profiles set, push if found to corresponding channels
    return 0;
}

void AntPlusRouter::setAntPlusNetworkKey(const uint8_t* key) {
    // TODO
    // set pointer
    // push if driver is already set
}

void AntPlusRouter::setProfile(uint8_t channel, BaseProfile& profile) {
    // TODO
    // set pointer
    // push config to radio if driver set
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
    // TODO
}

void AntPlusRouter::resetRadio(uint8_t waitForStartup) {
    // TODO
}

void AntPlusRouter::onPacketError(uint8_t error, uintptr_t data) {
    // TODO
}

void AntPlusRouter::onAcknowledgedData(AcknowledgedData& msg, uintptr_t data) {
    // TODO
}

void AntPlusRouter::onAdvancedBurstData(AdvancedBurstData& msg, uintptr_t data) {
    // TODO
}

void AntPlusRouter::onBroadcastData(BroadcastData& msg, uintptr_t data) {
    // TODO
}

void AntPlusRouter::onBurstTransferData(BurstTransferData& msg, uintptr_t data) {
    // TODO
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
