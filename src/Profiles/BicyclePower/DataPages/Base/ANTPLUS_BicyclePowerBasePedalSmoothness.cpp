#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerBasePedalSmoothness.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerPrivateDefines.h>

template<class T>
BicyclePowerBasePedalSmoothness<T>::BicyclePowerBasePedalSmoothness() : CoreDataPage<T>() {
}

template<class T>
uint8_t BicyclePowerBasePedalSmoothness<T>::getLeftTorqueEffectiveness() {
    return this->get8BitValue(
    		ANTPLUS_BICYCLEPOWER_DATAPAGE_LEFTEFFECTIVENESS_PEDALSMOOTHNESS_BYTE);
}

template<class T>
uint8_t BicyclePowerBasePedalSmoothness<T>::getRightTorqueEffectiveness() {
    return this->get8BitValue(
    		ANTPLUS_BICYCLEPOWER_DATAPAGE_RIGHTEFFECTIVENESS_PEDALSMOOTHNESS_BYTE);
}

template<class T>
uint8_t BicyclePowerBasePedalSmoothness<T>::getLeftPedalSmoothness() {
    return this->get8BitValue(
    		ANTPLUS_BICYCLEPOWER_DATAPAGE_LEFTSMOOTHNESS_PEDALSMOOTHNESS_BYTE);
}

template<class T>
uint8_t BicyclePowerBasePedalSmoothness<T>::getRightPedalSmoothness() {
    return this->get8BitValue(
    		ANTPLUS_BICYCLEPOWER_DATAPAGE_RIGHTSMOOTHNESS_PEDALSMOOTHNESS_BYTE);
}

template class BicyclePowerBasePedalSmoothness<BroadcastData>;
template class BicyclePowerBasePedalSmoothness<BroadcastDataMsg>;
