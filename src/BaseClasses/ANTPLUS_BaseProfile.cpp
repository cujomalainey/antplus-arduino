#include <BaseClasses/ANTPLUS_BaseProfile.h>
#include <ANTPLUS_PrivateDefines.h>

BaseProfile::BaseProfile(uint8_t deviceNumber) {

}

uint8_t BaseProfile::getChannelStatus() {
    // TODO
    return 0;
}

void BaseProfile::setRouter(AntPlusRouter* router) {
    _router = router;
}

void BaseProfile::setChannelNumber(uint8_t channel) {
    _channel = channel;
}

void BaseProfile::setDeviceNumber(uint16_t deviceNumber) {
    _deviceNumber = deviceNumber;
}

void BaseProfile::setDeviceType(uint8_t deviceType) {
    _deviceType = deviceType;
}

void BaseProfile::setTransmissionType(uint8_t transmissionType) {
    _transmissionType = transmissionType;
}

void BaseProfile::setSearchTimeout(uint8_t seconds) {
    // TODO
}

void BaseProfile::callOnOtherDataPage(AntRxDataResponse& msg) {
    _onOtherDataPage.call(msg);
}

void BaseProfile::setChannelType(uint8_t channelType) {
    _channelType = channelType;
}

void BaseProfile::setChannelPeriod(uint16_t channelPeriod) {
    _channelPeriod = channelPeriod;
}

void BaseProfile::pushChannelConfig() {
    AssignChannel ac = AssignChannel(_channel, _channelType, ANTPLUS_NETWORKKEY_INDEX);
    // TODO deal with magic numbers
    ChannelId ci = ChannelId(_channel, _deviceNumber, _deviceType, 0x80 & _deviceType, _transmissionType);
    ChannelPeriod cp = ChannelPeriod(_channel, _channelPeriod);
    ChannelRfFrequency crf = ChannelRfFrequency(_channel, ANTPLUS_CHANNEL_FREQUENCY);
    // TODO add set timeout
    _router->send(ac);
    _router->send(ci);
    _router->send(cp);
    _router->send(crf);
}

void BaseProfile::openChannel() {
    OpenChannel oc = OpenChannel(_channel);
    _router->send(oc);
}

void BaseProfile::closeChannel() {
    CloseChannel cc = CloseChannel(_channel);
    _router->send(cc);
}
