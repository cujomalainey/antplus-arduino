#include <Profiles/BicycleSpeed/DataPages/RX/ANTPLUS_BicycleSpeedManufacturerID.h>
#include <Profiles/BicycleSpeed/ANTPLUS_BicycleSpeedPrivateDefines.h>

BicycleSpeedManufacturerID::BicycleSpeedManufacturerID(AntRxDataResponse& dp) : BicycleSpeedBaseMainDataPage(dp), BicycleSpeedBaseManufacturerID<BroadcastData>() {
}
