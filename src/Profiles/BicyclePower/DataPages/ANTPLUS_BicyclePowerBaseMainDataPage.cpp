#include <Profiles/BicyclePower/DataPages/ANTPLUS_BicyclePowerBaseMainDataPage.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerPrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

BicyclePowerBaseMainDataPage::BicyclePowerBaseMainDataPage(AntRxDataResponse& dp) :
    BaseDataPage<BroadcastData>(dp) {}

// TODO move down since this isn't common to all classes
uint8_t BicyclePowerBaseMainDataPage::getDataPageNumber() {
    return getData(ANTPLUS_BICYCLEPOWER_DATAPAGE_DATAPAGE_BYTE);
}

uint8_t BicyclePowerBaseMainDataPage::getUpdateEventCount() {
    return getData(ANTPLUS_BICYCLEPOWER_DATAPAGE_UPDATEEVENTCOUNT_BYTE);
}

BicyclePowerBaseMainDataPageMsg::BicyclePowerBaseMainDataPageMsg(uint8_t dataPageNumber) :
    BaseDataPageMsg<BroadcastDataMsg>() {
    setDataBuffer(_buffer);
    set8BitValue(dataPageNumber, ANTPLUS_DEFAULT_DATAPAGE_BYTE);
};
