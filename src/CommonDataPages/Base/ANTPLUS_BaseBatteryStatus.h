#ifndef ANTPLUS_BASEBATTERYSTATUS_h
#define ANTPLUS_BASEBATTERYSTATUS_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

// Common page 82

template<class T>
class BaseBatteryStatus : virtual public CoreDataPage<T> {
public:
    BaseBatteryStatus();
    uint8_t getNumberOfBatteries();
    uint8_t getBatteryIdentifier();
    uint32_t getCumulativeOperatingTime();
    uint8_t getFractionalBatteryVoltage();
    uint8_t getCoarseBatteryVoltage();
    uint8_t getBatteryStatus();
    uint8_t getCumulativeOperatingTimeResolution();
};

#endif // ANTPLUS_BASEBATTERYSTATUS_h
