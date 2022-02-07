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

class BicyclePowerCrankTorqueFrequencyMsg :
    public BicyclePowerBaseMainDataPageMsg,
    public BicyclePowerBaseCrankTorqueFrequency<BroadcastDataMsg> {
public:
    BicyclePowerCrankTorqueFrequencyMsg();
    void setSlope(uint16_t slope);
    void setTimeStamp(uint16_t timestamp);
    void setTorqueTicksStamp(uint16_t tickstamp);
};

#endif // ANTPLUS_BICYCLEPOWERCRANKTORQUEFREQUENCY_h
