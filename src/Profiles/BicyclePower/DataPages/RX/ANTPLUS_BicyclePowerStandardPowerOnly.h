#ifndef ANTPLUS_BICYCLEPOWERSTANDARDPOWERONLY_h
#define ANTPLUS_BICYCLEPOWERSTANDARDPOWERONLY_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>

#include "ANT.h"

class BicyclePowerStandardPowerOnly : public BaseDataPage<BroadcastData> {
public:
    BicyclePowerStandardPowerOnly(AntRxDataResponse& dp);
    uint8_t getDataPageNumber();
    uint8_t getUpdateEventCount();
    uint8_t getPedalPower();
    uint8_t getInstantaneousCacence();
    uint16_t getCumulativePowerCount();
    uint16_t getInstataneousPowerCount();
};

#endif // ANTPLUS_BICYCLEPOWERSTANDARDPOWERONLY_h
