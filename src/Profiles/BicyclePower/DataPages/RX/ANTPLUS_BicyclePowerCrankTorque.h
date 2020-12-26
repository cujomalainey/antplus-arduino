#ifndef ANTPLUS_BICYCLEPOWERCRANKTORQUE_h
#define ANTPLUS_BICYCLEPOWERCRANKTORQUE_h

#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerBaseMainDataPage.h>
#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerBaseCrankTorque.h>

class BicyclePowerCrankTorque : public BicyclePowerBaseMainDataPage, public BicyclePowerBaseCrankTorque<BroadcastData> {
public:
    BicyclePowerCrankTorque(AntRxDataResponse& dp);
};

#endif // ANTPLUS_BICYCLEPOWERCRANKTORQUE_h
