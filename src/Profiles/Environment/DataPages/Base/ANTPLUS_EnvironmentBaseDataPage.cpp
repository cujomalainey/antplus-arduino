#include <Profiles/Environment/DataPages/Base/ANTPLUS_EnvironmentBaseDataPage.h>
#include <Profiles/Environment/ANTPLUS_EnvironmentPrivateDefines.h>

EnvironmentBaseDataPage::EnvironmentBaseDataPage(AntRxDataResponse& dp) : BaseDataPage<BroadcastData>(dp) {
}
