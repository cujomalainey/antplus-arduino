#include <Profiles/HeartRate/DataPages/RX/ANTPLUS_HeartRateManufacturerInformation.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

HeartRateManufacturerInformation::HeartRateManufacturerInformation(AntRxDataResponse& dp) : HeartRateBaseMainDataPage(dp), HeartRateBaseManufacturerInformation<BroadcastData>() {
}
