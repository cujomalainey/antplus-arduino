#ifndef ANTPLUS_HEARTRATESWIMINTERVALSUMMARY_h
#define ANTPLUS_HEARTRATESWIMINTERVALSUMMARY_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>
#include <Profiles/HeartRate/DataPages/ANTPLUS_HeartRateBaseMainDataPage.h>

template<class T>
class HeartRateBaseSwimIntervalSummary : virtual public CoreDataPage<T> {
public:
    HeartRateBaseSwimIntervalSummary();
    uint8_t getIntervalAverageHeartRate();
    uint8_t getIntervalMaximumHeartRate();
    uint8_t getSessionAverageHeartRate();
};

class HeartRateSwimIntervalSummary : public HeartRateBaseMainDataPage, public HeartRateBaseSwimIntervalSummary<BroadcastData> {
public:
    explicit HeartRateSwimIntervalSummary(AntRxDataResponse& dp);
};

class HeartRateSwimIntervalSummaryMsg : public HeartRateBaseMainDataPageMsg, public HeartRateBaseSwimIntervalSummary<BroadcastDataMsg> {
public:
    HeartRateSwimIntervalSummaryMsg();
    void setIntervalAverageHeartRate(uint8_t intervalAverage);
    void setIntervalMaximumHeartRate(uint8_t intervalMaximum);
    void setSessionAverageHeartRate(uint8_t sessionAverage);
};

#endif // ANTPLUS_HEARTRATESWIMINTERVALSUMMARY_h
