#ifndef ANTPLUS_HEARTRATEBASECAPABILITIES_h
#define ANTPLUS_HEARTRATEBASECAPABILITIES_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

template<class T>
class HeartRateBaseCapabilities : virtual public CoreDataPage<T> {
public:
    HeartRateBaseCapabilities();
    uint8_t getFeaturesSupported();
    uint8_t getFeaturesEnabled();
};

#endif // ANTPLUS_HEARTRATEBASECAPABILITIES_h
