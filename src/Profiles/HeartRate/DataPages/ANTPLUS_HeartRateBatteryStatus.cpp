#include <Profiles/HeartRate/DataPages/ANTPLUS_HeartRateBatteryStatus.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

template<class T>
HeartRateBaseBatteryStatus<T>::HeartRateBaseBatteryStatus() : CoreDataPage<T>() {
}

template<class T>
uint8_t HeartRateBaseBatteryStatus<T>::getBatteryLevel() {
    return this->get8BitValue(
            ANTPLUS_HEARTRATE_DATAPAGE_BATTERYSTATUS_BATTERYLEVEL_BYTE);
}

template<class T>
uint8_t HeartRateBaseBatteryStatus<T>::getFractionalBatteryVoltage() {
    return this->get8BitValue(
            ANTPLUS_HEARTRATE_DATAPAGE_BATTERYSTATUS_FRACTIONALBATTERYVOLTAGE_BYTE);
}

template<class T>
uint8_t HeartRateBaseBatteryStatus<T>::getCoarseBatteryVoltage() {
    return this->get8BitValue(
            ANTPLUS_HEARTRATE_DATAPAGE_BATTERYSTATUS_COARSEBATTERYVOLTAGE_BYTE,
            ANTPLUS_HEARTRATE_DATAPAGE_BATTERYSTATUS_COARSEBATTERYVOLTAGE_MASK);
}

template<class T>
uint8_t HeartRateBaseBatteryStatus<T>::getBatteryStatus() {
    return this->get8BitValue(
            ANTPLUS_HEARTRATE_DATAPAGE_BATTERYSTATUS_BATTERYSTATUS_BYTE,
            ANTPLUS_HEARTRATE_DATAPAGE_BATTERYSTATUS_BATTERYSTATUS_MASK,
            ANTPLUS_HEARTRATE_DATAPAGE_BATTERYSTATUS_BATTERYSTATUS_SHIFT);
}

template class HeartRateBaseBatteryStatus<BroadcastData>;
template class HeartRateBaseBatteryStatus<BroadcastDataMsg>;

HeartRateBatteryStatus::HeartRateBatteryStatus(AntRxDataResponse& dp) : HeartRateBaseMainDataPage(dp), HeartRateBaseBatteryStatus() {}

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
