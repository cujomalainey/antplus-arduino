#include <Profiles/Lev/DataPages/ANTPLUS_LevBaseMainDataPage.h>
#include <ANTPLUS_PrivateDefines.h>

LevBaseMainDataPage::LevBaseMainDataPage(AntRxDataResponse& dp) :
    BaseDataPage<BroadcastData>(dp) {}

LevBaseMainDataPageMsg::LevBaseMainDataPageMsg(uint8_t dataPageNumber) :
    BaseDataPageMsg<AcknowledgedDataMsg>() {
    setDataBuffer(_buffer);
    set8BitValue(dataPageNumber, ANTPLUS_DEFAULT_DATAPAGE_BYTE);
}
