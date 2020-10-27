#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerStdPowerOnlyDataPage.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerPrivateDefines.h>

BicyclePowerStdPowerOnlyDataPage::BicyclePowerStdPowerOnlyDataPage(AntRxDataResponse& dp) : BaseDataPage<BroadcastData>(dp) {

}

uint8_t BicyclePowerStdPowerOnlyDataPage::getDataPageNumber() {
    return getData(ANTPLUS_BICYCLEPOWER_DATAPAGE_DATAPAGE_BYTE);
}

uint8_t BicyclePowerStdPowerOnlyDataPage::getUpdateEventCount() {
    return getData(ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_UPDATEEVENTCOUNT_BYTE);
}
uint8_t BicyclePowerStdPowerOnlyDataPage::getPedalPower() {
    return getData(ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_PEDALPOWER_BYTE);
}
uint8_t BicyclePowerStdPowerOnlyDataPage::getInstantaneousCacence() {
    return getData(ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_INSTANTANEOUSCADENCE_BYTE);
}

uint16_t BicyclePowerStdPowerOnlyDataPage::getCumulativePowerCount() {
    return (getData(ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_ACCUMULATEDPOWERMSB_BYTE) << 8) |
            getData(ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_ACCUMULATEDPOWERLSB_BYTE);
}

uint16_t BicyclePowerStdPowerOnlyDataPage::getInstataneousPowerCount() {
    return (getData(ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_INSTANTANEOUSPOWERMSB_BYTE) << 8) |
            getData(ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_INSTANTANEOUSPOWERLSB_BYTE);
}
