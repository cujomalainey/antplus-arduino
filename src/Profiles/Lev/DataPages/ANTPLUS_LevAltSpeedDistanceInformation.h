#ifndef ANTPLUS_LEVALTSPEEDDISTANCEINFORMATION_h
#define ANTPLUS_LEVALTSPEEDDISTANCEINFORMATION_h

#include <Profiles/Lev/DataPages/ANTPLUS_LevBaseSpeedDistanceInformation.h>

class LevAltSpeedDistanceInformation : public LevBaseSpeedDistanceInformation {
public:
    explicit LevAltSpeedDistanceInformation(AntRxDataResponse& dp);
    uint16_t getFuelConsumption(); // in Wh/km
};

#endif // ANTPLUS_LEVALTSPEEDDISTANCEINFORMATION_h
