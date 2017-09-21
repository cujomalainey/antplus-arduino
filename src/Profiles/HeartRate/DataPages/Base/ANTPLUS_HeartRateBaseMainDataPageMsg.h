#ifndef ANTPLUS_HEARTRATEBASEMAINDATAPAGEMSG_h
#define ANTPLUS_HEARTRATEBASEMAINDATAPAGEMSG_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>

#include "ANT.h"

class HeartRateBaseMainDataPageMsg : public BaseDataPage, public BroadcastDataMsg {
public:
    HeartRateBaseMainDataPageMsg();
    uint8_t getPageChangeToggle();
    uint16_t getHeartBeatEventTime();
    uint8_t getHeartBeatCount();
    uint8_t getComputedHeartRate();
    void setPageChangeToggle(uint8_t toggle);
    void setHeartBeatEventTime(uint16_t time);
    void setHeartBeatCount(uint8_t count);
    void setComputedHeartRate(uint8_t heartRate);
};

#endif // ANTPLUS_HEARTRATEBASEMAINDATAPAGEMSG_h