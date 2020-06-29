#include <Profiles/BicycleSpeed/DataPages/RX/ANTPLUS_BicycleSpeedBatteryStatus.h>

BicycleSpeedBatteryStatus::BicycleSpeedBatteryStatus(AntRxDataResponse& dp) : BicycleSpeedBaseMainDataPage(dp), BicycleSpeedBaseBatteryStatus<BroadcastData>() {
}
