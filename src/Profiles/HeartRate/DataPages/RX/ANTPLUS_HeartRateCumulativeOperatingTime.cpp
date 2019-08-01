#include <Profiles/HeartRate/DataPages/RX/ANTPLUS_HeartRateCumulativeOperatingTime.h>

HeartRateCumulativeOperatingTime::HeartRateCumulativeOperatingTime(AntRxDataResponse& dp) : HeartRateBaseMainDataPage(dp), HeartRateBaseCumulativeOperatingTime<BroadcastData>() {
}
