#include <Profiles/MuscleOxygen/DataPages/ANTPLUS_MuscleOxygenBaseMainDataPage.h>
#include <ANTPLUS_PrivateDefines.h>

// TODO setup core
MuscleOxygenBaseMainDataPageMsg::MuscleOxygenBaseMainDataPageMsg(uint8_t dataPageNumber) : BaseDataPageMsg() {
    memset(_buffer, 0, MESSAGE_SIZE);
    setDataBuffer(_buffer);
    set8BitValue(dataPageNumber, ANTPLUS_DEFAULT_DATAPAGE_BYTE);
}