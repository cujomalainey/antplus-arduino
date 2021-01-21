#include <Profiles/Lev/DataPages/ANTPLUS_LevBaseMainDataPage.h>
#include <ANTPLUS_PrivateDefines.h>

LevBaseMainDataPage::LevBaseMainDataPage(AntRxDataResponse& dp) :
    BaseDataPage<BroadcastData>(dp) {}

LevBaseMainDataPageMsg::LevBaseMainDataPageMsg(uint8_t dataPageNumber) :
    BaseDataPageMsg<AcknowledgedDataMsg>() {
    setDataBuffer(_buffer);
    _buffer[ANTPLUS_DEFAULT_DATAPAGE_BYTE] = dataPageNumber;
}
