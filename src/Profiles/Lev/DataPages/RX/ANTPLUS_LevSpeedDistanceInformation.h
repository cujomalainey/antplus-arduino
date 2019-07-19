#ifndef ANTPLUS_LEVSPEEDDISTANCEINFORMATION_h
#define ANTPLUS_LEVSPEEDDISTANCEINFORMATION_h

#include <Profiles/Lev/DataPages/Base/ANTPLUS_LevBaseSpeedDistanceInformation.h>

class LevSpeedDistanceInformation : public LevBaseSpeedDistanceInformation {
public:
    LevSpeedDistanceInformation(AntRxDataResponse& dp);
    uint16_t getRemainingRange(); // in km
};


class LevAltSpeedDistanceInformation : public LevBaseSpeedDistanceInformation {
public:
    LevAltSpeedDistanceInformation(AntRxDataResponse& dp);
    uint16_t getFuelConsumption(); // in Wh/km
};

#endif // ANTPLUS_LEVSPEEDDISTANCEINFORMATION_h
