#include <Profiles/BicyclePower/DataPages/ANTPLUS_BicyclePowerCrankTorqueFrequency.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerPrivateDefines.h>

#define SLOPE_MSB_BYTE            2
#define SLOPE_LSB_BYTE            3
#define TIMESTAMP_MSB_BYTE        4
#define TIMESTAMP_LSB_BYTE        5
#define TORQUETICKSTAMP_MSB_BYTE  6
#define TORQUETICKSTAMP_LSB_BYTE  7

template<class T>
BicyclePowerBaseCrankTorqueFrequency<T>::BicyclePowerBaseCrankTorqueFrequency() :
    CoreDataPage<T>() {}

template<class T>
uint16_t BicyclePowerBaseCrankTorqueFrequency<T>::getSlope() {
    return this->get16BitValue(SLOPE_LSB_BYTE, SLOPE_MSB_BYTE);
}

template<class T>
uint16_t BicyclePowerBaseCrankTorqueFrequency<T>::getTimeStamp() {
    return this->get16BitValue(TIMESTAMP_LSB_BYTE, TIMESTAMP_MSB_BYTE);
}

template<class T>
uint16_t BicyclePowerBaseCrankTorqueFrequency<T>::getTorqueTicksStamp() {
    return this->get16BitValue(TORQUETICKSTAMP_LSB_BYTE,
            TORQUETICKSTAMP_MSB_BYTE);
}

template class BicyclePowerBaseCrankTorqueFrequency<BroadcastData>;
template class BicyclePowerBaseCrankTorqueFrequency<BroadcastDataMsg>;

BicyclePowerCrankTorqueFrequency::BicyclePowerCrankTorqueFrequency(AntRxDataResponse& dp) :
    BicyclePowerBaseMainDataPage(dp),
    BicyclePowerBaseCrankTorqueFrequency() {}

BicyclePowerCrankTorqueFrequencyMsg::BicyclePowerCrankTorqueFrequencyMsg() :
    BicyclePowerBaseMainDataPageMsg(ANTPLUS_BICYCLEPOWER_DATAPAGES_CRANKTORQUEFREQUENCY_NUMBER),
    BicyclePowerBaseCrankTorqueFrequency() {}

void BicyclePowerCrankTorqueFrequencyMsg::setSlope(uint16_t slope) {
    set16BitValue(slope, SLOPE_LSB_BYTE, SLOPE_MSB_BYTE);
}

void BicyclePowerCrankTorqueFrequencyMsg::setTimeStamp(uint16_t timestamp) {
    set16BitValue(timestamp, TIMESTAMP_LSB_BYTE, TIMESTAMP_MSB_BYTE);
}

void BicyclePowerCrankTorqueFrequencyMsg::setTorqueTicksStamp(uint16_t tickstamp) {
    set16BitValue(tickstamp, TORQUETICKSTAMP_LSB_BYTE,
            TORQUETICKSTAMP_MSB_BYTE);
}
