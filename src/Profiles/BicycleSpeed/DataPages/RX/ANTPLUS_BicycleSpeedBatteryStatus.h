#ifndef ANTPLUS_BICYCLESPEEDBATTERYSTATUS_h
#define ANTPLUS_BICYCLESPEEDBATTERYSTATUS_h

#include <Profiles/BicycleSpeed/DataPages/Base/ANTPLUS_BicycleSpeedBaseMainDataPage.h>
#include <Profiles/BicycleSpeed/DataPages/Base/ANTPLUS_BicycleSpeedBaseBatteryStatus.h>

class BicycleSpeedBatteryStatus : public BicycleSpeedBaseMainDataPage, public BicycleSpeedBaseBatteryStatus<BroadcastData> {
public:
    BicycleSpeedBatteryStatus(AntRxDataResponse& dp);
};

#endif // ANTPLUS_BICYCLESPEEDBATTERYSTATUS_h
