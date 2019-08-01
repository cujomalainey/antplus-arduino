#include <Profiles/HeartRate/DataPages/RX/ANTPLUS_HeartRateManufacturerInformation.h>

HeartRateManufacturerInformation::HeartRateManufacturerInformation(AntRxDataResponse& dp) : HeartRateBaseMainDataPage(dp), HeartRateBaseManufacturerInformation<BroadcastData>() {
}
