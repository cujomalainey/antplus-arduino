#include <Profiles/HeartRate/DataPages/RX/ANTPLUS_HeartRateCumulativeOperatingTime.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

HeartRateCumulativeOperatingTime::HeartRateCumulativeOperatingTime(AntRxDataResponse& dp) : HeartRateBaseMainDataPage(dp), HeartRateBaseCumulativeOperatingTime<BroadcastData>() {
}
