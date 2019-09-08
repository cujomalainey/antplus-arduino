#include <Profiles/BicycleSpeed/DataPages/Base/ANTPLUS_BicycleSpeedBaseCumulativeOperatingTime.h>
#include <Profiles/BicycleSpeed/ANTPLUS_BicycleSpeedPrivateDefines.h>

template<class T>
BicycleSpeedBaseCumulativeOperatingTime<T>::BicycleSpeedBaseCumulativeOperatingTime() : CoreDataPage<T>() {
}

template<class T>
uint32_t BicycleSpeedBaseCumulativeOperatingTime<T>::getCumulativeOperatingTime() {
    return this->get24BitValue(
            ANTPLUS_BICYCLESPEED_DATAPAGE_CUMULATIVEOPERATINGTIME_TIME_LSB_BYTE,
            ANTPLUS_BICYCLESPEED_DATAPAGE_CUMULATIVEOPERATINGTIME_TIME_MSB_BYTE);
}

template class BicycleSpeedBaseCumulativeOperatingTime<BroadcastData>;
template class BicycleSpeedBaseCumulativeOperatingTime<BroadcastDataMsg>;
