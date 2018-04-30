#include <Profiles/Environment/DataPages/Base/ANTPLUS_EnvironmentBaseDataPage.h>
#include <Profiles/Environment/ANTPLUS_EnvironmentPrivateDefines.h>

EnvironmentBaseDataPage::EnvironmentBaseDataPage(AntRxDataResponse& dp) : BaseDataPage<BroadcastData>(dp) {

}

uint8_t EnvironmentBaseDataPage::getDataPageNumber() {
    return getData(ANTPLUS_ENVIRONMENT_DATAPAGEBASE_DATAPAGE_BYTE);
}
