#include <Profiles/BicyclePower/DataPages/ANTPLUS_BicyclePowerStandardPowerOnly.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerPrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

template<class T>
BicyclePowerBaseStandardPowerOnly<T>::BicyclePowerBaseStandardPowerOnly() :
    CoreDataPage<T>() {}

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

BicyclePowerStandardPowerOnly::BicyclePowerStandardPowerOnly(AntRxDataResponse& dp) :
    BicyclePowerBaseMainDataPage(dp),
    BicyclePowerBaseStandardPowerOnly() {}

BicyclePowerStandardPowerOnlyMsg::BicyclePowerStandardPowerOnlyMsg() :
    BicyclePowerBaseMainDataPageMsg(ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_NUMBER),
    BicyclePowerBaseStandardPowerOnly<BroadcastDataMsg>() {
    _buffer[ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_PEDALPOWER_BYTE] = 0xFF;
    _buffer[ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_INSTANTANEOUSCADENCE_BYTE] = 0xFF;
}

void BicyclePowerStandardPowerOnlyMsg::setUpdateEventCount(uint8_t eventCount) {
    _buffer[ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_UPDATEEVENTCOUNT_BYTE] = eventCount;
}

void BicyclePowerStandardPowerOnlyMsg::setCumulativePowerCount(uint16_t accPower) {
    _buffer[ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_ACCUMULATEDPOWER_MSB_BYTE] = accPower >> 8;
    _buffer[ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_ACCUMULATEDPOWER_LSB_BYTE] = accPower & ANTPLUS_DEFAULT_BYTE_MASK;
}

void BicyclePowerStandardPowerOnlyMsg::setInstataneousPowerCount(uint16_t power) {
    _buffer[ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_INSTANTANEOUSPOWER_MSB_BYTE] = power >> 8;
    _buffer[ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_INSTANTANEOUSPOWER_LSB_BYTE] = power & ANTPLUS_DEFAULT_BYTE_MASK;
}
