#ifndef ANTPLUS_BICYCLEPOWERCRANKTORQUEFREQUENCY_h
#define ANTPLUS_BICYCLEPOWERCRANKTORQUEFREQUENCY_h

#include <Profiles/BicyclePower/DataPages/ANTPLUS_BicyclePowerBaseMainDataPage.h>

template<class T>
class BicyclePowerBaseCrankTorqueFrequency : virtual public CoreDataPage<T> {
public:
    BicyclePowerBaseCrankTorqueFrequency();
    uint16_t getSlope();
    uint16_t getTimeStamp();
    uint16_t getTorqueTicksStamp();
};

class BicyclePowerCrankTorqueFrequency :
    public BicyclePowerBaseMainDataPage,
    public BicyclePowerBaseCrankTorqueFrequency<BroadcastData> {
public:
    explicit BicyclePowerCrankTorqueFrequency(AntRxDataResponse& dp);
};

#endif // ANTPLUS_BICYCLEPOWERCRANKTORQUEFREQUENCY_h
