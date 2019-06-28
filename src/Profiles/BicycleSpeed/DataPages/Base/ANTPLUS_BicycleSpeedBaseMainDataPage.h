#ifndef ANTPLUS_BICYCLESPEEDBASEMAINDATAPAGE_h
#define ANTPLUS_BICYCLESPEEDBASEMAINDATAPAGE_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>

#include "ANT.h"

class BicycleSpeedBaseMainDataPage : public BaseDataPage<BroadcastData> {
public:
    BicycleSpeedBaseMainDataPage(AntRxDataResponse& dp);
    uint8_t getDataPageNumber();
    uint8_t getPageChangeToggle();
    uint16_t getBikeSpeedEventTime();
    uint16_t getCumulativeSpeedRevolutionCount();
};

#endif // ANTPLUS_BICYCLESPEEDBASEMAINDATAPAGE_h
