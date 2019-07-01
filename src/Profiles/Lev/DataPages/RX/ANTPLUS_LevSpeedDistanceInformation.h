#ifndef ANTPLUS_LEVSPEEDDISTANCEINFORMATION_h
#define ANTPLUS_LEVSPEEDDISTANCEINFORMATION_h

#include <Profiles/Lev/DataPages/Base/ANTPLUS_LevBaseSpeedDistanceInformation.h>

class LevSpeedDistanceInformation : public LevBaseSpeedDistanceInformation {
public:
    LevSpeedDistanceInformation(AntRxDataResponse& dp);
    uint16_t getRemainingRange(); // in km
    uint16_t getSpeed();     // in 1/10 km/h
};


class LevAltSpeedDistanceInformation : public LevBaseSpeedDistanceInformation {
public:
    LevAltSpeedDistanceInformation(AntRxDataResponse& dp);
    uint16_t getFuelConsumption(); // in Wh/km
    uint16_t getSpeed();     // in 1/10 km/h
};

#endif // ANTPLUS_LEVSPEEDDISTANCEINFORMATION_h
