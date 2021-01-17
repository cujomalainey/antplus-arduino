#include <Profiles/BicyclePower/DataPages/ANTPLUS_BicyclePowerStandardWheelTorque.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerPrivateDefines.h>

#define WHEELTICKS_BYTE                   2
#define INSTANTANEOUSCADENCE_BYTE         3
#define WHEELPERIOD_LSB_BYTE              4
#define WHEELPERIOD_MSB_BYTE              5
#define ACCUMULATEDTORQUE_LSB_BYTE        6
#define ACCUMULATEDTORQUE_MSB_BYTE        7

template<class T>
BicyclePowerBaseStandardWheelTorque<T>::BicyclePowerBaseStandardWheelTorque() :
    CoreDataPage<T>() {}

template<class T>
uint8_t BicyclePowerBaseStandardWheelTorque<T>::getWheelTicks() {
    return this->get8BitValue(WHEELTICKS_BYTE);
}

template<class T>
uint8_t BicyclePowerBaseStandardWheelTorque<T>::getInstantaneousCadence() {
    return this->get8BitValue(INSTANTANEOUSCADENCE_BYTE);
}

template<class T>
uint16_t BicyclePowerBaseStandardWheelTorque<T>::getWheelPeriod() {
    return this->get16BitValue(
            WHEELPERIOD_LSB_BYTE, WHEELPERIOD_MSB_BYTE);
}

template<class T>
uint16_t BicyclePowerBaseStandardWheelTorque<T>::getAccumulatedTorque() {
    return this->get16BitValue(
            ACCUMULATEDTORQUE_LSB_BYTE, ACCUMULATEDTORQUE_MSB_BYTE);
}

template class BicyclePowerBaseStandardWheelTorque<BroadcastData>;
template class BicyclePowerBaseStandardWheelTorque<BroadcastDataMsg>;

BicyclePowerStandardWheelTorque::BicyclePowerStandardWheelTorque(AntRxDataResponse& dp) :
    BicyclePowerBaseMainDataPage(dp),
    BicyclePowerBaseStandardWheelTorque() {}
