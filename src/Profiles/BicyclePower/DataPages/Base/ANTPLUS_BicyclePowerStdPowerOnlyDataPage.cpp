#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerStdPowerOnlyDataPage.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerPrivateDefines.h>

BicyclePowerStdPowerOnlyDataPage::BicyclePowerStdPowerOnlyDataPage(AntRxDataResponse& dp) : BaseDataPage<BroadcastData>(dp) {

}

uint8_t BicyclePowerStdPowerOnlyDataPage::getDataPageNumber() {
    return getData(ANTPLUS_BICYCLEPOWER_DATAPAGE_STD_POWERONLY_MAIN_DATAPAGE_BYTE);
}

uint8_t BicyclePowerStdPowerOnlyDataPage::getUpdateEventCount() {
    return getData(ANTPLUS_BICYCLEPOWER_DATAPAGE_STD_POWERONLY_MAIN_UPDATE_EVENT_COUNT_BYTE);
}
uint8_t BicyclePowerStdPowerOnlyDataPage::getPedalPower() {
    return getData(ANTPLUS_BICYCLEPOWER_DATAPAGE_STD_POWERONLY_MAIN_PEDAL_POWER_BYTE);
}
uint8_t BicyclePowerStdPowerOnlyDataPage::getInstantaneousCacence() {
    return getData(ANTPLUS_BICYCLEPOWER_DATAPAGE_STD_POWERONLY_MAIN_INSTANTANEOUS_CADENCE_BYTE);
}

uint16_t BicyclePowerStdPowerOnlyDataPage::getCumulativePowerCount() {
    return (getData(ANTPLUS_BICYCLEPOWER_DATAPAGE_STD_POWERONLY_MAIN_CUMULATIVEPOWERMSB_BYTE) << 8) |
            getData(ANTPLUS_BICYCLEPOWER_DATAPAGE_STD_POWERONLY_MAIN_CUMULATIVEPOWERLSB_BYTE);
}

uint16_t BicyclePowerStdPowerOnlyDataPage::getInstataneousPowerCount() {
    return (getData(ANTPLUS_BICYCLEPOWER_DATAPAGE_STD_POWERONLY_MAIN_INSTANTANEOUSPOWERMSB_BYTE) << 8) |
            getData(ANTPLUS_BICYCLEPOWER_DATAPAGE_STD_POWERONLY_MAIN_INSTANTANEOUSPOWERLSB_BYTE);
}
