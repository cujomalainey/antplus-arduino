#include <Profiles/Lev/DataPages/RX/ANTPLUS_LevSpeedDistanceInformation.h>
#include <Profiles/Lev/ANTPLUS_LevPrivateDefines.h>

/* Speed and Distance */
LevSpeedDistanceInformation::LevSpeedDistanceInformation(AntRxDataResponse& dp) : LevBaseSpeedDistanceInformation(dp) {
    return;
}

uint16_t LevSpeedDistanceInformation::getRemainingRange() { // in km
    return (uint16_t)getData(4) + (((uint16_t)getData(5) & 0x0F) << 8);
}

/* Alt Speed and Distance */
LevAltSpeedDistanceInformation::LevAltSpeedDistanceInformation(AntRxDataResponse& dp) : LevBaseSpeedDistanceInformation(dp) {
    return;
}

uint16_t LevAltSpeedDistanceInformation::getFuelConsumption() // in Wh/km
{
    return (uint16_t)getData(4) + (((uint16_t)getData(5) & 0x0F) << 8);
}

