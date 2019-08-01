#ifndef ANTPLUS_HEARTRATECOREMAINDATAPAGE_h
#define ANTPLUS_HEARTRATECOREMAINDATAPAGE_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

template<class T>
class HeartRateCoreMainDataPage : virtual public CoreDataPage<T> {
public:
    HeartRateCoreMainDataPage();
    uint8_t getDataPageNumber();
    uint8_t getPageChangeToggle();
    uint16_t getHeartBeatEventTime();
    uint8_t getHeartBeatCount();
    uint8_t getComputedHeartRate();
};

#endif // ANTPLUS_HEARTRATECOREMAINDATAPAGE_h
