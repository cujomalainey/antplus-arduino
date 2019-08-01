#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseBatteryStatus.h>
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
