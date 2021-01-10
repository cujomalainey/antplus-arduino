#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerBaseMainDataPage.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerPrivateDefines.h>

BicyclePowerBaseMainDataPage::BicyclePowerBaseMainDataPage(AntRxDataResponse& dp) : BaseDataPage<BroadcastData>(dp) {

}

uint8_t BicyclePowerBaseMainDataPage::getDataPageNumber() {
	    return getData(ANTPLUS_BICYCLEPOWER_DATAPAGE_DATAPAGE_BYTE);
}

uint8_t BicyclePowerBaseMainDataPage::getUpdateEventCount() {
    return getData(ANTPLUS_BICYCLEPOWER_DATAPAGE_UPDATEEVENTCOUNT_BYTE);
}
