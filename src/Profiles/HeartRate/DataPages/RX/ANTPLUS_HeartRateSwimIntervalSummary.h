#ifndef ANTPLUS_HEARTRATESWIMINTERVALSUMMARY_h
#define ANTPLUS_HEARTRATESWIMINTERVALSUMMARY_h

#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPage.h>

class HeartRateSwimIntervalSummary : public HeartRateBaseMainDataPage {
public:
    HeartRateSwimIntervalSummary(AntRxDataResponse& dp);
    uint8_t getIntervalAverageHeartRate();
    uint8_t getIntervalMaximumHeartRate();
    uint8_t getSessionAverageHeartRate();
};

#endif // ANTPLUS_HEARTRATESWIMINTERVALSUMMARY_h