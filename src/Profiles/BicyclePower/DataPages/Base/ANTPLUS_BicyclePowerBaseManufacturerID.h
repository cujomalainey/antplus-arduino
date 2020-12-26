#ifndef ANTPLUS_BICYCLEPOWERBASEMANUFACTURERINFORMATION_h
#define ANTPLUS_BICYCLEPOWERBASEMANUFACTURERINFORMATION_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

template<class T>
class BicyclePowerBaseManufacturerID : virtual public CoreDataPage<T> {
public:
    BicyclePowerBaseManufacturerID();
    uint8_t getHardwareVersion();
    uint16_t getManufacturerId();
    uint16_t getModelNumber();
};

#endif // ANTPLUS_BICYCLEPOWERBASEMANUFACTURERINFORMATION_h
