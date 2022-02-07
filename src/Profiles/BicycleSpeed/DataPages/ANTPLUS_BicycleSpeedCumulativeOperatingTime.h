#ifndef ANTPLUS_BICYCLESPEEDCUMULITIVEOPERATINGTIME_h
#define ANTPLUS_BICYCLESPEEDCUMULITIVEOPERATINGTIME_h

#include <Profiles/BicycleSpeed/DataPages/ANTPLUS_BicycleSpeedBaseMainDataPage.h>

template<class T>
class BicycleSpeedBaseCumulativeOperatingTime : virtual public CoreDataPage<T> {
public:
    BicycleSpeedBaseCumulativeOperatingTime();
    uint32_t getCumulativeOperatingTime(); // only 24 bits
};

class BicycleSpeedCumulativeOperatingTime : public BicycleSpeedBaseMainDataPage, public BicycleSpeedBaseCumulativeOperatingTime<BroadcastData> {
public:
    explicit BicycleSpeedCumulativeOperatingTime(AntRxDataResponse& dp);
};

#endif // ANTPLUS_BICYCLESPEEDCUMULITIVEOPERATINGTIME_h
