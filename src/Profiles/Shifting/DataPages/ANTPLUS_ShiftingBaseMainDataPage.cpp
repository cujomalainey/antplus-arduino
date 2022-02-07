#include <Profiles/Shifting/DataPages/ANTPLUS_ShiftingBaseMainDataPage.h>
#include <Profiles/Shifting/ANTPLUS_ShiftingPrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

ShiftingBaseMainDataPage::ShiftingBaseMainDataPage(AntRxDataResponse& dp) :
    BaseDataPage<BroadcastData>(dp) {}

ShiftingBaseMainDataPageMsg::ShiftingBaseMainDataPageMsg(uint8_t dataPageNumber) :
    BaseDataPageMsg<BroadcastDataMsg>()
{
    setDataBuffer(_buffer);
    set8BitValue(dataPageNumber, ANTPLUS_DEFAULT_DATAPAGE_BYTE);
}
