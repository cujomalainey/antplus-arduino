#include <Profiles/HeartRate/DataPages/RX/ANTPLUS_HeartRateCumulativeOperatingTime.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

HeartRateCumulativeOperatingTime::HeartRateCumulativeOperatingTime(AntRxDataResponse& dp) : HeartRateBaseMainDataPage(dp) {

}

uint32_t HeartRateCumulativeOperatingTime::getCumulativeOperatingTime() {
    uint32_t time = getData(ANTPLUS_HEARTRATE_DATAPAGE_CUMULATIVEOPERATINGTIME_TIME_LSB_BYTE);
    time |= getData(ANTPLUS_HEARTRATE_DATAPAGE_CUMULATIVEOPERATINGTIME_TIME_MID_BYTE) << ANTPLUS_HEARTRATE_DATAPAGE_CUMULATIVEOPERATINGTIME_TIME_MID_SHIFT;
    time |= getData(ANTPLUS_HEARTRATE_DATAPAGE_CUMULATIVEOPERATINGTIME_TIME_MSB_BYTE) << ANTPLUS_HEARTRATE_DATAPAGE_CUMULATIVEOPERATINGTIME_TIME_MSB_SHIFT;
    return time;
}
