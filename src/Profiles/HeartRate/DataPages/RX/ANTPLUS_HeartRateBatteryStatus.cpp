#include <Profiles/HeartRate/DataPages/RX/ANTPLUS_HeartRateBatteryStatus.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

HeartRateBatteryStatus::HeartRateBatteryStatus(AntRxDataResponse& dp) : HeartRateBaseMainDataPage(dp) {

}

uint8_t HeartRateBatteryStatus::getBatteryLevel() {
    return getData(ANTPLUS_HEARTRATE_DATAPAGE_BATTERYSTATUS_BATTERYLEVEL_BYTE);
}

uint8_t HeartRateBatteryStatus::getFractionalBatteryVoltage() {
    return getData(ANTPLUS_HEARTRATE_DATAPAGE_BATTERYSTATUS_FRACTIONALBATTERYVOLTAGE_BYTE);
}

uint8_t HeartRateBatteryStatus::getCoarseBatteryVolage() {
    return getData(ANTPLUS_HEARTRATE_DATAPAGE_BATTERYSTATUS_COARSEBATTERYVOLTAGE_BYTE) & ANTPLUS_HEARTRATE_DATAPAGE_BATTERYSTATUS_COARSEBATTERYVOLTAGE_MASK;
}

uint8_t HeartRateBatteryStatus::getBatteryStatus() {
    return (getData(ANTPLUS_HEARTRATE_DATAPAGE_BATTERYSTATUS_BATTERYSTATUS_BYTE) & ANTPLUS_HEARTRATE_DATAPAGE_BATTERYSTATUS_BATTERYSTATUS_MASK) << ANTPLUS_HEARTRATE_DATAPAGE_BATTERYSTATUS_BATTERYSTATUS_SHIFT;
}
