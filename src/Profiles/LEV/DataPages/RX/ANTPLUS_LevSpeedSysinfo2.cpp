#include <Profiles/Lev/DataPages/RX/ANTPLUS_LevSpeedSysinfo2.h>
#include <Profiles/Lev/ANTPLUS_LevPrivateDefines.h>

LevSpeedSysinfo2::LevSpeedSysinfo2(AntRxDataResponse& dp) : LevBaseMainDataPage(dp) {
	return;
}

uint8_t LevSpeedSysinfo2::getBatterySOC()
{
	return getData(1);
}

uint8_t LevSpeedSysinfo2::getTravelModeState()
{
	return getData(2);
}

uint8_t LevSpeedSysinfo2::getSystemState()
{
	return getData(3);
}

uint8_t LevSpeedSysinfo2::getGearState()
{
	return getData(4);
}

uint8_t LevSpeedSysinfo2::getPercentAssist()
{
	return getData(5);
}

uint16_t LevSpeedSysinfo2::getSpeed() // in 1/10 km/h
{
	return (uint16_t)getData(6) + (((uint16_t)getData(7) & 0x0F) << 8);
}
