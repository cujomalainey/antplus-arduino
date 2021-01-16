#ifndef ANTPLUS_BICYCLEPOWERSTANDARDPOWERONLY_h
#define ANTPLUS_BICYCLEPOWERSTANDARDPOWERONLY_h

#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerBaseMainDataPage.h>
#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerBaseStandardPowerOnly.h>

class BicyclePowerStandardPowerOnly : public BicyclePowerBaseMainDataPage, public BicyclePowerBaseStandardPowerOnly<BroadcastData> {
public:
    explicit BicyclePowerStandardPowerOnly(AntRxDataResponse& dp);
};

#endif // ANTPLUS_BICYCLEPOWERSTANDARDPOWERONLY_h


