#ifndef ANTPLUS_HEARTRATEBASEMAINDATAPAGEMSG_h
#define ANTPLUS_HEARTRATEBASEMAINDATAPAGEMSG_h

#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>

#include "ANT.h"

class HeartRateBaseMainDataPageMsg : public BaseDataPageMsg<BroadcastDataMsg> {
public:
    HeartRateBaseMainDataPageMsg(uint8_t dataPageNumber);
    uint8_t getPageChangeToggle();
    uint16_t getHeartBeatEventTime();
    uint8_t getHeartBeatCount();
    uint8_t getComputedHeartRate();
    void setPageChangeToggle(uint8_t toggle);
    void setHeartBeatEventTime(uint16_t time);
    void setHeartBeatCount(uint8_t count);
    void setComputedHeartRate(uint8_t heartRate);
protected:
    uint8_t _buffer[MESSAGE_SIZE];
};

#endif // ANTPLUS_HEARTRATEBASEMAINDATAPAGEMSG_h