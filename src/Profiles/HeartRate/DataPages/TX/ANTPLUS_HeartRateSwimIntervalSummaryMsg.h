#ifndef ANTPLUS_HEARTRATESWIMINTERVALSUMMARYMSG_h
#define ANTPLUS_HEARTRATESWIMINTERVALSUMMARYMSG_h

#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPageMsg.h>
#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseSwimIntervalSummary.h>

class HeartRateSwimIntervalSummaryMsg : public HeartRateBaseMainDataPageMsg, public HeartRateBaseSwimIntervalSummary<BroadcastDataMsg> {
public:
    HeartRateSwimIntervalSummaryMsg();
    void setIntervalAverageHeartRate(uint8_t intervalAverage);
    void setIntervalMaximumHeartRate(uint8_t intervalMaximum);
    void setSessionAverageHeartRate(uint8_t sessionAverage);
};

#endif // ANTPLUS_HEARTRATESWIMINTERVALSUMMARYMSG_h
