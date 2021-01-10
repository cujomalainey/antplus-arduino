#ifndef ANTPLUS_BICYCLEPOWERPOWERONLY_h
#define ANTPLUS_BICYCLEPOWERPOWERONLY_h

#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerBaseMainDataPage.h>
#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerBasePowerOnly.h>

class BicyclePowerPowerOnly : public BicyclePowerBaseMainDataPage, public BicyclePowerBasePowerOnly<BroadcastData> {
public:
    BicyclePowerPowerOnly(AntRxDataResponse& dp);
};

#endif // ANTPLUS_BICYCLEPOWERPOWERONLY_h
