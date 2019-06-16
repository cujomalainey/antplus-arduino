#include <Profiles/MuscleOxygen/DataPages/Base/ANTPLUS_MuscleOxygenBaseMainDataPageMsg.h>
#include <Profiles/MuscleOxygen/ANTPLUS_MuscleOxygenPrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>


MuscleOxygenBaseMainDataPageMsg::MuscleOxygenBaseMainDataPageMsg(uint8_t dataPageNumber) : BaseDataPageMsg<BroadcastDataMsg>()
{
    memset(_buffer, 0, MESSAGE_SIZE);
    setDataBuffer(_buffer);
    _buffer[ANTPLUS_DEFAULT_DATAPAGE_BYTE] = dataPageNumber;
    setCapabilities();
    setNotifications();
}

void MuscleOxygenBaseMainDataPageMsg::setEventCount( uint8_t n )
{
    _buffer[1] = n;
}

void MuscleOxygenBaseMainDataPageMsg::setNotifications( uint8_t n )
{
    _buffer[2] = n;
}

void MuscleOxygenBaseMainDataPageMsg::setCapabilities( uint8_t c )
{
    _buffer[3] = c;
}

void MuscleOxygenBaseMainDataPageMsg::setTotalHemoglobinConcentration( uint16_t tc )
{
    _buffer[4] = (uint8_t)tc;
    _buffer[5] &= ~0x0F;
    _buffer[5] |= (tc >> 8) & 0x0F;
}

/* TODO
void MuscleOxygenBaseMainDataPageMsg::setPreviousSaturatedHemoglobinPercentage( uint16_t pp )
{
    _buffer[5] &= ~0xF0;
    _buffer[5] |= (uint8_t)(pp << 4);
    _buffer[6] &= ~0x3F;
    _buffer[6] |= (pp >> 4) & 0x3F;
}
*/

void MuscleOxygenBaseMainDataPageMsg::setCurrentSaturatedHemoglobinPercentage( uint16_t cp )
{
    _buffer[6] &= ~0xC0;
    _buffer[6] |= (uint8_t)(cp << 6);
    _buffer[7]  = cp >> 2;
}
