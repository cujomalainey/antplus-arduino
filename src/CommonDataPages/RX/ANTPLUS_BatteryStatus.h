#ifndef ANTPLUS_BATTERYSTATUS_h
#define ANTPLUS_BATTERYSTATUS_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>
#include <CommonDataPages/Base/ANTPLUS_BaseBatteryStatus.h>

#include "ANT.h"

// Common page 82

class BatteryStatus : public BaseDataPage<BroadcastData>, public BaseBatteryStatus<BroadcastData> {
public:
    BatteryStatus(AntRxDataResponse& dp);
};

#endif // ANTPLUS_BATTERYSTATUS_h
