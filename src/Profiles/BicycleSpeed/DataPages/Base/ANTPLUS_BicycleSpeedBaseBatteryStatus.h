#ifndef ANTPLUS_BICYCLESPEEDBASEBATTERYSTATUS_h
#define ANTPLUS_BICYCLESPEEDBASEBATTERYSTATUS_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

template<class T>
class BicycleSpeedBaseBatteryStatus : virtual public CoreDataPage<T> {
public:
    BicycleSpeedBaseBatteryStatus();
    uint8_t getFractionalBatteryVoltage();
    uint8_t getCoarseBatteryVoltage();
    uint8_t getBatteryStatus();
};

#endif // ANTPLUS_BICYCLESPEEDBASEBATTERYSTATUS_h
