#ifndef ANTPLUS_BIKEPOWERSTANDARDPOWERONLYMSG_h
#define ANTPLUS_BIKEPOWERSTANDARDPOWERONLYMSG_h

#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>

#include "ANT.h"

class BicyclePowerStandardPowerOnlyMsg : public BaseDataPageMsg<BroadcastDataMsg> {
public:
    BicyclePowerStandardPowerOnlyMsg(void);
    void setUpdateEventCount(uint8_t eventCount);
    void setCumulativePowerCount(uint16_t accPower);
    void setInstataneousPowerCount(uint16_t power);
protected:
    uint8_t _buffer[MESSAGE_SIZE];
};

#endif // ANTPLUS_BIKEPOWERSTANDARDPOWERONLYMSG_h
