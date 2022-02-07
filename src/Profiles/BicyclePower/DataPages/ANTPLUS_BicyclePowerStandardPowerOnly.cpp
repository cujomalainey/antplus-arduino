#include <Profiles/BicyclePower/DataPages/ANTPLUS_BicyclePowerStandardPowerOnly.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerPrivateDefines.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerDefines.h>
#include <ANTPLUS_PrivateDefines.h>

#define PEDALPOWER_BYTE 2
#define PEDALPOWER_MASK 0x7F
#define PEDALDIFFERENTIATION_BYTE 2
#define PEDALDIFFERENTIATION_MASK 0x80
#define PEDALDIFFERENTIATION_SHIFT 7
#define INSTANTANEOUSCADENCE_BYTE 3
#define ACCUMULATEDPOWER_LSB_BYTE 4
#define ACCUMULATEDPOWER_MSB_BYTE 5
#define INSTANTANEOUSPOWER_LSB_BYTE 6
#define INSTANTANEOUSPOWER_MSB_BYTE 7

template<class T>
BicyclePowerBaseStandardPowerOnly<T>::BicyclePowerBaseStandardPowerOnly() :
    CoreDataPage<T>() {}

template<class T>
uint8_t BicyclePowerBaseStandardPowerOnly<T>::getPedalPower() {
    return this->get8BitValue(PEDALPOWER_BYTE, PEDALPOWER_MASK);
}

template<class T>
uint8_t BicyclePowerBaseStandardPowerOnly<T>::getPedalDifferentiation() {
    return this->get8BitValue(PEDALDIFFERENTIATION_BYTE,
            PEDALDIFFERENTIATION_MASK,
            PEDALDIFFERENTIATION_SHIFT);
}

template<class T>
uint8_t BicyclePowerBaseStandardPowerOnly<T>::getInstantaneousCadence() {
    return this->get8BitValue(INSTANTANEOUSCADENCE_BYTE);
}

template<class T>
uint16_t BicyclePowerBaseStandardPowerOnly<T>::getAccumulatedPower() {
    return this->get16BitValue(
            ACCUMULATEDPOWER_LSB_BYTE, ACCUMULATEDPOWER_MSB_BYTE);
}

template<class T>
uint16_t BicyclePowerBaseStandardPowerOnly<T>::getInstantaneousPower() {
    return this->get16BitValue(
            INSTANTANEOUSPOWER_LSB_BYTE, INSTANTANEOUSPOWER_MSB_BYTE);
}

template class BicyclePowerBaseStandardPowerOnly<BroadcastData>;
template class BicyclePowerBaseStandardPowerOnly<BroadcastDataMsg>;

BicyclePowerStandardPowerOnly::BicyclePowerStandardPowerOnly(AntRxDataResponse& dp) :
    BicyclePowerBaseMainDataPage(dp),
    BicyclePowerBaseStandardPowerOnly() {}

BicyclePowerStandardPowerOnlyMsg::BicyclePowerStandardPowerOnlyMsg() :
    BicyclePowerBaseMainDataPageMsg(ANTPLUS_BICYCLEPOWER_DATAPAGES_STANDARDPOWERONLY_NUMBER),
    BicyclePowerBaseStandardPowerOnly<BroadcastDataMsg>() {
    setPedalPower(ANTPLUS_BICYCLEPOWER_DATAPAGES_STANDARDPOWERONLY_PEDALPOWER_NOTUSED);
    setPedalDifferentiation(ANTPLUS_BICYCLEPOWER_DATAPAGES_STANDARDPOWERONLY_PEDALDIFFERENTIATION_RIGHT);
    setInstantaneousCadence(ANTPLUS_BICYCLEPOWER_DATAPAGES_STANDARDPOWERONLY_INSTANTANEOUSCADENCE_INVALID);
}

void BicyclePowerStandardPowerOnlyMsg::setPedalPower(uint8_t pedalPower) {
    set8BitValue(pedalPower, PEDALPOWER_BYTE, PEDALPOWER_MASK);
}

void BicyclePowerStandardPowerOnlyMsg::setPedalDifferentiation(uint8_t differentiation) {
    set8BitValue(differentiation,
            PEDALDIFFERENTIATION_BYTE,
            PEDALDIFFERENTIATION_MASK,
            PEDALDIFFERENTIATION_SHIFT);
}

void BicyclePowerStandardPowerOnlyMsg::setInstantaneousCadence(uint8_t cadence) {
    set8BitValue(cadence, INSTANTANEOUSCADENCE_BYTE);
}

void BicyclePowerStandardPowerOnlyMsg::setAccumulatedPower(uint16_t accPower) {
    set16BitValue(accPower, ACCUMULATEDPOWER_LSB_BYTE, ACCUMULATEDPOWER_MSB_BYTE);
}

void BicyclePowerStandardPowerOnlyMsg::setInstantaneousPower(uint16_t instantaneousPower) {
    set16BitValue(instantaneousPower, INSTANTANEOUSPOWER_LSB_BYTE, INSTANTANEOUSPOWER_MSB_BYTE);
}
