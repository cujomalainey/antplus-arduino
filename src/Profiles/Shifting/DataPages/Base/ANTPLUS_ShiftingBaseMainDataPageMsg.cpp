#include <Profiles/Shifting/DataPages/Base/ANTPLUS_ShiftingBaseMainDataPageMsg.h>
#include <Profiles/Shifting/ANTPLUS_ShiftingPrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

ShiftingBaseMainDataPageMsg::ShiftingBaseMainDataPageMsg() : BaseDataPageMsg<BroadcastDataMsg>()
{
    memset(_buffer, 0, MESSAGE_SIZE);
    setDataBuffer(_buffer);
    _buffer[ANTPLUS_SHIFTING_DATAPAGEBASE_DATAPAGE_BYTE] = ANTPLUS_SHIFTING_DATAPAGE_SHIFTSYSTEMSTATUS_NUMBER;
    _buffer[2] = 0xFF;
}

void ShiftingBaseMainDataPageMsg::setEventCount( uint8_t n )
{
    _buffer[1] = n;
}

void ShiftingBaseMainDataPageMsg::setCurrentGearRear(uint8_t cgr)
{
    _buffer[3] &= ~0x1F;
    _buffer[3] |= cgr & 0x1F;
}

void ShiftingBaseMainDataPageMsg::setCurrentGearFront( uint8_t cgf )
{
    _buffer[3] &= ~0xE0;
    _buffer[3] |= cgf << 5;
}

void ShiftingBaseMainDataPageMsg::setTotalNumbersGearRear(uint8_t tgr)
{
    _buffer[4] &= ~0x1F;
    _buffer[4] |= tgr & 0x1F;
}

void ShiftingBaseMainDataPageMsg::setTotalNumbersGearFront( uint8_t tgf )
{
    _buffer[4] &= ~0xE0;
    _buffer[4] |= tgf << 5;
}
