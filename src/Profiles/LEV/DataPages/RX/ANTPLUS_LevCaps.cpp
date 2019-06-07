#include <Profiles/Lev/DataPages/RX/ANTPLUS_LevCaps.h>
#include <Profiles/Lev/ANTPLUS_LevPrivateDefines.h>

LevCaps::LevCaps(AntRxDataResponse& dp) : LevBaseMainDataPage(dp) {
	return;
}

uint8_t LevCaps::getTravelModesSupported()
{
	return getData(2);
}

uint16_t LevCaps::getWheelCircumference()
{
	return (uint16_t)getData(3) + (((uint16_t)getData(4) & 0x0F) << 8);
}
