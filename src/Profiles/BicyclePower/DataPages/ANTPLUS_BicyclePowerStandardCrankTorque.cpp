#include <Profiles/BicyclePower/DataPages/ANTPLUS_BicyclePowerStandardCrankTorque.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerPrivateDefines.h>

template<class T>
BicyclePowerBaseStandardCrankTorque<T>::BicyclePowerBaseStandardCrankTorque() :
    CoreDataPage<T>() {}

template<class T>
uint8_t BicyclePowerBaseStandardCrankTorque<T>::getCrankTicks() {
    return this->get8BitValue(
            ANTPLUS_BICYCLEPOWER_DATAPAGE_CRANKTICKS_CRANKTORQUE_BYTE);
}

template<class T>
uint8_t BicyclePowerBaseStandardCrankTorque<T>::getInstantCadence() {
    return this->get8BitValue(
            ANTPLUS_BICYCLEPOWER_DATAPAGE_CADENCE_CRANKTORQUE_BYTE);
}

template<class T>
uint16_t BicyclePowerBaseStandardCrankTorque<T>::getCrankPeriod() {
    return this->get16BitValue(
            ANTPLUS_BICYCLEPOWER_DATAPAGE_CRANKPERIODLSB_CRANKTORQUE_BYTE,
            ANTPLUS_BICYCLEPOWER_DATAPAGE_CRANKPERIODMSB_CRANKTORQUE_BYTE);
}

template<class T>
uint16_t BicyclePowerBaseStandardCrankTorque<T>::getAccumulatedTorque() {
    return this->get16BitValue(
            ANTPLUS_BICYCLEPOWER_DATAPAGE_ACCUMULATEDTORQUELSB_CRANKTORQUE_BYTE,
            ANTPLUS_BICYCLEPOWER_DATAPAGE_ACCUMULATEDTORQUEMSB_CRANKTORQUE_BYTE);
}

template class BicyclePowerBaseStandardCrankTorque<BroadcastData>;
template class BicyclePowerBaseStandardCrankTorque<BroadcastDataMsg>;

BicyclePowerStandardCrankTorque::BicyclePowerStandardCrankTorque(AntRxDataResponse& dp) :
    BicyclePowerBaseMainDataPage(dp),
    BicyclePowerBaseStandardCrankTorque() {}
