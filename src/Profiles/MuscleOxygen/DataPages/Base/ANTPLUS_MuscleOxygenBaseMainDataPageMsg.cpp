#include <Profiles/MuscleOxygen/DataPages/Base/ANTPLUS_MuscleOxygenBaseMainDataPageMsg.h>
#include <ANTPLUS_PrivateDefines.h>

MuscleOxygenBaseMainDataPageMsg::MuscleOxygenBaseMainDataPageMsg(uint8_t dataPageNumber) : BaseDataPageMsg() {
    memset(_buffer, 0, MESSAGE_SIZE);
    setDataBuffer(_buffer);
    set8BitValue(dataPageNumber, ANTPLUS_DEFAULT_DATAPAGE_BYTE);
}
