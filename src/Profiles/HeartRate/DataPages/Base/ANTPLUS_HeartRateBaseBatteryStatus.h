#ifndef ANTPLUS_HEARTRATEBASEBATTERYSTATUS_h
#define ANTPLUS_HEARTRATEBASEBATTERYSTATUS_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

template<class T>
class HeartRateBaseBatteryStatus : virtual public CoreDataPage<T> {
public:
    HeartRateBaseBatteryStatus();
    uint8_t getBatteryLevel();
    uint8_t getFractionalBatteryVoltage();
    uint8_t getCoarseBatteryVoltage();
    uint8_t getBatteryStatus();
};

#endif // ANTPLUS_HEARTRATEBASEBATTERYSTATUS_h
