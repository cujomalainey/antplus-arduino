#include <Profiles/BicyclePower/DataPages/ANTPLUS_BicyclePowerStandardWheelTorque.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerPrivateDefines.h>

template<class T>
BicyclePowerBaseStandardWheelTorque<T>::BicyclePowerBaseStandardWheelTorque() :
    CoreDataPage<T>() {}

template<class T>
uint8_t BicyclePowerBaseStandardWheelTorque<T>::getWheelTicks() {
    return this->get8BitValue(
            ANTPLUS_BICYCLEPOWER_DATAPAGE_WHEELTICKS_WHEELTORQUE_BYTE);
}

template<class T>
uint8_t BicyclePowerBaseStandardWheelTorque<T>::getInstantCadence() {
    return this->get8BitValue(
            ANTPLUS_BICYCLEPOWER_DATAPAGE_CADENCE_WHEELTORQUE_BYTE);
}

template<class T>
uint16_t BicyclePowerBaseStandardWheelTorque<T>::getWheelPeriod() {
    return this->get16BitValue(
            ANTPLUS_BICYCLEPOWER_DATAPAGE_WHEELPERIODLSB_WHEELTORQUE_BYTE,
            ANTPLUS_BICYCLEPOWER_DATAPAGE_WHEELPERIODMSB_WHEELTORQUE_BYTE);
}

template<class T>
uint16_t BicyclePowerBaseStandardWheelTorque<T>::getAccumulatedTorque() {
    return this->get16BitValue(
            ANTPLUS_BICYCLEPOWER_DATAPAGE_ACCUMULATEDTORQUELSB_WHEELTORQUE_BYTE,
            ANTPLUS_BICYCLEPOWER_DATAPAGE_ACCUMULATEDTORQUEMSB_WHEELTORQUE_BYTE);
}

template class BicyclePowerBaseStandardWheelTorque<BroadcastData>;
template class BicyclePowerBaseStandardWheelTorque<BroadcastDataMsg>;

BicyclePowerStandardWheelTorque::BicyclePowerStandardWheelTorque(AntRxDataResponse& dp) :
    BicyclePowerBaseMainDataPage(dp),
    BicyclePowerBaseStandardWheelTorque() {}
