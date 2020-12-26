#ifndef ANTPLUS_BICYCLEPOWERBASEPOWERONLY_h
#define ANTPLUS_BICYCLEPOWERBASEPOWERONLY_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

template<class T>
class BicyclePowerBasePowerOnly : virtual public CoreDataPage<T> {
public:
    BicyclePowerBasePowerOnly();
    uint8_t getPedalBalance();
    uint8_t getInstantCadence();
    uint16_t getAccumulatedPower();
    uint16_t getInstantPower();
};

#endif // ANTPLUS_BICYCLEPOWERBASEPOWERONLY_h
