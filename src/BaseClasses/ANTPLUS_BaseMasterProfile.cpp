#include <BaseClasses/ANTPLUS_BaseDataPage.h>
#include <BaseClasses/ANTPLUS_BaseMasterProfile.h>
#include <CommonDataPages/ANTPLUS_CommonDataPageDefines.h>
#include <CommonDataPages/ANTPLUS_RequestDataPage.h>

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
    BaseDataPage<AcknowledgedData> dp(msg);

    if (dp.getDataPageNumber() == ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_NUMBER) {
        handleRequestDataPage(msg);
    }
}

void BaseMasterProfile::handleRequestDataPage(AcknowledgedData& msg) {
    RequestDataPage dp(msg);
    if (!isDataPageValid(dp.getRequestedPageNumber())) {
        // Datapage requested isn't supported, don't do anything
        return;
    }
    _requestedCount = dp.getRequestedTransmissionResponseCount();
    _requestedPage = dp.getRequestedPageNumber();
    _isRequestAcknowledged = dp.getRequestedTransmissionUseAcknowledged();
    _requestAcked = !dp.transmitTillAcknowledged();
    // TODO handle command type
}

bool BaseMasterProfile::isRequestedPagePending() {
    return _requestedCount > 0 || !_requestAcked;
}

uint8_t BaseMasterProfile::getRequestedPage() {
    if (_requestedCount > 0) {
        _requestedCount--;
    }
    return _requestedPage;
}

bool BaseMasterProfile::isRequestedPageAcknowledged() {
    return _isRequestAcknowledged && _ackMessagesAllowed;
}

void BaseMasterProfile::begin() {
    BaseProfile::begin();
    // send first datapage manually so we don't transmit 0s
    transmitNextDataPage();
}

void BaseMasterProfile::invalidateDataPageRequest() {
    _requestedCount = 0;
    _requestAcked = true;
}

void BaseMasterProfile::setAckMessageUsage(bool on) {
    _ackMessagesAllowed = on;
}

void BaseMasterProfile::transmitMsg(BaseDataPageMsg<BroadcastDataMsg> &msg) {
    if (isRequestedPageAcknowledged() && isRequestedPagePending()) {
        AcknowledgedDataMsg ack;
        ack.setDataBuffer(msg.getDataBuffer());
        send(ack);
    } else {
        send(msg);
    }
}

void BaseMasterProfile::transmitMsg(BaseDataPageMsg<AcknowledgedDataMsg> &msg) {
    send(msg);
}
