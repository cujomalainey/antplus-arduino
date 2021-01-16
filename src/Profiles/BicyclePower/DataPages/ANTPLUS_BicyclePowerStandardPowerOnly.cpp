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
    BicyclePowerBaseMainDataPageMsg(STANDARDPOWERONLY_NUMBER),
    BicyclePowerBaseStandardPowerOnly<BroadcastDataMsg>() {
    // TODO magic nums also using buffer directly
    _buffer[PEDALPOWER_BYTE] = 0xFF;
    _buffer[INSTANTANEOUSCADENCE_BYTE] = 0xFF;
}

void BicyclePowerStandardPowerOnlyMsg::setUpdateEventCount(uint8_t eventCount) {
    _buffer[UPDATEEVENTCOUNT_BYTE] = eventCount;
}

void BicyclePowerStandardPowerOnlyMsg::setCumulativePowerCount(uint16_t accPower) {
    _buffer[ACCUMULATEDPOWER_MSB_BYTE] = accPower >> 8;
    _buffer[ACCUMULATEDPOWER_LSB_BYTE] = accPower & ANTPLUS_DEFAULT_BYTE_MASK;
}

void BicyclePowerStandardPowerOnlyMsg::setInstataneousPowerCount(uint16_t power) {
    _buffer[INSTANTANEOUSPOWER_MSB_BYTE] = power >> 8;
    _buffer[INSTANTANEOUSPOWER_LSB_BYTE] = power & ANTPLUS_DEFAULT_BYTE_MASK;
}
