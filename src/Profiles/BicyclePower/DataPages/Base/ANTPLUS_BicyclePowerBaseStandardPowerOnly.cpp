#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerBaseStandardPowerOnly.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerPrivateDefines.h>

template<class T>
BicyclePowerBaseStandardPowerOnly<T>::BicyclePowerBaseStandardPowerOnly() : CoreDataPage<T>() {
}

template<class T>
uint8_t BicyclePowerBaseStandardPowerOnly<T>::getPedalPower() {
    return this->get8BitValue(
            ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_PEDALPOWER_BYTE);
}

template<class T>
uint8_t BicyclePowerBaseStandardPowerOnly<T>::getInstantaneousCadence() {
    return this->get8BitValue(
            ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_INSTANTANEOUSCADENCE_BYTE);
}

template<class T>
uint16_t BicyclePowerBaseStandardPowerOnly<T>::getAccumulatedPower() {
    return this->get16BitValue(
            ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_ACCUMULATEDPOWER_LSB_BYTE,
            ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_ACCUMULATEDPOWER_MSB_BYTE);
}

template<class T>
uint16_t BicyclePowerBaseStandardPowerOnly<T>::getInstantaneousPower() {
    return this->get16BitValue(
            ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_INSTANTANEOUSPOWER_LSB_BYTE,
            ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_INSTANTANEOUSPOWER_MSB_BYTE);
}

template class BicyclePowerBaseStandardPowerOnly<BroadcastData>;
template class BicyclePowerBaseStandardPowerOnly<BroadcastDataMsg>;
