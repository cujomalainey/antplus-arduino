#include <Profiles/Lev/DataPages/ANTPLUS_LevBaseSpeedDistanceInformation.h>
#include <Profiles/Lev/ANTPLUS_LevPrivateDefines.h>

#define ODOMETER_LSB_BYTE           1
#define ODOMETER_MSB_BYTE           3
#define LEVSPEED_LSB_BYTE           6
#define LEVSPEED_MSB_BYTE           7
#define LEVSPEED_MASK               0x0FFF

/* Speed and Distance */
LevBaseSpeedDistanceInformation::LevBaseSpeedDistanceInformation(AntRxDataResponse& dp) :
    LevBaseMainDataPage(dp) {}

uint32_t LevBaseSpeedDistanceInformation::getOdometer() { // in km
    return this->get32BitValue(ODOMETER_LSB_BYTE, ODOMETER_MSB_BYTE);
}

uint16_t LevBaseSpeedDistanceInformation::getLevSpeed() // in 1/10 km/h
{
    return this->get16BitValue(LEVSPEED_LSB_BYTE, LEVSPEED_MSB_BYTE,
            LEVSPEED_MASK);
}
