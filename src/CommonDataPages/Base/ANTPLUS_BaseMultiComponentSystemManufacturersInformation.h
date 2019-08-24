#ifndef ANTPLUS_BASEMULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_h
#define ANTPLUS_BASEMULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

// Common page 78

template<class T>
class BaseMultiComponentSystemManufacturersInformation : virtual public CoreDataPage<T> {
public:
    BaseMultiComponentSystemManufacturersInformation();
    uint8_t getNumberOfComponents();
    uint8_t getComponentIdentifier();
    uint8_t getHWRevision();
    uint16_t getManufacturerID();
    uint16_t getModelNumber();
};

#endif // ANTPLUS_BASEMULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_h
