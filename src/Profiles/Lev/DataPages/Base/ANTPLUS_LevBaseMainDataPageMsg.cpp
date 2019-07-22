#include <Profiles/Lev/DataPages/Base/ANTPLUS_LevBaseMainDataPageMsg.h>
#include <Profiles/Lev/ANTPLUS_LevPrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

LevBaseMainDataPageMsg::LevBaseMainDataPageMsg(uint8_t dataPageNumber) : BaseDataPageMsg<AcknowledgedDataMsg>() {
    setDataBuffer(_buffer);
    _buffer[ANTPLUS_DEFAULT_DATAPAGE_BYTE] = dataPageNumber;
}
