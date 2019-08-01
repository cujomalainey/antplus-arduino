#include <Profiles/HeartRate/DataPages/RX/ANTPLUS_HeartRateSwimIntervalSummary.h>

HeartRateSwimIntervalSummary::HeartRateSwimIntervalSummary(AntRxDataResponse& dp) : HeartRateBaseMainDataPage(dp), HeartRateBaseSwimIntervalSummary<BroadcastData>() {
}
