#include <Profiles/Lev/DataPages/RX/ANTPLUS_LevSpeedSystemInformation2.h>
#include <Profiles/Lev/ANTPLUS_LevPrivateDefines.h>

LevSpeedSystemInformation2::LevSpeedSystemInformation2(AntRxDataResponse& dp) : LevBaseMainDataPage(dp) {
    return;
}

uint8_t LevSpeedSystemInformation2::getBatterySOC()
{
    return getData(1);
}

uint8_t LevSpeedSystemInformation2::getTravelModeState()
{
    return getData(2);
}

uint8_t LevSpeedSystemInformation2::getSystemState()
{
    return getData(3);
}

uint8_t LevSpeedSystemInformation2::getGearState()
{
    return getData(4);
}

uint8_t LevSpeedSystemInformation2::getPercentAssist()
{
    return getData(5);
}

uint16_t LevSpeedSystemInformation2::getSpeed() // in 1/10 km/h
{
    return (uint16_t)getData(6) + (((uint16_t)getData(7) & 0x0F) << 8);
}
