#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPage.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

HeartRateBaseMainDataPage::HeartRateBaseMainDataPage(AntRxDataResponse& dp) : BaseDataPage<BroadcastData>(dp), HeartRateCoreMainDataPage<BroadcastData>() {
}
