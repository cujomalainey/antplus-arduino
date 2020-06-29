#include <Profiles/BicycleSpeed/DataPages/RX/ANTPLUS_BicycleSpeedProductID.h>

BicycleSpeedProductID::BicycleSpeedProductID(AntRxDataResponse& dp) : BicycleSpeedBaseMainDataPage(dp), BicycleSpeedBaseProductID<BroadcastData>() {
}
