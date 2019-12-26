#ifndef ANTPLUS_BICYCLESPEEDBASEMOTIONANDSPEED_h
#define ANTPLUS_BICYCLESPEEDBASEMOTIONANDSPEED_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

template<class T>
class BicycleSpeedBaseMotionAndSpeed : virtual public CoreDataPage<T> {
public:
    BicycleSpeedBaseMotionAndSpeed();
    uint8_t getFlags();
};

#endif // ANTPLUS_BICYCLESPEEDBASEMOTIONANDSPEED_h
