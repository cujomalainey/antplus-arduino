#ifndef ANTPLUS_HEARTRATECUMULITIVEOPERATINGTIME_h
#define ANTPLUS_HEARTRATECUMULITIVEOPERATINGTIME_h

#include <Profiles/HeartRate/DataPages/ANTPLUS_HeartRateBaseMainDataPage.h>

template<class T>
class HeartRateBaseCumulativeOperatingTime : virtual public CoreDataPage<T> {
public:
    HeartRateBaseCumulativeOperatingTime();
    uint32_t getCumulativeOperatingTime(); // only 24 bits
};

class HeartRateCumulativeOperatingTime : public HeartRateBaseMainDataPage, public HeartRateBaseCumulativeOperatingTime<BroadcastData> {
public:
    explicit HeartRateCumulativeOperatingTime(AntRxDataResponse& dp);
};

class HeartRateCumulativeOperatingTimeMsg : public HeartRateBaseMainDataPageMsg, public HeartRateBaseCumulativeOperatingTime<BroadcastDataMsg> {
public:
    HeartRateCumulativeOperatingTimeMsg();
    void setCumulativeOperatingTime(uint32_t time);
};

#endif // ANTPLUS_HEARTRATECUMULITIVEOPERATINGTIME_h
