#include <Profiles/Lev/DataPages/RX/ANTPLUS_LevSpeedDist.h>
#include <Profiles/Lev/ANTPLUS_LevPrivateDefines.h>

/* Speed and Distance */
LevSpeedDist1::LevSpeedDist1(AntRxDataResponse& dp) : LevBaseMainDataPage(dp) {
	return;
}

uint32_t LevSpeedDist1::getTotalDist() // in km
{
	return (uint32_t)getData(1) + ((uint32_t)getData(2) << 8) + ((uint32_t)getData(3) << 16);
}

uint16_t LevSpeedDist1::getRemainingRange() // in km
{
	return (uint16_t)getData(4) + (((uint16_t)getData(5) & 0x0F) << 8);
}

uint16_t LevSpeedDist1::getSpeed() // in 1/10 km/h
{
	return (uint16_t)getData(6) + (((uint16_t)getData(7) & 0x0F) << 8);
}

/* Alt Speed and Distance */
LevSpeedDist2::LevSpeedDist2(AntRxDataResponse& dp) : LevBaseMainDataPage(dp) {
	return;
}

uint32_t LevSpeedDist2::getTotalDist() // in km
{
	return (uint32_t)getData(1) + ((uint32_t)getData(2) << 8) + ((uint32_t)getData(3) << 16);
}

uint16_t LevSpeedDist2::getFuelConsumption() // in Wh/km
{
	return (uint16_t)getData(4) + (((uint16_t)getData(5) & 0x0F) << 8);
}

uint16_t LevSpeedDist2::getSpeed() // in 1/10 km/h
{
	return (uint16_t)getData(6) + (((uint16_t)getData(7) & 0x0F) << 8);
}
