#ifndef ANTPLUS_BASEMANUFACTURERSINFORMATION_h
#define ANTPLUS_BASEMANUFACTURERSINFORMATION_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

// Common page 80

template<class T>
class BaseManufacturersInformation : virtual public CoreDataPage<T> {
public:
    BaseManufacturersInformation();
    uint8_t getHWRevision();
    uint16_t getManufacturerID();
    uint16_t getModelNumber();
};

#endif // ANTPLUS_BASEMANUFACTURERSINFORMATION_h
