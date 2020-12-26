#ifndef ANTPLUS_BICYCLEPOWERBASEPEDALSMOOTHNESS_h
#define ANTPLUS_BICYCLEPOWERBASEPEDALSMOOTHNESS_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

template<class T>
class BicyclePowerBasePedalSmoothness : virtual public CoreDataPage<T> {
public:
    BicyclePowerBasePedalSmoothness();
    uint8_t getLeftTorqueEffectiveness();
    uint8_t getRightTorqueEffectiveness();
    uint8_t getLeftPedalSmoothness();
    uint8_t getRightPedalSmoothness();
};

#endif // ANTPLUS_BICYCLEPOWERBASEPEDALSMOOTHNESS_h