#ifndef ANTPLUS_HEARTRATECUMULITIVEOPERATINGTIMEMSG_h
#define ANTPLUS_HEARTRATECUMULITIVEOPERATINGTIMEMSG_h

#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPageMsg.h>
#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseCumulativeOperatingTime.h>

class HeartRateCumulativeOperatingTimeMsg : public HeartRateBaseMainDataPageMsg, public HeartRateBaseCumulativeOperatingTime<BroadcastDataMsg> {
public:
    HeartRateCumulativeOperatingTimeMsg();
    void setCumulativeOperatingTime(uint32_t time);
};

#endif // ANTPLUS_HEARTRATECUMULITIVEOPERATINGTIMEMSG_h
