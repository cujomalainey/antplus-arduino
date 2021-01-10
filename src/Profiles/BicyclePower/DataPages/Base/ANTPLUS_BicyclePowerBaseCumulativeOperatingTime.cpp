#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerBaseCumulativeOperatingTime.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerPrivateDefines.h>

template<class T>
BicyclePowerBaseCumulativeOperatingTime<T>::BicyclePowerBaseCumulativeOperatingTime() : CoreDataPage<T>() {
}

template<class T>
uint32_t BicyclePowerBaseCumulativeOperatingTime<T>::getCumulativeOperatingTime() {
    return this->get24BitValue(
            ANTPLUS_BICYCLEPOWER_DATAPAGE_CUMULATIVEOPERATINGTIME_TIMELSB_BYTE,
            ANTPLUS_BICYCLEPOWER_DATAPAGE_CUMULATIVEOPERATINGTIME_TIMEMSB_BYTE);
}

template class BicyclePowerBaseCumulativeOperatingTime<BroadcastData>;
template class BicyclePowerBaseCumulativeOperatingTime<BroadcastDataMsg>;
