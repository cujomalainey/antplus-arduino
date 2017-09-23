#include <BaseClasses/ANTPLUS_BaseProfile.h>

BaseProfile::BaseProfile(uint8_t channelId) {
    // TODO
}

uint8_t BaseProfile::getChannelStatus() {
    // TODO
    return 0;
}

void BaseProfile::setRouter(AntPlusRouter router) {
    // TODO
}

void BaseProfile::setChannelId(uint16_t channelId) {
    // TODO
}

void BaseProfile::setDeviceType(uint8_t deviceType) {
    // TODO
}

void BaseProfile::setTransmissionType(uint8_t transmissionType) {
    // TODO
}

void BaseProfile::pushChannelConfig() {
    AssignChannel ac;
    ChannelId ci;
    ChannelPeriod cp;
    ChannelRfFrequency crf;
    // TODO
}

void BaseProfile::openChannel() {
    OpenChannel oc;
    // TODO
}

void BaseProfile::closeChannel() {
    // TODO
}
