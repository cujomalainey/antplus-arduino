#ifndef ANTPLUS_HEARTRATESWIMINTERVALSUMMARY_h
#define ANTPLUS_HEARTRATESWIMINTERVALSUMMARY_h

#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPage.h>
#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseSwimIntervalSummary.h>

class HeartRateSwimIntervalSummary : public HeartRateBaseMainDataPage, public HeartRateBaseSwimIntervalSummary<BroadcastData> {
public:
    HeartRateSwimIntervalSummary(AntRxDataResponse& dp);
};

#endif // ANTPLUS_HEARTRATESWIMINTERVALSUMMARY_h
