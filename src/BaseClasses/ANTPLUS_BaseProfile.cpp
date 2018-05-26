#include <BaseClasses/ANTPLUS_BaseProfile.h>
#include <ANTPLUS_PrivateDefines.h>

BaseProfile::BaseProfile(uint16_t deviceNumber, uint8_t transmissionType) {
    setDeviceNumber(deviceNumber);
    setTransmissionType(transmissionType);
}

uint8_t BaseProfile::getChannelStatus() {
    return _channelStatus;
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

void BaseProfile::setSearchTimeout(uint8_t counts) {
    _searchTimeout = counts;
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
    AssignChannel ac(_channel, _channelType, ANTPLUS_NETWORKKEY_INDEX);
    ChannelId ci(_channel, _deviceNumber, _deviceType, ANTPLUS_PAIRING_BIT_MASK & _deviceType, _transmissionType);
    ChannelPeriod cp(_channel, _channelPeriod);
    ChannelRfFrequency crf(_channel, ANTPLUS_CHANNEL_FREQUENCY);
    SearchTimeout st(_channel, _searchTimeout);

    _router->send(ac);
    _router->send(ci);
    _router->send(cp);
    _router->send(crf);
    _router->send(st);
}

void BaseProfile::openChannel() {
    OpenChannel oc = OpenChannel(_channel);
    _channelStatus = CHANNEL_STATUS_SEARCHING;
    _router->send(oc);
}

void BaseProfile::closeChannel() {
    CloseChannel cc = CloseChannel(_channel);
    _channelStatus = CHANNEL_STATUS_ASSIGNED;
    _router->send(cc);
}

void BaseProfile::onChannelEventResponse(ChannelEventResponse& msg) {
    uint8_t event = msg.getCode();

    // TODO this looks weird to me
    switch (event) {
    case STATUS_EVENT_CHANNEL_CLOSED:
    case STATUS_EVENT_RX_FAIL_GO_TO_SEARCH:
        _channelStatus = CHANNEL_STATUS_ASSIGNED;
        break;
    }

    _onChannelEvent.call(msg);
}

void BaseProfile::onChannelIdResponse(ChannelIdResponse& msg) {
    setDeviceNumber(msg.getDeviceNumber());
    setTransmissionType(msg.getTransmissionType());
    _onChannelIdResponse.call(msg);
}

void BaseProfile::onAcknowledgedData(AcknowledgedData& msg) {
    checkProfileStatus();
    _onDataPage.call(msg);
}

void BaseProfile::onAdvancedBurstData(AdvancedBurstData& msg) {
    checkProfileStatus();
    _onDataPage.call(msg);
}

void BaseProfile::onBroadcastData(BroadcastData& msg) {
    checkProfileStatus();
    _onDataPage.call(msg);
}

void BaseProfile::onBurstTransferData(BurstTransferData& msg) {
    checkProfileStatus();
    _onDataPage.call(msg);
}

void BaseProfile::onChannelStatus(ChannelStatus& msg) {
    _channelStatus = msg.getChannelState();
}

void BaseProfile::checkProfileStatus() {
    if (!getDeviceNumber() || !getTransmissionType()) {
        RequestMessage rm = RequestMessage(CHANNEL_ID, _channel);
        send(rm);
    }
    if (_channelStatus == CHANNEL_STATUS_SEARCHING) {
        RequestMessage rm = RequestMessage(CHANNEL_STATUS, _channel);
        send(rm);
    }
}

void BaseProfile::send(AntRequest& msg) {
    _router->send(msg);
}

uint8_t BaseProfile::getTransmissionType() {
    return _transmissionType;
}

uint16_t BaseProfile::getDeviceNumber() {
    return _deviceNumber;
}

void BaseProfile::loop() {
    _router->loop();
}

void BaseProfile::begin() {
    pushChannelConfig();
    openChannel();
}

void BaseProfile::stop() {
    closeChannel();
}
