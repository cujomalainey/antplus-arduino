#ifndef ANTPLUS_HEARTRATEBATTERYSTATUS_h
#define ANTPLUS_HEARTRATEBATTERYSTATUS_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>

#include "ANT.h"

class HeartRateBaseMainDataPage : public HeartRateBatteryStatus {
public:
    uint8_t getBatteryLevel();
    uint8_t getFractionalBatteryVoltage();
    uint8_t getCoarseBatteryVolage();
    uint8_t getBatteryStatus();
}

#endif // ANTPLUS_HEARTRATEBATTERYSTATUS_h