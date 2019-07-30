#ifndef ANTPLUS_HEARTRATECUMULITIVEOPERATINGTIME_h
#define ANTPLUS_HEARTRATECUMULITIVEOPERATINGTIME_h

#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPage.h>
#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseCumulativeOperatingTime.h>

class HeartRateCumulativeOperatingTime : public HeartRateBaseMainDataPage, HeartRateBaseCumulativeOperatingTime<BroadcastData> {
public:
    HeartRateCumulativeOperatingTime(AntRxDataResponse& dp);
};

#endif // ANTPLUS_HEARTRATECUMULITIVEOPERATINGTIME_h
