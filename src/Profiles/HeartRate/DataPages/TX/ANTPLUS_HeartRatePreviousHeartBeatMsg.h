#ifndef ANTPLUS_HEARTRATEPREVIOUSHEARTBEATMSG_h
#define ANTPLUS_HEARTRATEPREVIOUSHEARTBEATMSG_h

#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPageMsg.h>

class HeartRatePreviousHeartBeatMsg : public HeartRateBaseMainDataPageMsg {
public:
    HeartRatePreviousHeartBeatMsg();
    uint8_t getManufacturerSpecific();
    uint16_t getPreviousHeartBeatEventTime();
    void setManufacturerSpecific(uint8_t specificByte);
    void setPreviousHeartBeatEventTime(uint16_t eventTime);
};

#endif // ANTPLUS_HEARTRATEPREVIOUSHEARTBEATMSG_h