#include <CommonDataPages/RX/ANTPLUS_BatteryStatus.h>

BatteryStatus::BatteryStatus(AntRxDataResponse& dp) : BaseDataPage<BroadcastData>(dp), BaseBatteryStatus<BroadcastData>() {
}
