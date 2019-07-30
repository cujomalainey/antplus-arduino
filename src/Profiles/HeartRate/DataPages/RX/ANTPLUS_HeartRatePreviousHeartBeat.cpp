#include <Profiles/HeartRate/DataPages/RX/ANTPLUS_HeartRatePreviousHeartBeat.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

HeartRatePreviousHeartBeat::HeartRatePreviousHeartBeat(AntRxDataResponse& dp) : HeartRateBaseMainDataPage(dp), HeartRateBasePreviousHeartBeat<BroadcastData>() {
}
