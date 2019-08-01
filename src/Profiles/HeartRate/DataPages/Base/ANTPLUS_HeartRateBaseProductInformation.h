#ifndef ANTPLUS_HEARTRATEBASEPRODUCTIONINFORMATION_h
#define ANTPLUS_HEARTRATEBASEPRODUCTIONINFORMATION_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

template<class T>
class HeartRateBaseProductInformation : virtual public CoreDataPage<T> {
public:
    HeartRateBaseProductInformation();
    uint8_t getHardwareVersion();
    uint8_t getSoftwareVersion();
    uint8_t getModelNumber();
};

#endif // ANTPLUS_HEARTRATEBASEPRODUCTIONINFORMATION_h
