#include <Profiles/HeartRate/DataPages/RX/ANTPLUS_HeartRateCapabilities.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

HeartRateCapabilities::HeartRateCapabilities(AntRxDataResponse& dp) : HeartRateBaseMainDataPage(dp), HeartRateBaseCapabilities<BroadcastData>() {
}
