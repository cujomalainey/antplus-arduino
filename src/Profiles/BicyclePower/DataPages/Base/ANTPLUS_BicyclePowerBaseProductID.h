#ifndef ANTPLUS_BICYCLEPOWERBASEPRODUCTID_h
#define ANTPLUS_BICYCLEPOWERBASEPRODUCTID_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

template<class T>
class BicyclePowerBaseProductID : virtual public CoreDataPage<T> {
public:
    BicyclePowerBaseProductID();
    uint8_t getSoftwareVersionSupplemental();
    uint8_t getSoftwareVersion();
    uint8_t getModelNumber();
    uint32_t getSerialNumber();
};

#endif // ANTPLUS_BICYCLEPOWERBASEPRODUCTIONINFORMATION_h
