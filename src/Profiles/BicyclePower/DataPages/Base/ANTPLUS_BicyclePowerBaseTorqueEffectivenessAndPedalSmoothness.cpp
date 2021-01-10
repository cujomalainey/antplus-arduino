#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerBaseTorqueEffectivenessAndPedalSmoothness.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerPrivateDefines.h>

template<class T>
BicyclePowerBaseTorqueEffectivenessAndPedalSmoothness<T>::BicyclePowerBaseTorqueEffectivenessAndPedalSmoothness() : CoreDataPage<T>() {
}

template<class T>
uint8_t BicyclePowerBaseTorqueEffectivenessAndPedalSmoothness<T>::getLeftTorqueEffectiveness() {
    return this->get8BitValue(
            ANTPLUS_BICYCLEPOWER_DATAPAGE_LEFTEFFECTIVENESS_PEDALSMOOTHNESS_BYTE);
}

template<class T>
uint8_t BicyclePowerBaseTorqueEffectivenessAndPedalSmoothness<T>::getRightTorqueEffectiveness() {
    return this->get8BitValue(
            ANTPLUS_BICYCLEPOWER_DATAPAGE_RIGHTEFFECTIVENESS_PEDALSMOOTHNESS_BYTE);
}

template<class T>
uint8_t BicyclePowerBaseTorqueEffectivenessAndPedalSmoothness<T>::getLeftPedalSmoothness() {
    return this->get8BitValue(
            ANTPLUS_BICYCLEPOWER_DATAPAGE_LEFTSMOOTHNESS_PEDALSMOOTHNESS_BYTE);
}

template<class T>
uint8_t BicyclePowerBaseTorqueEffectivenessAndPedalSmoothness<T>::getRightPedalSmoothness() {
    return this->get8BitValue(
            ANTPLUS_BICYCLEPOWER_DATAPAGE_RIGHTSMOOTHNESS_PEDALSMOOTHNESS_BYTE);
}

template class BicyclePowerBaseTorqueEffectivenessAndPedalSmoothness<BroadcastData>;
template class BicyclePowerBaseTorqueEffectivenessAndPedalSmoothness<BroadcastDataMsg>;
