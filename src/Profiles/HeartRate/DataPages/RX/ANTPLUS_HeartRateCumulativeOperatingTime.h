#ifndef ANTPLUS_HEARTRATECUMULITIVEOPERATINGTIME_h
#define ANTPLUS_HEARTRATECUMULITIVEOPERATINGTIME_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>

#include "ANT.h"

class HeartRateCumulativeOperatingTime : public HeartRateBaseMainDataPage {
public:
    HeartRateCumulativeOperatingTime();
    uint8_t getFeaturesSupported();
    uint8_t getFeaturesEnabled();
}

#endif // ANTPLUS_HEARTRATECUMULITIVEOPERATINGTIME_h