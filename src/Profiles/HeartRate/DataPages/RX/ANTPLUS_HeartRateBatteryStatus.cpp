#include <Profiles/HeartRate/DataPages/RX/ANTPLUS_HeartRateBatteryStatus.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

HeartRateBatteryStatus::HeartRateBatteryStatus(AntRxDataResponse& dp) : HeartRateBaseMainDataPage(dp), HeartRateBaseBatteryStatus() {

}
