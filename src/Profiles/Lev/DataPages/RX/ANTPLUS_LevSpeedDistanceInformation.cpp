#include <Profiles/Lev/DataPages/RX/ANTPLUS_LevSpeedDistanceInformation.h>
#include <Profiles/Lev/ANTPLUS_LevPrivateDefines.h>

/* Speed and Distance */
LevSpeedDistanceInformation::LevSpeedDistanceInformation(AntRxDataResponse& dp) : LevBaseMainDataPage(dp) {
    return;
}

uint32_t LevSpeedDistanceInformation::getOdometer() { // in km
    return (uint32_t)getData(1) + ((uint32_t)getData(2) << 8) + ((uint32_t)getData(3) << 16);
}

uint16_t LevSpeedDistanceInformation::getRemainingRange() { // in km
    return (uint16_t)getData(4) + (((uint16_t)getData(5) & 0x0F) << 8);
}

uint16_t LevSpeedDistanceInformation::getSpeed() { // in 1/10 km/h
    return (uint16_t)getData(6) + (((uint16_t)getData(7) & 0x0F) << 8);
}

/* Alt Speed and Distance */
LevAltSpeedDistanceInformation::LevAltSpeedDistanceInformation(AntRxDataResponse& dp) : LevBaseMainDataPage(dp) {
    return;
}

uint32_t LevAltSpeedDistanceInformation::getOdometer() // in km
{
    return (uint32_t)getData(1) + ((uint32_t)getData(2) << 8) + ((uint32_t)getData(3) << 16);
}

uint16_t LevAltSpeedDistanceInformation::getFuelConsumption() // in Wh/km
{
    return (uint16_t)getData(4) + (((uint16_t)getData(5) & 0x0F) << 8);
}

uint16_t LevAltSpeedDistanceInformation::getSpeed() // in 1/10 km/h
{
    return (uint16_t)getData(6) + (((uint16_t)getData(7) & 0x0F) << 8);
}
