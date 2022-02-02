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

BicyclePowerTorqueEffectivenessAndPedalSmoothnessMsg::BicyclePowerTorqueEffectivenessAndPedalSmoothnessMsg() :
    BicyclePowerBaseMainDataPageMsg(ANTPLUS_BICYCLEPOWER_DATAPAGES_TORQUEEFFECTIVENESSANDPEDALSMOOTHNESS_NUMBER),
    BicyclePowerBaseTorqueEffectivenessAndPedalSmoothness() {
    setLeftTorqueEffectiveness(ANTPLUS_BICYCLEPOWER_DATAPAGES_TORQUEEFFECTIVENESSANDPEDALSMOOTHNESS_TORQUEEFFECTIVENESS_INVALID);
    setRightTorqueEffectiveness(ANTPLUS_BICYCLEPOWER_DATAPAGES_TORQUEEFFECTIVENESSANDPEDALSMOOTHNESS_TORQUEEFFECTIVENESS_INVALID);
    setLeftPedalSmoothness(ANTPLUS_BICYCLEPOWER_DATAPAGES_TORQUEEFFECTIVENESSANDPEDALSMOOTHNESS_PEDALSMOOTHNESS_INVALID);
    setRightPedalSmoothness(ANTPLUS_BICYCLEPOWER_DATAPAGES_TORQUEEFFECTIVENESSANDPEDALSMOOTHNESS_PEDALSMOOTHNESS_INVALID);
}

void BicyclePowerTorqueEffectivenessAndPedalSmoothnessMsg::setLeftTorqueEffectiveness(uint8_t effectiveness) {
    set8BitValue(effectiveness, LEFTEFFECTIVENESS_BYTE);
}

void BicyclePowerTorqueEffectivenessAndPedalSmoothnessMsg::setRightTorqueEffectiveness(uint8_t effectiveness) {
    set8BitValue(effectiveness, RIGHTEFFECTIVENESS_BYTE);
}

void BicyclePowerTorqueEffectivenessAndPedalSmoothnessMsg::setLeftPedalSmoothness(uint8_t smoothness) {
    set8BitValue(smoothness, LEFTSMOOTHNESS_BYTE);
}

void BicyclePowerTorqueEffectivenessAndPedalSmoothnessMsg::setRightPedalSmoothness(uint8_t smoothness) {
    set8BitValue(smoothness, RIGHTSMOOTHNESS_BYTE);
}
