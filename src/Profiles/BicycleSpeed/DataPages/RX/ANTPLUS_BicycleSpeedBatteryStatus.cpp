#include <Profiles/BicycleSpeed/DataPages/RX/ANTPLUS_BicycleSpeedBatteryStatus.h>
#include <Profiles/BicycleSpeed/ANTPLUS_BicycleSpeedPrivateDefines.h>

BicycleSpeedBatteryStatus::BicycleSpeedBatteryStatus(AntRxDataResponse& dp) : BicycleSpeedBaseMainDataPage(dp) {

}

uint8_t BicycleSpeedBatteryStatus::getFractionalBatteryVoltage() {
    return getData(ANTPLUS_BICYCLESPEED_DATAPAGE_BATTERYSTATUS_FRACTIONALBATTERYVOLTAGE_BYTE);
}

uint8_t BicycleSpeedBatteryStatus::getCoarseBatteryVoltage() {
    return getData(ANTPLUS_BICYCLESPEED_DATAPAGE_BATTERYSTATUS_COARSEBATTERYVOLTAGE_BYTE) & ANTPLUS_BICYCLESPEED_DATAPAGE_BATTERYSTATUS_COARSEBATTERYVOLTAGE_MASK;
}

uint8_t BicycleSpeedBatteryStatus::getBatteryStatus() {
    return (getData(ANTPLUS_BICYCLESPEED_DATAPAGE_BATTERYSTATUS_BATTERYSTATUS_BYTE) & ANTPLUS_BICYCLESPEED_DATAPAGE_BATTERYSTATUS_BATTERYSTATUS_MASK) >> ANTPLUS_BICYCLESPEED_DATAPAGE_BATTERYSTATUS_BATTERYSTATUS_SHIFT;
}
