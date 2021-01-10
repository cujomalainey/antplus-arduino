#ifndef ANTPLUS_BICYCLEPOWERBASEPOWERONLY_h
#define ANTPLUS_BICYCLEPOWERBASEPOWERONLY_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

template<class T>
class BicyclePowerBaseStandardPowerOnly : virtual public CoreDataPage<T> {
public:
    BicyclePowerBaseStandardPowerOnly();
    uint8_t getPedalPower();
    uint8_t getInstantaneousCadence();
    uint16_t getAccumulatedPower();
    uint16_t getInstantaneousPower();
};

#endif // ANTPLUS_BICYCLEPOWERBASEPOWERONLY_h
