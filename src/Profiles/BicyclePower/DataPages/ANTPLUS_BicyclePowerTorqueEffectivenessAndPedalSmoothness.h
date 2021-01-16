#ifndef ANTPLUS_BICYCLEPOWERPEDALSMOOTHNESS_h
#define ANTPLUS_BICYCLEPOWERPEDALSMOOTHNESS_h

#include <Profiles/BicyclePower/DataPages/ANTPLUS_BicyclePowerBaseMainDataPage.h>

template<class T>
class BicyclePowerBaseTorqueEffectivenessAndPedalSmoothness : virtual public CoreDataPage<T> {
public:
    BicyclePowerBaseTorqueEffectivenessAndPedalSmoothness();
    uint8_t getLeftTorqueEffectiveness();
    uint8_t getRightTorqueEffectiveness();
    uint8_t getLeftPedalSmoothness();
    uint8_t getRightPedalSmoothness();
};

class BicyclePowerTorqueEffectivenessAndPedalSmoothness : public BicyclePowerBaseMainDataPage, public BicyclePowerBaseTorqueEffectivenessAndPedalSmoothness<BroadcastData> {
public:
    explicit BicyclePowerTorqueEffectivenessAndPedalSmoothness(AntRxDataResponse& dp);
};

#endif // ANTPLUS_BICYCLEPOWERPEDALSMOOTHNESS_h
