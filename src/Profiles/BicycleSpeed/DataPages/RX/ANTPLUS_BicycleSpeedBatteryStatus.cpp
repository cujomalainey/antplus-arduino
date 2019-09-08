#include <Profiles/BicycleSpeed/DataPages/RX/ANTPLUS_BicycleSpeedBatteryStatus.h>
#include <Profiles/BicycleSpeed/ANTPLUS_BicycleSpeedPrivateDefines.h>

BicycleSpeedBatteryStatus::BicycleSpeedBatteryStatus(AntRxDataResponse& dp) : BicycleSpeedBaseMainDataPage(dp), BicycleSpeedBaseBatteryStatus<BroadcastData>() {
}
