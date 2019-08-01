#ifndef ANTPLUS_HEARTRATEPREVIOUSHEARTBEATMSG_h
#define ANTPLUS_HEARTRATEPREVIOUSHEARTBEATMSG_h

#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPageMsg.h>
#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBasePreviousHeartBeat.h>

class HeartRatePreviousHeartBeatMsg : public HeartRateBaseMainDataPageMsg, public HeartRateBasePreviousHeartBeat<BroadcastDataMsg> {
public:
    HeartRatePreviousHeartBeatMsg();
    void setManufacturerSpecific(uint8_t specificByte);
    void setPreviousHeartBeatEventTime(uint16_t eventTime);
};

#endif // ANTPLUS_HEARTRATEPREVIOUSHEARTBEATMSG_h
