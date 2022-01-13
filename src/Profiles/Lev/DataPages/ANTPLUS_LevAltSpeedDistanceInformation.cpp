#include <Profiles/Lev/DataPages/ANTPLUS_LevAltSpeedDistanceInformation.h>
#include <Profiles/Lev/ANTPLUS_LevPrivateDefines.h>

#define FUELCONSUMPTION_LSB_BYTE  4
#define FUELCONSUMPTION_MSB_BYTE  5
#define FUELCONSUMPTION_MASK      0x0FFF

/* Alt Speed and Distance */
LevAltSpeedDistanceInformation::LevAltSpeedDistanceInformation(AntRxDataResponse& dp) :
    LevBaseSpeedDistanceInformation(dp) {}

uint16_t LevAltSpeedDistanceInformation::getFuelConsumption() // in Wh/km
{
    return this->get16BitValue(FUELCONSUMPTION_LSB_BYTE,
            FUELCONSUMPTION_MSB_BYTE, FUELCONSUMPTION_MASK);
}

