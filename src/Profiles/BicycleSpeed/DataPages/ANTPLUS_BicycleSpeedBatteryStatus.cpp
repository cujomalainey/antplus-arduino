#include <Profiles/BicycleSpeed/DataPages/ANTPLUS_BicycleSpeedBatteryStatus.h>
#include <Profiles/BicycleSpeed/ANTPLUS_BicycleSpeedPrivateDefines.h>

template<class T>
BicycleSpeedBaseBatteryStatus<T>::BicycleSpeedBaseBatteryStatus() :
    CoreDataPage<T>() {}

template<class T>
uint8_t BicycleSpeedBaseBatteryStatus<T>::getFractionalBatteryVoltage() {
    return this->get8BitValue(
            ANTPLUS_BICYCLESPEED_DATAPAGE_BATTERYSTATUS_FRACTIONALBATTERYVOLTAGE_BYTE);
}

template<class T>
uint8_t BicycleSpeedBaseBatteryStatus<T>::getCoarseBatteryVoltage() {
    return this->get8BitValue(
            ANTPLUS_BICYCLESPEED_DATAPAGE_BATTERYSTATUS_COARSEBATTERYVOLTAGE_BYTE,
            ANTPLUS_BICYCLESPEED_DATAPAGE_BATTERYSTATUS_COARSEBATTERYVOLTAGE_MASK);
}

template<class T>
uint8_t BicycleSpeedBaseBatteryStatus<T>::getBatteryStatus() {
    return this->get8BitValue(
            ANTPLUS_BICYCLESPEED_DATAPAGE_BATTERYSTATUS_BATTERYSTATUS_BYTE,
            ANTPLUS_BICYCLESPEED_DATAPAGE_BATTERYSTATUS_BATTERYSTATUS_MASK,
            ANTPLUS_BICYCLESPEED_DATAPAGE_BATTERYSTATUS_BATTERYSTATUS_SHIFT);
}

template class BicycleSpeedBaseBatteryStatus<BroadcastData>;
template class BicycleSpeedBaseBatteryStatus<BroadcastDataMsg>;

BicycleSpeedBatteryStatus::BicycleSpeedBatteryStatus(AntRxDataResponse& dp) :
    BicycleSpeedBaseMainDataPage(dp),
    BicycleSpeedBaseBatteryStatus<BroadcastData>() {}
