#include <Profiles/BicycleSpeed/DataPages/RX/ANTPLUS_BicycleSpeedManufacturerID.h>

BicycleSpeedManufacturerID::BicycleSpeedManufacturerID(AntRxDataResponse& dp) : BicycleSpeedBaseMainDataPage(dp), BicycleSpeedBaseManufacturerID<BroadcastData>() {
}
