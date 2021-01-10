#ifndef ANTPLUS_BICYCLEPOWERSTANDARDCRANKTORQUE_h
#define ANTPLUS_BICYCLEPOWERSTANDARDCRANKTORQUE_h

#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerBaseMainDataPage.h>
#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerBaseStandardCrankTorque.h>

class BicyclePowerStandardCrankTorque : public BicyclePowerBaseMainDataPage, public BicyclePowerBaseStandardCrankTorque<BroadcastData> {
public:
    BicyclePowerStandardCrankTorque(AntRxDataResponse& dp);
};

#endif // ANTPLUS_BICYCLEPOWERSTANDARDCRANKTORQUE_h
