#include <Profiles/Lev/DataPages/ANTPLUS_LevSpeedDistanceInformation.h>
#include <Profiles/Lev/ANTPLUS_LevPrivateDefines.h>

#define REMAININGRANGE_LSB_BYTE  4
#define REMAININGRANGE_MSB_BYTE  5
#define REMAININGRANGE_MASK      0x0FFF

/* Speed and Distance */
LevSpeedDistanceInformation::LevSpeedDistanceInformation(AntRxDataResponse& dp) :
    LevBaseSpeedDistanceInformation(dp) {}

uint16_t LevSpeedDistanceInformation::getRemainingRange() { // in km
    return this->get16BitValue(REMAININGRANGE_LSB_BYTE, REMAININGRANGE_MSB_BYTE,
            REMAININGRANGE_MASK);
}
