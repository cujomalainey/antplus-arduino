#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerBaseWheelTorque.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerPrivateDefines.h>

template<class T>
BicyclePowerBaseWheelTorque<T>::BicyclePowerBaseWheelTorque() : CoreDataPage<T>() {
}

template<class T>
uint8_t BicyclePowerBaseWheelTorque<T>::getWheelTicks() {
    return this->get8BitValue(
    		ANTPLUS_BICYCLEPOWER_DATAPAGE_WHEELTICKS_WHEELTORQUE_BYTE);
}

template<class T>
uint8_t BicyclePowerBaseWheelTorque<T>::getInstantCadence() {
    return this->get8BitValue(
    		ANTPLUS_BICYCLEPOWER_DATAPAGE_CADENCE_WHEELTORQUE_BYTE);
}

template<class T>
uint16_t BicyclePowerBaseWheelTorque<T>::getWheelPeriod() {
    return this->get16BitValue(
    		ANTPLUS_BICYCLEPOWER_DATAPAGE_WHEELPERIODLSB_WHEELTORQUE_BYTE,
			ANTPLUS_BICYCLEPOWER_DATAPAGE_WHEELPERIODMSB_WHEELTORQUE_BYTE);
}

template<class T>
uint16_t BicyclePowerBaseWheelTorque<T>::getAccumulatedTorque() {
    return this->get16BitValue(
    		ANTPLUS_BICYCLEPOWER_DATAPAGE_ACCUMULATEDTORQUELSB_WHEELTORQUE_BYTE,
			ANTPLUS_BICYCLEPOWER_DATAPAGE_ACCUMULATEDTORQUEMSB_WHEELTORQUE_BYTE);
}

template class BicyclePowerBaseWheelTorque<BroadcastData>;
template class BicyclePowerBaseWheelTorque<BroadcastDataMsg>;
