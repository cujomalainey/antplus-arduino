#ifndef ANTPLUS_HEARTRATEBASEMANUFACTURERINFORMATION_h
#define ANTPLUS_HEARTRATEBASEMANUFACTURERINFORMATION_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

template<class T>
class HeartRateBaseManufacturerInformation : virtual public CoreDataPage<T> {
public:
    HeartRateBaseManufacturerInformation();
    uint8_t getManufacturerIdLsb();
    uint16_t getSerialNumber();
};

#endif // ANTPLUS_HEARTRATEBASEMANUFACTURERINFORMATION_h
