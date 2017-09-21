#ifndef ANTPLUS_HEARTRATECUMULITIVEOPERATINGTIMEMSG_h
#define ANTPLUS_HEARTRATECUMULITIVEOPERATINGTIMEMSG_h

#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPageMsg.h>

class HeartRateCumulativeOperatingTimeMsg : public HeartRateBaseMainDataPageMsg {
public:
    HeartRateCumulativeOperatingTimeMsg();
    uint32_t getCumulativeOperatingTime();
    void setCumulativeOperatingTime(uint32_t time);
};

#endif // ANTPLUS_HEARTRATECUMULITIVEOPERATINGTIMEMSG_h