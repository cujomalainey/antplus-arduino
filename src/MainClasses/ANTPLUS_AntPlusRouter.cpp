#include <MainClasses/ANTPLUS_AntPlusRouter.h>

AntPlusRouter::AntPlusRouter() {
    // TODO
}

AntPlusRouter::AntPlusRouter(BaseAntWithCallbacks& driver) {
    // TODO
}

AntPlusRouter::AntPlusRouter(BaseAntWithCallbacks& driver, const uint8_t* key) {
    // TODO
}

void AntPlusRouter::setDriver(BaseAntWithCallbacks& driver) {
    // TODO
}

void AntPlusRouter::setAntPlusNetworkKey(const uint8_t* key) {
    // TODO
}

void AntPlusRouter::setProfile(uint8_t channel, BaseProfile& profile) {
    // TODO
}

void AntPlusRouter::send(AntRequest& msg) {
    // TODO
}

uint8_t AntPlusRouter::getMaxChannels() {
    // TODO
    return 0;
}

void AntPlusRouter::loop() {
    // TODO
}

void AntPlusRouter::reset() {
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
