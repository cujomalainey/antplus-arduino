#include <Profiles/HeartRate/DataPages/ANTPLUS_HeartRateCumulativeOperatingTime.h>
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

HeartRateCumulativeOperatingTime::HeartRateCumulativeOperatingTime(AntRxDataResponse& dp) : HeartRateBaseMainDataPage(dp), HeartRateBaseCumulativeOperatingTime<BroadcastData>() {}

HeartRateCumulativeOperatingTimeMsg::HeartRateCumulativeOperatingTimeMsg() : HeartRateBaseMainDataPageMsg(ANTPLUS_HEARTRATE_DATAPAGE_CUMULATIVEOPERATINGTIME_NUMBER), HeartRateBaseCumulativeOperatingTime<BroadcastDataMsg>() {
}

void HeartRateCumulativeOperatingTimeMsg::setCumulativeOperatingTime(uint32_t time) {
    set24BitValue(time,
            ANTPLUS_HEARTRATE_DATAPAGE_CUMULATIVEOPERATINGTIME_TIME_LSB_BYTE,
            ANTPLUS_HEARTRATE_DATAPAGE_CUMULATIVEOPERATINGTIME_TIME_MSB_BYTE);
}
