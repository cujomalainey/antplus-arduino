#ifndef ANTPLUS_HEARTRATEBATTERYSTATUS_h
#define ANTPLUS_HEARTRATEBATTERYSTATUS_h

#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPage.h>

class HeartRateBatteryStatus : public HeartRateBaseMainDataPage {
public:
    HeartRateBatteryStatus(AntRxDataResponse& dp);
    uint8_t getBatteryLevel();
    uint8_t getFractionalBatteryVoltage();
    uint8_t getCoarseBatteryVoltage();
    uint8_t getBatteryStatus();
};

#endif // ANTPLUS_HEARTRATEBATTERYSTATUS_h