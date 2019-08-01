#include <Profiles/HeartRate/DataPages/RX/ANTPLUS_HeartRateProductInformation.h>

HeartRateProductInformation::HeartRateProductInformation(AntRxDataResponse& dp) : HeartRateBaseMainDataPage(dp), HeartRateBaseProductInformation<BroadcastData>() {
}
