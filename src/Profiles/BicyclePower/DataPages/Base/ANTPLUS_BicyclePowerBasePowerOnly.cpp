#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerBasePowerOnly.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerPrivateDefines.h>

template<class T>
BicyclePowerBasePowerOnly<T>::BicyclePowerBasePowerOnly() : CoreDataPage<T>() {
}

template<class T>
uint8_t BicyclePowerBasePowerOnly<T>::getPedalBalance() {
    return this->get8BitValue(
    		ANTPLUS_BICYCLEPOWER_DATAPAGE_PEDALPOWER_POWERONLY_BYTE);
}

template<class T>
uint8_t BicyclePowerBasePowerOnly<T>::getInstantCadence() {
    return this->get8BitValue(
    		ANTPLUS_BICYCLEPOWER_DATAPAGE_CADENCE_POWERONLY_BYTE);
}

template<class T>
uint16_t BicyclePowerBasePowerOnly<T>::getAccumulatedPower() {
    return this->get16BitValue(
    		ANTPLUS_BICYCLEPOWER_DATAPAGE_ACCUMULATEDPOWERLSB_POWERONLY_BYTE,
			ANTPLUS_BICYCLEPOWER_DATAPAGE_ACCUMULATEDPOWERMSB_POWERONLY_BYTE);
}

template<class T>
uint16_t BicyclePowerBasePowerOnly<T>::getInstantPower() {
    return this->get16BitValue(
    		ANTPLUS_BICYCLEPOWER_DATAPAGE_INSTANTPOWERLSB_POWERONLY_BYTE,
			ANTPLUS_BICYCLEPOWER_DATAPAGE_INSTANTPOWERMSB_POWERONLY_BYTE);
}

template class BicyclePowerBasePowerOnly<BroadcastData>;
template class BicyclePowerBasePowerOnly<BroadcastDataMsg>;
