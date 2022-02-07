#include <Profiles/Environment/DataPages/ANTPLUS_EnvironmentTemperature.h>
#include <Profiles/Environment/ANTPLUS_EnvironmentPrivateDefines.h>

#define EVENTCOUNT_BYTE 2
#define LOW24HOUR_LSB_BYTE 3
#define LOW24HOUR_MSB_BYTE 4
#define LOW24HOUR_MSB_MASK 0xF0
#define LOW24HOUR_MSB_SHIFT 4
#define HIGH24HOUR_LSB_BYTE 4
#define HIGH24HOUR_MSB_BYTE 5
#define HIGH24HOUR_LSB_MASK 0x0F
#define HIGH24HOUR_MSB_SHIFT 4
#define CURRENTTEMP_LSB_BYTE 6
#define CURRENTTEMP_MSB_BYTE 7

template<class T>
EnvironmentBaseTemperature<T>::EnvironmentBaseTemperature() :
    CoreDataPage<T>() {}

template<class T>
uint8_t EnvironmentBaseTemperature<T>::getEventCount() {
    return this->get8BitValue(EVENTCOUNT_BYTE);
}

/* NOTE: this is a non-contigous data field, which resuls in the shenanigans below */
template<class T>
int16_t EnvironmentBaseTemperature<T>::get24HourLow() {
    int16_t low = this->get8BitValue(LOW24HOUR_MSB_BYTE, LOW24HOUR_MSB_MASK);
    low <<= LOW24HOUR_MSB_SHIFT;
    low |= this->get8BitValue(LOW24HOUR_LSB_BYTE);
    // extend bits if negative
    low = (0x800 & low) ? low | 0xF000 : low;
    return low;
}

/* NOTE: this is a non-contigous data field, which resuls in the shenanigans below */
template<class T>
int16_t EnvironmentBaseTemperature<T>::get24HourHigh() {
    int16_t high = this->get8BitValue(HIGH24HOUR_MSB_BYTE);
    high <<= HIGH24HOUR_MSB_SHIFT;
    high |= this->get8BitValue(HIGH24HOUR_LSB_BYTE, HIGH24HOUR_LSB_MASK);
    // extend bits if negative
    high = (0x800 & high) ? high | 0xF000 : high;
    return high;
}

template<class T>
int16_t EnvironmentBaseTemperature<T>::getCurrentTemp() {
    return this->get16BitValue(CURRENTTEMP_LSB_BYTE, CURRENTTEMP_MSB_BYTE);
}

template class EnvironmentBaseTemperature<BroadcastData>;
template class EnvironmentBaseTemperature<BroadcastDataMsg>;

EnvironmentTemperature::EnvironmentTemperature(AntRxDataResponse& dp) :
    EnvironmentBaseDataPage(dp),
    EnvironmentBaseTemperature<BroadcastData>() {}

