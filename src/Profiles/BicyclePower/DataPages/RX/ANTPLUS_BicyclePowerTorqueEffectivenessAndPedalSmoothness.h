#ifndef ANTPLUS_BICYCLEPOWERPEDALSMOOTHNESS_h
#define ANTPLUS_BICYCLEPOWERPEDALSMOOTHNESS_h

#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerBaseMainDataPage.h>
#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerBaseTorqueEffectivenessAndPedalSmoothness.h>

class BicyclePowerTorqueEffectivenessAndPedalSmoothness : public BicyclePowerBaseMainDataPage, public BicyclePowerBaseTorqueEffectivenessAndPedalSmoothness<BroadcastData> {
public:
    BicyclePowerTorqueEffectivenessAndPedalSmoothness(AntRxDataResponse& dp);
};

#endif // ANTPLUS_BICYCLEPOWERPEDALSMOOTHNESS_h
