#include <Profiles/Shifting/DataPages/Base/ANTPLUS_ShiftingBaseMainDataPageMsg.h>
#include <Profiles/Shifting/ANTPLUS_ShiftingPrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

ShiftingBaseMainDataPageMsg::ShiftingBaseMainDataPageMsg(uint8_t dataPageNumber) : BaseDataPageMsg<BroadcastDataMsg>()
{
    memset(_buffer, 0, MESSAGE_SIZE);
    setDataBuffer(_buffer);
    set8BitValue(dataPageNumber, ANTPLUS_SHIFTING_DATAPAGEBASE_DATAPAGE_BYTE);
    _buffer[2] = 0xFF;
}
