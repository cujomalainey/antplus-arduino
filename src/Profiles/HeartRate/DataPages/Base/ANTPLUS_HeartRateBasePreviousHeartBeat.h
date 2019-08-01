#ifndef ANTPLUS_HEARTRATEBASEPREVIOUSHEARTBEAT_h
#define ANTPLUS_HEARTRATEBASEPREVIOUSHEARTBEAT_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

template<class T>
class HeartRateBasePreviousHeartBeat : virtual public CoreDataPage<T> {
public:
    HeartRateBasePreviousHeartBeat();
    uint8_t getManufacturerSpecific();
    uint16_t getPreviousHeartBeatEventTime();
};

#endif // ANTPLUS_HEARTRATEBASEPREVIOUSHEARTBEAT_h
