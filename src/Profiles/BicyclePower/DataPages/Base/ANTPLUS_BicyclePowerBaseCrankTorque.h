#ifndef ANTPLUS_BICYCLEPOWERBASECRANKTORQUE_h
#define ANTPLUS_BICYCLEPOWERBASECRANKTORQUE_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

template<class T>
class BicyclePowerBaseCrankTorque : virtual public CoreDataPage<T> {
public:
    BicyclePowerBaseCrankTorque();
    uint8_t getCrankTicks();
    uint8_t getInstantCadence(); // May not be available, 0xFF indicates invalid
    uint16_t getCrankPeriod();
    uint16_t getAccumulatedTorque();
};

#endif // ANTPLUS_BICYCLEPOWERBASECRANKTORQUE_h
