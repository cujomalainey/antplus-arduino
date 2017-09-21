#ifndef ANTPLUS_HEARTRATESWIMINTERVALSUMMARYMSG_h
#define ANTPLUS_HEARTRATESWIMINTERVALSUMMARYMSG_h

#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPageMsg.h>

class HeartRateSwimIntervalSummaryMsg : public HeartRateBaseMainDataPageMsg {
public:
    HeartRateSwimIntervalSummaryMsg();
    uint8_t getIntervalAverageHeartRate();
    uint8_t getIntervalMaximumHeartRate();
    uint8_t getSessionAverageHeartRate();
    void setIntervalAverageHeartRate(uint8_t intervalAverage);
    void setIntervalMaximumHeartRate(uint8_t intervalMaximum);
    void setSessionAverageHeartRate(uint8_t sessionAverage);
};

#endif // ANTPLUS_HEARTRATESWIMINTERVALSUMMARYMSG_h