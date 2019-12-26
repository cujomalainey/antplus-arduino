#ifndef ANTPLUS_BICYCLESPEEDCUMULITIVEOPERATINGTIME_h
#define ANTPLUS_BICYCLESPEEDCUMULITIVEOPERATINGTIME_h

#include <Profiles/BicycleSpeed/DataPages/Base/ANTPLUS_BicycleSpeedBaseMainDataPage.h>
#include <Profiles/BicycleSpeed/DataPages/Base/ANTPLUS_BicycleSpeedBaseCumulativeOperatingTime.h>

class BicycleSpeedCumulativeOperatingTime : public BicycleSpeedBaseMainDataPage, public BicycleSpeedBaseCumulativeOperatingTime<BroadcastData> {
public:
    BicycleSpeedCumulativeOperatingTime(AntRxDataResponse& dp);
};

#endif // ANTPLUS_BICYCLESPEEDCUMULITIVEOPERATINGTIME_h
