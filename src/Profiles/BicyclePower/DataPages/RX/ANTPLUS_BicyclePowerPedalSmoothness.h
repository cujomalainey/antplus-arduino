#ifndef ANTPLUS_BICYCLEPOWERPEDALSMOOTHNESS_h
#define ANTPLUS_BICYCLEPOWERPEDALSMOOTHNESS_h

#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerBaseMainDataPage.h>
#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerBasePedalSmoothness.h>

class BicyclePowerPedalSmoothness : public BicyclePowerBaseMainDataPage, public BicyclePowerBasePedalSmoothness<BroadcastData> {
public:
    BicyclePowerPedalSmoothness(AntRxDataResponse& dp);
};

#endif // ANTPLUS_BICYCLEPOWERPEDALSMOOTHNESS_h
