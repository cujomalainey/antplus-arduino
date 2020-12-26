#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerBaseBatteryStatus.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerPrivateDefines.h>

template<class T>
BicyclePowerBaseBatteryStatus<T>::BicyclePowerBaseBatteryStatus() : CoreDataPage<T>() {
}

template<class T>
uint8_t BicyclePowerBaseBatteryStatus<T>::getFractionalBatteryVoltage() {
    return this->get8BitValue(
            ANTPLUS_BICYCLEPOWER_DATAPAGE_BATTERYSTATUS_FRACTIONALBATTERYVOLTAGE_BYTE);
}

template<class T>
uint8_t BicyclePowerBaseBatteryStatus<T>::getCoarseBatteryVoltage() {
    return this->get8BitValue(
            ANTPLUS_BICYCLEPOWER_DATAPAGE_BATTERYSTATUS_COARSEBATTERYVOLTAGE_BYTE,
            ANTPLUS_BICYCLEPOWER_DATAPAGE_BATTERYSTATUS_COARSEBATTERYVOLTAGE_MASK);
}

template<class T>
uint8_t BicyclePowerBaseBatteryStatus<T>::getBatteryStatus() {
    return this->get8BitValue(
            ANTPLUS_BICYCLEPOWER_DATAPAGE_BATTERYSTATUS_BATTERYSTATUS_BYTE,
            ANTPLUS_BICYCLEPOWER_DATAPAGE_BATTERYSTATUS_BATTERYSTATUS_MASK,
            ANTPLUS_BICYCLEPOWER_DATAPAGE_BATTERYSTATUS_BATTERYSTATUS_SHIFT);
}

template class BicyclePowerBaseBatteryStatus<BroadcastData>;
template class BicyclePowerBaseBatteryStatus<BroadcastDataMsg>;
