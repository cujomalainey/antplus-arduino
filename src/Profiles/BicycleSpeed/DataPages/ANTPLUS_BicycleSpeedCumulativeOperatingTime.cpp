#include <Profiles/BicycleSpeed/DataPages/ANTPLUS_BicycleSpeedCumulativeOperatingTime.h>
#include <Profiles/BicycleSpeed/ANTPLUS_BicycleSpeedPrivateDefines.h>

#define CUMULATIVEOPERATINGTIME_TIME_LSB_BYTE 1
#define CUMULATIVEOPERATINGTIME_TIME_MSB_BYTE 3

template<class T>
BicycleSpeedBaseCumulativeOperatingTime<T>::BicycleSpeedBaseCumulativeOperatingTime() :
    CoreDataPage<T>() {}

template<class T>
uint32_t BicycleSpeedBaseCumulativeOperatingTime<T>::getCumulativeOperatingTime() {
    return this->get24BitValue(CUMULATIVEOPERATINGTIME_TIME_LSB_BYTE,
            CUMULATIVEOPERATINGTIME_TIME_MSB_BYTE);
}

template class BicycleSpeedBaseCumulativeOperatingTime<BroadcastData>;
template class BicycleSpeedBaseCumulativeOperatingTime<BroadcastDataMsg>;

BicycleSpeedCumulativeOperatingTime::BicycleSpeedCumulativeOperatingTime(AntRxDataResponse& dp) :
    BicycleSpeedBaseMainDataPage(dp), BicycleSpeedBaseCumulativeOperatingTime<BroadcastData>() {}
