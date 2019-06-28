#include <Profiles/BicycleSpeed/DataPages/RX/ANTPLUS_BicycleSpeedCumulativeOperatingTime.h>
#include <Profiles/BicycleSpeed/ANTPLUS_BicycleSpeedPrivateDefines.h>

BicycleSpeedCumulativeOperatingTime::BicycleSpeedCumulativeOperatingTime(AntRxDataResponse& dp) : BicycleSpeedBaseMainDataPage(dp) {

}

uint32_t BicycleSpeedCumulativeOperatingTime::getCumulativeOperatingTime() {
    uint32_t time = getData(ANTPLUS_BICYCLESPEED_DATAPAGE_CUMULATIVEOPERATINGTIME_TIME_LSB_BYTE);
    time |= getData(ANTPLUS_BICYCLESPEED_DATAPAGE_CUMULATIVEOPERATINGTIME_TIME_MID_BYTE) << ANTPLUS_BICYCLESPEED_DATAPAGE_CUMULATIVEOPERATINGTIME_TIME_MID_SHIFT;
    time |= getData(ANTPLUS_BICYCLESPEED_DATAPAGE_CUMULATIVEOPERATINGTIME_TIME_MSB_BYTE) << ANTPLUS_BICYCLESPEED_DATAPAGE_CUMULATIVEOPERATINGTIME_TIME_MSB_SHIFT;
    return time;
}
