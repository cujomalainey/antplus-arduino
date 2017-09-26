#ifndef ANTPLUS_HEARTRATECUMULITIVEOPERATINGTIME_h
#define ANTPLUS_HEARTRATECUMULITIVEOPERATINGTIME_h

#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPage.h>

class HeartRateCumulativeOperatingTime : public HeartRateBaseMainDataPage {
public:
    HeartRateCumulativeOperatingTime(AntRxDataResponse& dp);
    uint32_t getCumulativeOperatingTime(); // only 24 bits
};

#endif // ANTPLUS_HEARTRATECUMULITIVEOPERATINGTIME_h