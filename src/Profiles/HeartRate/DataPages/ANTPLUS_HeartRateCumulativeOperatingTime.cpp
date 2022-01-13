#include <Profiles/HeartRate/DataPages/ANTPLUS_HeartRateCumulativeOperatingTime.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

#define TIME_LSB_BYTE 1
#define TIME_MSB_BYTE 3

template<class T>
HeartRateBaseCumulativeOperatingTime<T>::HeartRateBaseCumulativeOperatingTime() :
    CoreDataPage<T>() {}

template<class T>
uint32_t HeartRateBaseCumulativeOperatingTime<T>::getCumulativeOperatingTime() {
    return this->get24BitValue(TIME_LSB_BYTE, TIME_MSB_BYTE);
}

template class HeartRateBaseCumulativeOperatingTime<BroadcastData>;
template class HeartRateBaseCumulativeOperatingTime<BroadcastDataMsg>;

HeartRateCumulativeOperatingTime::HeartRateCumulativeOperatingTime(AntRxDataResponse& dp) :
    HeartRateBaseMainDataPage(dp),
    HeartRateBaseCumulativeOperatingTime<BroadcastData>() {}

HeartRateCumulativeOperatingTimeMsg::HeartRateCumulativeOperatingTimeMsg() :
    HeartRateBaseMainDataPageMsg(HEARTRATE_CUMULATIVEOPERATINGTIME_NUMBER),
    HeartRateBaseCumulativeOperatingTime<BroadcastDataMsg>() {}

void HeartRateCumulativeOperatingTimeMsg::setCumulativeOperatingTime(uint32_t time) {
    set24BitValue(time, TIME_LSB_BYTE, TIME_MSB_BYTE);
}
