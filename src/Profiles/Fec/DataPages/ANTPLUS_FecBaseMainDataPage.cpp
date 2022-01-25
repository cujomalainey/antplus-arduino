#include <Profiles/Fec/DataPages/ANTPLUS_FecBaseMainDataPage.h>
#include <ANTPLUS_PrivateDefines.h>

FecBaseMainDataPage::FecBaseMainDataPage(AntRxDataResponse& dp) :
    BaseDataPage<BroadcastData>(dp) {}

FecBaseMainDataPageMsg::FecBaseMainDataPageMsg(uint8_t dataPageNumber) :
    BaseDataPageMsg<BroadcastDataMsg>() {
    setDataBuffer(_buffer);
    set8BitValue(dataPageNumber, ANTPLUS_DEFAULT_DATAPAGE_BYTE);
}

