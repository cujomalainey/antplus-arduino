#ifndef ANTPLUS_BIKEPOWERSTDPOWERONLYDATAPAGEMSG_h
#define ANTPLUS_BIKEPOWERSTDPOWERONLYDATAPAGEMSG_h

#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>

#include "ANT.h"

class BicyclePowerStdPowerOnlyDataPageMsg : public BaseDataPageMsg<BroadcastDataMsg> {
public:
    BicyclePowerStdPowerOnlyDataPageMsg(void);
    void setUpdateEventCount(uint8_t eventCount);
    void setCumulativePowerCount(uint16_t accPower);
    void setInstataneousPowerCount(uint16_t power);
protected:
    uint8_t _buffer[MESSAGE_SIZE];
};

#endif // ANTPLUS_BIKEPOWERSTDPOWERONLYDATAPAGEMSG_h
