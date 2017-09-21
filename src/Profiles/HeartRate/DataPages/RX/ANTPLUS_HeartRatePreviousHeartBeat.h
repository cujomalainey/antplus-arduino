#ifndef ANTPLUS_HEARTRATEPREVIOUSHEARTBEAT_h
#define ANTPLUS_HEARTRATEPREVIOUSHEARTBEAT_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>

#include "ANT.h"

class HeartRatePreviousHeartBeat : public HeartRateBaseMainDataPage {
public:
    HeartRatePreviousHeartBeat();
    uint8_t getManufacturerSpecific();
    uint16_t getPreviousHeartBeatEventTime();
}

#endif // ANTPLUS_HEARTRATEPREVIOUSHEARTBEAT_h