#ifndef ANTPLUS_ENVIRONMENTBASETEMPERATURE_h
#define ANTPLUS_ENVIRONMENTBASETEMPERATURE_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

template<class T>
class EnvironmentBaseTemperature : virtual public CoreDataPage<T> {
public:
    EnvironmentBaseTemperature();
    uint8_t getEventCount();
    int16_t get24HourLow();
    int16_t get24HourHigh();
    int16_t getCurrentTemp();
};

#endif // ANTPLUS_ENVIRONMENTBASETEMPERATURE_h
