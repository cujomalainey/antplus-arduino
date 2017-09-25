#ifndef ANTPLUS_HEARTRATEBASEMAINDATAPAGE_h
#define ANTPLUS_HEARTRATEBASEMAINDATAPAGE_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>

#include "ANT.h"

class HeartRateBaseMainDataPage : public BaseDataPage<BroadcastData> {
public:
    HeartRateBaseMainDataPage(BroadcastData& dp);
    uint8_t getDataPageNumber();
    uint8_t getPageChangeToggle();
    uint16_t getHeartBeatEventTime();
    uint8_t getHeartBeatCount();
    uint8_t getComputedHeartRate();
};

#endif // ANTPLUS_HEARTRATEBASEMAINDATAPAGE_h