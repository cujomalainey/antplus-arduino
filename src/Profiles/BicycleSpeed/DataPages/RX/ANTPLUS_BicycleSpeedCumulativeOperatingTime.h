#ifndef ANTPLUS_BICYCLESPEEDCUMULITIVEOPERATINGTIME_h
#define ANTPLUS_BICYCLESPEEDCUMULITIVEOPERATINGTIME_h

#include <Profiles/BicycleSpeed/DataPages/Base/ANTPLUS_BicycleSpeedBaseMainDataPage.h>

class BicycleSpeedCumulativeOperatingTime : public BicycleSpeedBaseMainDataPage {
public:
    BicycleSpeedCumulativeOperatingTime(AntRxDataResponse& dp);
    uint32_t getCumulativeOperatingTime(); // only 24 bits
};

#endif // ANTPLUS_BICYCLESPEEDCUMULITIVEOPERATINGTIME_h
