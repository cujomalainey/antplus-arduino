#include <Profiles/BicyclePower/DataPages/RX/ANTPLUS_BicyclePowerManufacturerID.h>

BicyclePowerManufacturerID::BicyclePowerManufacturerID(AntRxDataResponse& dp) : BicyclePowerBaseMainDataPage(dp), BicyclePowerBaseManufacturerID<BroadcastData>() {
}
