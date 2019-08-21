#include <Profiles/HeartRate/DataPages/RX/ANTPLUS_HeartRateCapabilities.h>

HeartRateCapabilities::HeartRateCapabilities(AntRxDataResponse& dp) : HeartRateBaseMainDataPage(dp), HeartRateBaseCapabilities<BroadcastData>() {
}
