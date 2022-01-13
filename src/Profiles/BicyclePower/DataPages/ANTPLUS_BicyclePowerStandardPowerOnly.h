#ifndef ANTPLUS_BICYCLEPOWERSTANDARDPOWERONLY_h
#define ANTPLUS_BICYCLEPOWERSTANDARDPOWERONLY_h

#include <Profiles/BicyclePower/DataPages/ANTPLUS_BicyclePowerBaseMainDataPage.h>

template<class T>
class BicyclePowerBaseStandardPowerOnly : virtual public CoreDataPage<T> {
public:
    BicyclePowerBaseStandardPowerOnly();
    uint8_t getPedalPower();
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
    void setUpdateEventCount(uint8_t eventCount);
    void setCumulativePowerCount(uint16_t accPower);
    void setInstantaneousPowerCount(uint16_t power);
};

#endif // ANTPLUS_BICYCLEPOWERSTANDARDPOWERONLY_h
