#ifndef ANTPLUS_LEVBASESPEEDDISTANCEINFORMATION_h
#define ANTPLUS_LEVBASESPEEDDISTANCEINFORMATION_h

#include <Profiles/Lev/DataPages/Base/ANTPLUS_LevBaseMainDataPage.h>

class LevBaseSpeedDistanceInformation : public LevBaseMainDataPage {
public:
    LevBaseSpeedDistanceInformation(AntRxDataResponse& dp);
    uint32_t getOdometer(); // in km
};

#endif // ANTPLUS_LEVBASESPEEDDISTANCEINFORMATION_h
