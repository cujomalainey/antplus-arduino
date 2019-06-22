#include <BaseClasses/ANTPLUS_BaseDataPage.h>
#include <BaseClasses/ANTPLUS_BaseMasterProfile.h>
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
    BaseDataPage<AcknowledgedData> bdp(msg);
    if (bdp.getDataPageNumber() == ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_NUMBER) {
        RequestDataPage rdp(msg);
        _requestedPage = rdp.getRequestedPageNumber();
        if (rdp.transmitTillAcknowledged()) {
            _requestAcked = false;
        } else if (rdp.getRequestedPageCount()) {
            _requestedCount = rdp.getRequestedPageCount();
        }
        _isRequestAcknowledged = rdp.getUseAcknowledgedMsgs();
        // TODO handle command type
    }
    // passthrough so any profiles that reset their broadcast pattern on a request can do so
    // also the profile can handle the descriptor bytes if needed
    BaseProfile::onAcknowledgedData(msg);
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
