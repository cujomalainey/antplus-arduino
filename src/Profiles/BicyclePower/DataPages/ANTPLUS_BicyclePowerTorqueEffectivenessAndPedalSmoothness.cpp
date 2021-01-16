#include <Profiles/BicyclePower/DataPages/ANTPLUS_BicyclePowerTorqueEffectivenessAndPedalSmoothness.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerPrivateDefines.h>

#define LEFTEFFECTIVENESS_BYTE    2
#define RIGHTEFFECTIVENESS_BYTE   3
#define LEFTSMOOTHNESS_BYTE       4
#define RIGHTSMOOTHNESS_BYTE      5

template<class T>
BicyclePowerBaseTorqueEffectivenessAndPedalSmoothness<T>::BicyclePowerBaseTorqueEffectivenessAndPedalSmoothness() :
    CoreDataPage<T>() {}

template<class T>
uint8_t BicyclePowerBaseTorqueEffectivenessAndPedalSmoothness<T>::getLeftTorqueEffectiveness() {
    return this->get8BitValue(LEFTEFFECTIVENESS_BYTE);
}

template<class T>
uint8_t BicyclePowerBaseTorqueEffectivenessAndPedalSmoothness<T>::getRightTorqueEffectiveness() {
    return this->get8BitValue(RIGHTEFFECTIVENESS_BYTE);
}

template<class T>
uint8_t BicyclePowerBaseTorqueEffectivenessAndPedalSmoothness<T>::getLeftPedalSmoothness() {
    return this->get8BitValue(LEFTSMOOTHNESS_BYTE);
}

template<class T>
uint8_t BicyclePowerBaseTorqueEffectivenessAndPedalSmoothness<T>::getRightPedalSmoothness() {
    return this->get8BitValue(RIGHTSMOOTHNESS_BYTE);
}

template class BicyclePowerBaseTorqueEffectivenessAndPedalSmoothness<BroadcastData>;
template class BicyclePowerBaseTorqueEffectivenessAndPedalSmoothness<BroadcastDataMsg>;

BicyclePowerTorqueEffectivenessAndPedalSmoothness::BicyclePowerTorqueEffectivenessAndPedalSmoothness(AntRxDataResponse& dp) :
    BicyclePowerBaseMainDataPage(dp),
    BicyclePowerBaseTorqueEffectivenessAndPedalSmoothness() {}
