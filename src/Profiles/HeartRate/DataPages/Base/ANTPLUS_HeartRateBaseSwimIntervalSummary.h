#ifndef ANTPLUS_HEARTRATEBASESWIMINTERVALSUMMARY_h
#define ANTPLUS_HEARTRATEBASESWIMINTERVALSUMMARY_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

template<class T>
class HeartRateBaseSwimIntervalSummary : virtual public CoreDataPage<T> {
public:
    HeartRateBaseSwimIntervalSummary();
    uint8_t getIntervalAverageHeartRate();
    uint8_t getIntervalMaximumHeartRate();
    uint8_t getSessionAverageHeartRate();
};

#endif // ANTPLUS_HEARTRATEBASESWIMINTERVALSUMMARY_h
