#include <Profiles/BicyclePower/DataPages/ANTPLUS_BicyclePowerStandardPowerOnly.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerPrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

#define UPDATEEVENTCOUNT_BYTE   1
#define PEDALPOWER_BYTE 2
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
    return this->get8BitValue(PEDALPOWER_BYTE);
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
    BicyclePowerBaseMainDataPageMsg(BICYCLEPOWER_STANDARDPOWERONLY_NUMBER),
    BicyclePowerBaseStandardPowerOnly<BroadcastDataMsg>() {
    // TODO magic nums
    this->set8BitValue(0xFF, PEDALPOWER_BYTE);
    this->set8BitValue(0xFF, INSTANTANEOUSCADENCE_BYTE);
}

void BicyclePowerStandardPowerOnlyMsg::setUpdateEventCount(uint8_t eventCount) {
    this->set8BitValue(eventCount, UPDATEEVENTCOUNT_BYTE);
}

void BicyclePowerStandardPowerOnlyMsg::setCumulativePowerCount(uint16_t accPower) {
    this->set16BitValue(accPower, ACCUMULATEDPOWER_LSB_BYTE, ACCUMULATEDPOWER_MSB_BYTE);
}

void BicyclePowerStandardPowerOnlyMsg::setInstantaneousPowerCount(uint16_t power) {
    this->set16BitValue(power, INSTANTANEOUSPOWER_LSB_BYTE, INSTANTANEOUSPOWER_MSB_BYTE);
}
