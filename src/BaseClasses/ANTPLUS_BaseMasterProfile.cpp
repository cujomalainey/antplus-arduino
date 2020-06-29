#include <BaseClasses/ANTPLUS_BaseMasterProfile.h>
#include <BaseClasses/ANTPLUS_BaseDataPage.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>
#include <CommonDataPages/RX/ANTPLUS_RequestDataPage.h>

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
    _requestedCount = dp.getRequestedPageCount();
    _requestedPage = dp.getRequestedPageNumber();
    _isRequestAcknowledged = dp.getUseAcknowledgedMsgs();
    _requestAcked = !dp.transmitTillAcknowledged();
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
    return _isRequestAcknowledged;
}

void BaseMasterProfile::begin() {
    BaseProfile::begin();
    // send first datapage manually so we don't transmit 0s
    transmitNextDataPage();
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
