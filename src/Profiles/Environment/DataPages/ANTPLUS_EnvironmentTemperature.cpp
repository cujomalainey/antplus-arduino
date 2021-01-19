#include <Profiles/Environment/DataPages/ANTPLUS_EnvironmentTemperature.h>
#include <Profiles/Environment/ANTPLUS_EnvironmentPrivateDefines.h>

template<class T>
EnvironmentBaseTemperature<T>::EnvironmentBaseTemperature() :
    CoreDataPage<T>() {}

template<class T>
uint8_t EnvironmentBaseTemperature<T>::getEventCount() {
    return this->get8BitValue(
            ANTPLUS_ENVIRONMENT_DATAPAGE_TEMPERATURE_EVENTCOUNT_BYTE);
}

/* NOTE: this is a non-contigous data field, which resuls in the shenanigans below */
template<class T>
int16_t EnvironmentBaseTemperature<T>::get24HourLow() {
    int16_t low = this->get8BitValue(
            ANTPLUS_ENVIRONMENT_DATAPAGE_TEMPERATURE_24HOURLOW_MSB_BYTE,
            ANTPLUS_ENVIRONMENT_DATAPAGE_TEMPERATURE_24HOURLOW_MSB_MASK);
    low <<= ANTPLUS_ENVIRONMENT_DATAPAGE_TEMPERATURE_24HOURLOW_MSB_SHIFT;
    low |= this->get8BitValue(
            ANTPLUS_ENVIRONMENT_DATAPAGE_TEMPERATURE_24HOURLOW_LSB_BYTE);
    // extend bits if negative
    low = (0x800 & low) ? low | 0xF000 : low;
    return low;
}

/* NOTE: this is a non-contigous data field, which resuls in the shenanigans below */
template<class T>
int16_t EnvironmentBaseTemperature<T>::get24HourHigh() {
    int16_t high = this->get8BitValue(
            ANTPLUS_ENVIRONMENT_DATAPAGE_TEMPERATURE_24HOURHIGH_MSB_BYTE);
    high <<= ANTPLUS_ENVIRONMENT_DATAPAGE_TEMPERATURE_24HOURHIGH_MSB_SHIFT;
    high |= this->get8BitValue(
            ANTPLUS_ENVIRONMENT_DATAPAGE_TEMPERATURE_24HOURHIGH_LSB_BYTE,
            ANTPLUS_ENVIRONMENT_DATAPAGE_TEMPERATURE_24HOURHIGH_LSB_MASK);
    // extend bits if negative
    high = (0x800 & high) ? high | 0xF000 : high;
    return high;
}

template<class T>
int16_t EnvironmentBaseTemperature<T>::getCurrentTemp() {
    return this->get16BitValue(
            ANTPLUS_ENVIRONMENT_DATAPAGE_TEMPERATURE_CURRENTTEMP_LSB_BYTE,
            ANTPLUS_ENVIRONMENT_DATAPAGE_TEMPERATURE_CURRENTTEMP_MSB_BYTE);
}

template class EnvironmentBaseTemperature<BroadcastData>;
template class EnvironmentBaseTemperature<BroadcastDataMsg>;

EnvironmentTemperature::EnvironmentTemperature(AntRxDataResponse& dp) :
    EnvironmentBaseDataPage(dp),
    EnvironmentBaseTemperature<BroadcastData>() {}

