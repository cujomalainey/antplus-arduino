#ifndef ANTPLUS_HEARTRATEBATTERYSTATUS_h
#define ANTPLUS_HEARTRATEBATTERYSTATUS_h

#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPage.h>
#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseBatteryStatus.h>

class HeartRateBatteryStatus : public HeartRateBaseMainDataPage, public HeartRateBaseBatteryStatus<BroadcastData> {
public:
    explicit HeartRateBatteryStatus(AntRxDataResponse& dp);
};

#endif // ANTPLUS_HEARTRATEBATTERYSTATUS_h
