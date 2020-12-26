#ifndef ANTPLUS_BICYCLEPOWERBATTERYSTATUS_h
#define ANTPLUS_BICYCLEPOWERBATTERYSTATUS_h

#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerBaseMainDataPage.h>
#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerBaseBatteryStatus.h>

class BicyclePowerBatteryStatus : public BicyclePowerBaseMainDataPage, public BicyclePowerBaseBatteryStatus<BroadcastData> {
public:
    BicyclePowerBatteryStatus(AntRxDataResponse& dp);
};

#endif // ANTPLUS_BICYCLEPOWERBATTERYSTATUS_h
