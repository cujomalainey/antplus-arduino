#include <Profiles/BicycleSpeed/DataPages/ANTPLUS_BicycleSpeedBatteryStatus.h>
#include <Profiles/BicycleSpeed/ANTPLUS_BicycleSpeedPrivateDefines.h>

#define FRACTIONALBATTERYVOLTAGE_BYTE 2
#define COARSEBATTERYVOLTAGE_BYTE 3
#define BATTERYSTATUS_BYTE 3
#define COARSEBATTERYVOLTAGE_MASK 0x0F
#define BATTERYSTATUS_MASK 0x70
#define BATTERYSTATUS_SHIFT 4

template<class T>
BicycleSpeedBaseBatteryStatus<T>::BicycleSpeedBaseBatteryStatus() :
    CoreDataPage<T>() {}

template<class T>
uint8_t BicycleSpeedBaseBatteryStatus<T>::getFractionalBatteryVoltage() {
    return this->get8BitValue(FRACTIONALBATTERYVOLTAGE_BYTE);
}

template<class T>
uint8_t BicycleSpeedBaseBatteryStatus<T>::getCoarseBatteryVoltage() {
    return this->get8BitValue(COARSEBATTERYVOLTAGE_BYTE,
            COARSEBATTERYVOLTAGE_MASK);
}

template<class T>
uint8_t BicycleSpeedBaseBatteryStatus<T>::getBatteryStatus() {
    return this->get8BitValue(BATTERYSTATUS_BYTE, BATTERYSTATUS_MASK,
            BATTERYSTATUS_SHIFT);
}

template class BicycleSpeedBaseBatteryStatus<BroadcastData>;
template class BicycleSpeedBaseBatteryStatus<BroadcastDataMsg>;

BicycleSpeedBatteryStatus::BicycleSpeedBatteryStatus(AntRxDataResponse& dp) :
    BicycleSpeedBaseMainDataPage(dp),
    BicycleSpeedBaseBatteryStatus<BroadcastData>() {}
