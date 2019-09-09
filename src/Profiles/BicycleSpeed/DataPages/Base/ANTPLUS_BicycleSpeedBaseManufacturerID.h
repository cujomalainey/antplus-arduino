#ifndef ANTPLUS_BICYCLESPEEDBASEMANUFACTURERID_h
#define ANTPLUS_BICYCLESPEEDBASEMANUFACTURERID_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

template<class T>
class BicycleSpeedBaseManufacturerID : virtual public CoreDataPage<T> {
public:
    BicycleSpeedBaseManufacturerID();
    uint8_t getManufacturerId();
    uint16_t getSerialNumber();
};

#endif // ANTPLUS_BICYCLESPEEDBASEMANUFACTURERID_h
