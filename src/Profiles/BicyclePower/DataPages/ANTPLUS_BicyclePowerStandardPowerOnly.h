#ifndef ANTPLUS_BICYCLEPOWERSTANDARDPOWERONLY_h
#define ANTPLUS_BICYCLEPOWERSTANDARDPOWERONLY_h

#include <Profiles/BicyclePower/DataPages/ANTPLUS_BicyclePowerBaseMainDataPage.h>

template<class T>
class BicyclePowerBaseStandardPowerOnly : virtual public CoreDataPage<T> {
public:
    BicyclePowerBaseStandardPowerOnly();
    uint8_t getPedalPower();
    uint8_t getPedalDifferentiation();
    uint8_t getInstantaneousCadence();
    uint16_t getAccumulatedPower();
    uint16_t getInstantaneousPower();
};

class BicyclePowerStandardPowerOnly : public BicyclePowerBaseMainDataPage, public BicyclePowerBaseStandardPowerOnly<BroadcastData> {
public:
    explicit BicyclePowerStandardPowerOnly(AntRxDataResponse& dp);
};

class BicyclePowerStandardPowerOnlyMsg : public BicyclePowerBaseMainDataPageMsg, public BicyclePowerBaseStandardPowerOnly<BroadcastDataMsg> {
public:
    BicyclePowerStandardPowerOnlyMsg(void);
    void setPedalPower(uint8_t pedalPower);
    void setPedalDifferentiation(uint8_t differentiation);
    void setInstantaneousCadence(uint8_t cadence);
    void setAccumulatedPower(uint16_t accPower);
    void setInstantaneousPower(uint16_t instantaneousPower);
};

#endif // ANTPLUS_BICYCLEPOWERSTANDARDPOWERONLY_h
