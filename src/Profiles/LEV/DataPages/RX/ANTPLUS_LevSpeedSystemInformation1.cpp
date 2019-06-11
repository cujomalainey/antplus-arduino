#include <Profiles/Lev/DataPages/RX/ANTPLUS_LevSpeedSystemInformation1.h>
#include <Profiles/Lev/ANTPLUS_LevPrivateDefines.h>

LevSpeedSystemInformation1::LevSpeedSystemInformation1(AntRxDataResponse& dp) : LevBaseMainDataPage(dp) {
	return;
}

uint8_t LevSpeedSystemInformation1::getTemperatureState()
{
	return getData(1);
}

uint8_t LevSpeedSystemInformation1::getTravelModeState()
{
	return getData(2);
}

uint8_t LevSpeedSystemInformation1::getSystemState()
{
	return getData(3);
}

uint8_t LevSpeedSystemInformation1::getGearState()
{
	return getData(4);
}

uint8_t LevSpeedSystemInformation1::getError()
{
	return getData(5);
}

uint16_t LevSpeedSystemInformation1::getSpeed() // in 1/10 km/h
{
	return (uint16_t)getData(6) + (((uint16_t)getData(7) & 0x0F) << 8);
}
