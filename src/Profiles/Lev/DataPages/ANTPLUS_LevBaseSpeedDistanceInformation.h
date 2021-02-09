#ifndef ANTPLUS_LEVBASESPEEDDISTANCEINFORMATION_h
#define ANTPLUS_LEVBASESPEEDDISTANCEINFORMATION_h

#include <Profiles/Lev/DataPages/ANTPLUS_LevBaseMainDataPage.h>

class LevBaseSpeedDistanceInformation : public LevBaseMainDataPage {
public:
    explicit LevBaseSpeedDistanceInformation(AntRxDataResponse& dp);
    uint32_t getOdometer(); // in km
    uint16_t getLevSpeed(); // in 1/10 km/h
};

#endif // ANTPLUS_LEVBASESPEEDDISTANCEINFORMATION_h
