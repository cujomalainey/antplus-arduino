#ifndef ANTPLUS_BICYCLEPOWERBASEMAINDATAPAGE_h
#define ANTPLUS_BICYCLEPOWERBASEMAINDATAPAGE_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>

#include "ANT.h"

class BicyclePowerStdPowerOnlyDataPage : public BaseDataPage<BroadcastData> {
public:
    BicyclePowerStdPowerOnlyDataPage(AntRxDataResponse& dp);
    uint8_t getDataPageNumber();
    uint8_t getUpdateEventCount();
    uint8_t getPedalPower();
    uint8_t getInstantaneousCacence();
    uint16_t getCumulativePowerCount();
    uint16_t getInstataneousPowerCount();
};

#endif // ANTPLUS_BICYCLEPOWERBASEMAINDATAPAGE_h
