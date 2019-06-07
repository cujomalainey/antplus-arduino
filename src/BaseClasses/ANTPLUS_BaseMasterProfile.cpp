#include <BaseClasses/ANTPLUS_BaseMasterProfile.h>

BaseMasterProfile::BaseMasterProfile(uint16_t deviceNumber, uint8_t transmissionType) : BaseProfile(deviceNumber, transmissionType) {
}

void BaseMasterProfile::onChannelEventResponse(ChannelEventResponse& msg) {
    BaseProfile::onChannelEventResponse(msg);
    if (msg.getCode() == STATUS_EVENT_TX) {
        transmitNextDataPage();
    }
    if (msg.getCode() == STATUS_EVENT_TRANSFER_TX_COMPLETED) {
        _requestAcked = true;
    }
}

void BaseMasterProfile::onAcknowledgedData(AcknowledgedData& msg) {
    BaseProfile::onAcknowledgedData(msg);
    // TODO handle requested dataPage
}

bool BaseMasterProfile::isRequestedPagePending() {
    return _requestedCount > 0 || !_requestAcked;
}

uint8_t BaseMasterProfile::getRequestedPage() {
    return _requestedPage;
}

bool BaseMasterProfile::isRequestedPageAcknowledged() {
    return _isRequestAcknowledged;
}
