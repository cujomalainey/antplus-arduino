#ifndef ANTPLUS_BICYCLEPOWERBASEWHEELTORQUE_h
#define ANTPLUS_BICYCLEPOWERBASEWHEELTORQUE_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

template<class T>
class BicyclePowerBaseStandardWheelTorque : virtual public CoreDataPage<T> {
public:
    BicyclePowerBaseStandardWheelTorque();
    uint8_t getWheelTicks();
    uint8_t getInstantCadence(); // May not be available, 0xFF indicates invalid
    uint16_t getWheelPeriod();
    uint16_t getAccumulatedTorque();
};

#endif // ANTPLUS_BICYCLEPOWERBASEWHEELTORQUE_h
