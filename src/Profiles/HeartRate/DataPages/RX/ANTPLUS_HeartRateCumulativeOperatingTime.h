#ifndef ANTPLUS_HEARTRATECUMULITIVEOPERATINGTIME_h
#define ANTPLUS_HEARTRATECUMULITIVEOPERATINGTIME_h

#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPage.h>

class HeartRateCumulativeOperatingTime : public HeartRateBaseMainDataPage {
public:
    HeartRateCumulativeOperatingTime();
    uint8_t getFeaturesSupported();
    uint8_t getFeaturesEnabled();
};

#endif // ANTPLUS_HEARTRATECUMULITIVEOPERATINGTIME_h