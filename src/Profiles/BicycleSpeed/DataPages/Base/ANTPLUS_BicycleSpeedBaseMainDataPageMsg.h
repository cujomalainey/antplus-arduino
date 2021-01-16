#ifndef ANTPLUS_HEARTRATEBASEMAINDATAPAGEMSG_h
#define ANTPLUS_HEARTRATEBASEMAINDATAPAGEMSG_h

#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>

#include "ANT.h"

class BicycleSpeedBaseMainDataPageMsg : public BaseDataPageMsg<BroadcastDataMsg> {
public:
    explicit BicycleSpeedBaseMainDataPageMsg(uint8_t dataPageNumber);
    uint8_t getPageChangeToggle();
    uint16_t getBikeSpeedEventTime();
    uint16_t getCumulativeSpeedRevolutionCount();
    void setPageChangeToggle(uint8_t toggle);
    void setBikeSpeedEventTime(uint16_t time);
    void setCumulativeSpeedRevolutionCount(uint16_t count);
protected:
    uint8_t _buffer[MESSAGE_SIZE];
};

#endif // ANTPLUS_HEARTRATEBASEMAINDATAPAGEMSG_h
