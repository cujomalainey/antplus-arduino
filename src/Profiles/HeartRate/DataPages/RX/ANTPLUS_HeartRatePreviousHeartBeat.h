#ifndef ANTPLUS_HEARTRATEPREVIOUSHEARTBEAT_h
#define ANTPLUS_HEARTRATEPREVIOUSHEARTBEAT_h

#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPage.h>
#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBasePreviousHeartBeat.h>

class HeartRatePreviousHeartBeat : public HeartRateBaseMainDataPage, public HeartRateBasePreviousHeartBeat<BroadcastData> {
public:
    HeartRatePreviousHeartBeat(AntRxDataResponse& dp);
};

#endif // ANTPLUS_HEARTRATEPREVIOUSHEARTBEAT_h
