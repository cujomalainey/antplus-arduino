#ifndef ANTPLUS_BICYCLEPOWERSTANDARDCRANKTORQUE_h
#define ANTPLUS_BICYCLEPOWERSTANDARDCRANKTORQUE_h

#include <Profiles/BicyclePower/DataPages/ANTPLUS_BicyclePowerBaseMainDataPage.h>

template<class T>
class BicyclePowerBaseStandardCrankTorque : virtual public CoreDataPage<T> {
public:
    BicyclePowerBaseStandardCrankTorque();
    uint8_t getCrankTicks();
    uint8_t getInstantCadence(); // May not be available, 0xFF indicates invalid
    uint16_t getCrankPeriod();
    uint16_t getAccumulatedTorque();
};

class BicyclePowerStandardCrankTorque : public BicyclePowerBaseMainDataPage, public BicyclePowerBaseStandardCrankTorque<BroadcastData> {
public:
    explicit BicyclePowerStandardCrankTorque(AntRxDataResponse& dp);
};

#endif // ANTPLUS_BICYCLEPOWERSTANDARDCRANKTORQUE_h
