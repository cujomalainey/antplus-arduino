#ifndef ANTPLUS_BICYCLEPOWERBASECUMULITIVEOPERATINGTIME_h
#define ANTPLUS_BICYCLEPOWERBASECUMULITIVEOPERATINGTIME_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

template<class T>
class BicyclePowerBaseCumulativeOperatingTime : virtual public CoreDataPage<T> {
public:
    BicyclePowerBaseCumulativeOperatingTime();
    uint32_t getCumulativeOperatingTime(); // only 24 bits
};

#endif // ANTPLUS_BICYCLEPOWERBASECUMULITIVEOPERATINGTIME_h
