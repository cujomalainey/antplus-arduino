#include <Profiles/Lev/DataPages/Base/ANTPLUS_LevBaseSpeedDistanceInformation.h>
#include <Profiles/Lev/ANTPLUS_LevPrivateDefines.h>

/* Speed and Distance */
LevBaseSpeedDistanceInformation::LevBaseSpeedDistanceInformation(AntRxDataResponse& dp) : LevBaseMainDataPage(dp) {
}

uint32_t LevBaseSpeedDistanceInformation::getOdometer() { // in km
    return (uint32_t)getData(1) + ((uint32_t)getData(2) << 8) + ((uint32_t)getData(3) << 16);
}

uint16_t LevBaseSpeedDistanceInformation::getSpeed() // in 1/10 km/h
{
    return (uint16_t)getData(6) + (((uint16_t)getData(7) & 0x0F) << 8);
}
