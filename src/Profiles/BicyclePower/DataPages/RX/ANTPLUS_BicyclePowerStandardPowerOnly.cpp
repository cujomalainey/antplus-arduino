#include <Profiles/BicyclePower/DataPages/RX/ANTPLUS_BicyclePowerStandardPowerOnly.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerPrivateDefines.h>

BicyclePowerStandardPowerOnly::BicyclePowerStandardPowerOnly(AntRxDataResponse& dp) : BaseDataPage<BroadcastData>(dp) {
}

uint8_t BicyclePowerStandardPowerOnly::getDataPageNumber() {
    return getData(ANTPLUS_BICYCLEPOWER_DATAPAGE_DATAPAGE_BYTE);
}

uint8_t BicyclePowerStandardPowerOnly::getUpdateEventCount() {
    return getData(ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_UPDATEEVENTCOUNT_BYTE);
}
uint8_t BicyclePowerStandardPowerOnly::getPedalPower() {
    return getData(ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_PEDALPOWER_BYTE);
}
uint8_t BicyclePowerStandardPowerOnly::getInstantaneousCacence() {
    return getData(ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_INSTANTANEOUSCADENCE_BYTE);
}

uint16_t BicyclePowerStandardPowerOnly::getCumulativePowerCount() {
    return (getData(ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_ACCUMULATEDPOWERMSB_BYTE) << 8) |
            getData(ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_ACCUMULATEDPOWERLSB_BYTE);
}

uint16_t BicyclePowerStandardPowerOnly::getInstataneousPowerCount() {
    return (getData(ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_INSTANTANEOUSPOWERMSB_BYTE) << 8) |
            getData(ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_INSTANTANEOUSPOWERLSB_BYTE);
}
