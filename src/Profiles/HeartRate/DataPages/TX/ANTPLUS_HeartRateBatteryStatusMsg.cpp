#include <Profiles/HeartRate/DataPages/TX/ANTPLUS_HeartRateBatteryStatusMsg.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

HeartRateBatteryStatusMsg::HeartRateBatteryStatusMsg() : HeartRateBaseMainDataPageMsg(ANTPLUS_HEARTRATE_DATAPAGE_BATTERYSTATUS_NUMBER), HeartRateBaseBatteryStatus<BroadcastDataMsg>() {
}

void HeartRateBatteryStatusMsg::setBatteryLevel(uint8_t level) {
    set8BitValue(level,
            ANTPLUS_HEARTRATE_DATAPAGE_BATTERYSTATUS_BATTERYLEVEL_BYTE);
}

void HeartRateBatteryStatusMsg::setFractionalBatteryVoltage(uint8_t voltage) {
    set8BitValue(voltage,
            ANTPLUS_HEARTRATE_DATAPAGE_BATTERYSTATUS_FRACTIONALBATTERYVOLTAGE_BYTE);
}

void HeartRateBatteryStatusMsg::setCoarseBatteryVolage(uint8_t voltage) {
    set8BitValue(voltage,
            ANTPLUS_HEARTRATE_DATAPAGE_BATTERYSTATUS_COARSEBATTERYVOLTAGE_BYTE,
            ANTPLUS_HEARTRATE_DATAPAGE_BATTERYSTATUS_COARSEBATTERYVOLTAGE_MASK);
}

void HeartRateBatteryStatusMsg::setBatteryStatus(uint8_t status) {
    set8BitValue(status,
            ANTPLUS_HEARTRATE_DATAPAGE_BATTERYSTATUS_BATTERYSTATUS_BYTE,
            ANTPLUS_HEARTRATE_DATAPAGE_BATTERYSTATUS_BATTERYSTATUS_MASK,
            ANTPLUS_HEARTRATE_DATAPAGE_BATTERYSTATUS_BATTERYSTATUS_SHIFT);
}
