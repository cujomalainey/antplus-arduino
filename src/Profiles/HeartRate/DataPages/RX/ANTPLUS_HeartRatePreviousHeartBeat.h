#ifndef ANTPLUS_HEARTRATEPREVIOUSHEARTBEAT_h
#define ANTPLUS_HEARTRATEPREVIOUSHEARTBEAT_h

#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPage.h>

#include "ANT.h"

class HeartRatePreviousHeartBeat : public HeartRateBaseMainDataPage {
public:
    HeartRatePreviousHeartBeat();
    uint8_t getManufacturerSpecific();
    uint16_t getPreviousHeartBeatEventTime();
};

#endif // ANTPLUS_HEARTRATEPREVIOUSHEARTBEAT_h