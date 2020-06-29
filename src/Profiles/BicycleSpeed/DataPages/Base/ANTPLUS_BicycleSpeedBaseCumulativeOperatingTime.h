#ifndef ANTPLUS_BICYCLESPEEDBASECUMULITIVEOPERATINGTIME_h
#define ANTPLUS_BICYCLESPEEDBASECUMULITIVEOPERATINGTIME_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

template<class T>
class BicycleSpeedBaseCumulativeOperatingTime : virtual public CoreDataPage<T> {
public:
    BicycleSpeedBaseCumulativeOperatingTime();
    uint32_t getCumulativeOperatingTime(); // only 24 bits
};

#endif // ANTPLUS_BICYCLESPEEDBASECUMULITIVEOPERATINGTIME_h
