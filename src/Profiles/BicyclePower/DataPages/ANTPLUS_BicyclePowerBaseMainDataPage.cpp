#include <Profiles/BicyclePower/DataPages/ANTPLUS_BicyclePowerBaseMainDataPage.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerPrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

// TODO make second base class for callibration messages
#define UPDATEEVENTCOUNT_BYTE 1

BicyclePowerBaseMainDataPage::BicyclePowerBaseMainDataPage(AntRxDataResponse& dp) :
    BaseDataPage<BroadcastData>(dp) {}

uint8_t BicyclePowerBaseMainDataPage::getDataPageNumber() {
    return this->get8BitValue(ANTPLUS_DEFAULT_DATAPAGE_BYTE);
}

uint8_t BicyclePowerBaseMainDataPage::getUpdateEventCount() {
    return this->get8BitValue(UPDATEEVENTCOUNT_BYTE);
}

BicyclePowerBaseMainDataPageMsg::BicyclePowerBaseMainDataPageMsg(uint8_t dataPageNumber) :
    BaseDataPageMsg<BroadcastDataMsg>() {
    setDataBuffer(_buffer);
    set8BitValue(dataPageNumber, ANTPLUS_DEFAULT_DATAPAGE_BYTE);
};

void BicyclePowerBaseMainDataPageMsg::setUpdateEventCount(uint8_t eventCount) {
    set8BitValue(eventCount, UPDATEEVENTCOUNT_BYTE);
}
