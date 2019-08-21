#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseCumulativeOperatingTime.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

template<class T>
HeartRateBaseCumulativeOperatingTime<T>::HeartRateBaseCumulativeOperatingTime() : CoreDataPage<T>() {
}

template<class T>
uint32_t HeartRateBaseCumulativeOperatingTime<T>::getCumulativeOperatingTime() {
    return this->get24BitValue(
            ANTPLUS_HEARTRATE_DATAPAGE_CUMULATIVEOPERATINGTIME_TIME_LSB_BYTE,
            ANTPLUS_HEARTRATE_DATAPAGE_CUMULATIVEOPERATINGTIME_TIME_MSB_BYTE);
}

template class HeartRateBaseCumulativeOperatingTime<BroadcastData>;
template class HeartRateBaseCumulativeOperatingTime<BroadcastDataMsg>;
