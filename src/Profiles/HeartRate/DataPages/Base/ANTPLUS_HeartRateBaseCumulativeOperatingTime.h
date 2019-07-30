#ifndef ANTPLUS_HEARTRATEBASECUMULITIVEOPERATINGTIME_h
#define ANTPLUS_HEARTRATEBASECUMULITIVEOPERATINGTIME_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

template<class T>
class HeartRateBaseCumulativeOperatingTime : virtual public CoreDataPage<T> {
public:
    HeartRateBaseCumulativeOperatingTime();
    uint32_t getCumulativeOperatingTime(); // only 24 bits
};

#endif // ANTPLUS_HEARTRATEBASECUMULITIVEOPERATINGTIME_h
