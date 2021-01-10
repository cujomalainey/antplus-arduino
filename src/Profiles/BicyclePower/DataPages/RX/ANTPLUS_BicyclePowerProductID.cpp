#include <Profiles/BicyclePower/DataPages/RX/ANTPLUS_BicyclePowerProductID.h>

BicyclePowerProductID::BicyclePowerProductID(AntRxDataResponse& dp) : BicyclePowerBaseMainDataPage(dp), BicyclePowerBaseProductID<BroadcastData>() {
}
