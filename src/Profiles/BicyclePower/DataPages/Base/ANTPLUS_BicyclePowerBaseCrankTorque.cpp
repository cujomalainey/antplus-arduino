#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerBaseCrankTorque.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerPrivateDefines.h>

template<class T>
BicyclePowerBaseCrankTorque<T>::BicyclePowerBaseCrankTorque() : CoreDataPage<T>() {
}

template<class T>
uint8_t BicyclePowerBaseCrankTorque<T>::getCrankTicks() {
    return this->get8BitValue(
    		ANTPLUS_BICYCLEPOWER_DATAPAGE_CRANKTICKS_CRANKTORQUE_BYTE);
}

template<class T>
uint8_t BicyclePowerBaseCrankTorque<T>::getInstantCadence() {
    return this->get8BitValue(
    		ANTPLUS_BICYCLEPOWER_DATAPAGE_CADENCE_CRANKTORQUE_BYTE);
}

template<class T>
uint16_t BicyclePowerBaseCrankTorque<T>::getCrankPeriod() {
    return this->get16BitValue(
    		ANTPLUS_BICYCLEPOWER_DATAPAGE_CRANKPERIODLSB_CRANKTORQUE_BYTE,
			ANTPLUS_BICYCLEPOWER_DATAPAGE_CRANKPERIODMSB_CRANKTORQUE_BYTE);
}

template<class T>
uint16_t BicyclePowerBaseCrankTorque<T>::getAccumulatedTorque() {
    return this->get16BitValue(
    		ANTPLUS_BICYCLEPOWER_DATAPAGE_ACCUMULATEDTORQUELSB_CRANKTORQUE_BYTE,
			ANTPLUS_BICYCLEPOWER_DATAPAGE_ACCUMULATEDTORQUEMSB_CRANKTORQUE_BYTE);
}

template class BicyclePowerBaseCrankTorque<BroadcastData>;
template class BicyclePowerBaseCrankTorque<BroadcastDataMsg>;
