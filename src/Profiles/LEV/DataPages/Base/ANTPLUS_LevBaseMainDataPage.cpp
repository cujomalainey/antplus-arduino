#include <Profiles/Lev/DataPages/Base/ANTPLUS_LevBaseMainDataPage.h>
#include <Profiles/Lev/ANTPLUS_LevPrivateDefines.h>

LevBaseMainDataPage::LevBaseMainDataPage(AntRxDataResponse& dp) : BaseDataPage<BroadcastData>(dp) {

}

uint8_t LevBaseMainDataPage::getDataPageNumber() {
    return getData(ANTPLUS_LEV_DATAPAGEBASE_DATAPAGE_BYTE) & ANTPLUS_LEV_DATAPAGEBASE_DATAPAGE_MASK;
}
