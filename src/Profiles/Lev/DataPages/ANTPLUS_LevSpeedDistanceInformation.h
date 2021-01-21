#ifndef ANTPLUS_LEVSPEEDDISTANCEINFORMATION_h
#define ANTPLUS_LEVSPEEDDISTANCEINFORMATION_h

#include <Profiles/Lev/DataPages/ANTPLUS_LevBaseSpeedDistanceInformation.h>

class LevSpeedDistanceInformation : public LevBaseSpeedDistanceInformation {
public:
    LevSpeedDistanceInformation(AntRxDataResponse& dp);
    uint16_t getRemainingRange(); // in km
};

#endif // ANTPLUS_LEVSPEEDDISTANCEINFORMATION_h
