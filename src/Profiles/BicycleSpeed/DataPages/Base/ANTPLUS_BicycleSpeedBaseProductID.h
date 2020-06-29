#ifndef ANTPLUS_BICYCLESPEEDBASEPRODUCTIONID_h
#define ANTPLUS_BICYCLESPEEDBASEPRODUCTIONID_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

template<class T>
class BicycleSpeedBaseProductID : virtual public CoreDataPage<T> {
public:
    BicycleSpeedBaseProductID();
    uint8_t getHardwareVersion();
    uint8_t getSoftwareVersion();
    uint8_t getModelNumber();
};

#endif // ANTPLUS_BICYCLESPEEDBASEPRODUCTIONID_h
