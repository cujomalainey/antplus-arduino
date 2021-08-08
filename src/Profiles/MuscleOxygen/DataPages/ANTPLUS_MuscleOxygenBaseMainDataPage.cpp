#include <Profiles/MuscleOxygen/DataPages/ANTPLUS_MuscleOxygenBaseMainDataPage.h>
#include <ANTPLUS_PrivateDefines.h>

MuscleOxygenBaseMainDataPage::MuscleOxygenBaseMainDataPage(AntRxDataResponse& dp) :
    BaseDataPage<BroadcastData>(dp) {}

MuscleOxygenBaseMainDataPageMsg::MuscleOxygenBaseMainDataPageMsg(uint8_t dataPageNumber) : BaseDataPageMsg() {
    setDataBuffer(_buffer);
    set8BitValue(dataPageNumber, ANTPLUS_DEFAULT_DATAPAGE_BYTE);
}
