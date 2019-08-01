#include <Profiles/HeartRate/DataPages/RX/ANTPLUS_HeartRatePreviousHeartBeat.h>

HeartRatePreviousHeartBeat::HeartRatePreviousHeartBeat(AntRxDataResponse& dp) : HeartRateBaseMainDataPage(dp), HeartRateBasePreviousHeartBeat<BroadcastData>() {
}
