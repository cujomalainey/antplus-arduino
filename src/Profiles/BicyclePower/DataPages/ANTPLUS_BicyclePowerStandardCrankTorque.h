#ifndef ANTPLUS_BICYCLEPOWERSTANDARDCRANKTORQUE_h
#define ANTPLUS_BICYCLEPOWERSTANDARDCRANKTORQUE_h

#include <Profiles/BicyclePower/DataPages/ANTPLUS_BicyclePowerBaseMainDataPage.h>

template<class T>
class BicyclePowerBaseStandardCrankTorque : virtual public CoreDataPage<T> {
public:
    BicyclePowerBaseStandardCrankTorque();
    uint8_t getCrankTicks();
    uint8_t getInstantaneousCadence();
    uint16_t getCrankPeriod();
    uint16_t getAccumulatedTorque();
};

class BicyclePowerStandardCrankTorque :
    public BicyclePowerBaseMainDataPage,
    public BicyclePowerBaseStandardCrankTorque<BroadcastData> {
public:
    explicit BicyclePowerStandardCrankTorque(AntRxDataResponse& dp);
};

class BicyclePowerStandardCrankTorqueMsg :
    public BicyclePowerBaseMainDataPageMsg,
    public BicyclePowerBaseStandardCrankTorque<BroadcastDataMsg> {
public:
    BicyclePowerStandardCrankTorqueMsg();
    void setCrankTicks(uint8_t ticks);
    void setInstantaneousCadence(uint8_t cadence);
    void setCrankPeriod(uint16_t period);
    void setAccumulatedTorque(uint16_t torque);
};

#endif // ANTPLUS_BICYCLEPOWERSTANDARDCRANKTORQUE_h
