#include <BaseClasses/ANTPLUS_BaseProfile.h>
#include <ANTPLUS_PrivateDefines.h>

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

void BaseProfile::setDeviceNumber(uint16_t deviceNumber) {
    _deviceNumber = deviceNumber;
}

void BaseProfile::setDeviceType(uint8_t deviceType) {
    // TODO
}

void BaseProfile::setTransmissionType(uint8_t transmissionType) {
    // TODO
}

void BaseProfile::setSearchTimeout(uint8_t seconds) {
    // TODO
}

void BaseProfile::setChannelType(uint8_t channelType) {
    // TODO
}

void BaseProfile::setChannelPeriod(uint16_t channelPeriod) {
    // TODO
}

void BaseProfile::pushChannelConfig() {
    AssignChannel ac = AssignChannel(_channel, _channelType, ANTPLUS_NETWORKKEY_INDEX);
    // TODO deal with magic numbers
    ChannelId ci = ChannelId(_channel, _deviceNumber, _deviceType, 0x80 & _deviceType, _transmissionType);
    ChannelPeriod cp = ChannelPeriod(_channel, _channelPeriod);
    ChannelRfFrequency crf = ChannelRfFrequency(_channel, ANTPLUS_CHANNEL_FREQUENCY);
    // TODO add set timeout
}

void BaseProfile::openChannel() {
    OpenChannel oc;
    // TODO
}

void BaseProfile::closeChannel() {
    // TODO
}
