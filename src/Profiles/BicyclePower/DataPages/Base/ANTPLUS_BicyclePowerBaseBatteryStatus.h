#ifndef ANTPLUS_BICYCLEPOWERBASEBATTERYSTATUS_h
#define ANTPLUS_BICYCLEPOWERBASEBATTERYSTATUS_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

template<class T>
class BicyclePowerBaseBatteryStatus : virtual public CoreDataPage<T> {
public:
    BicyclePowerBaseBatteryStatus();
    uint8_t getFractionalBatteryVoltage();
    uint8_t getCoarseBatteryVoltage();
    uint8_t getBatteryStatus();
};

#endif // ANTPLUS_BICYCLEPOWERBASEBATTERYSTATUS_h
