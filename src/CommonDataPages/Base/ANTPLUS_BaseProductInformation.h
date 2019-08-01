#ifndef ANTPLUS_BASEPRODUCTINFORMATION_h
#define ANTPLUS_BASEPRODUCTINFORMATION_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

// Common page 81

template<class T>
class BaseProductInformation : virtual public CoreDataPage<T> {
public:
    BaseProductInformation();
    uint8_t getSWRevisionSupplemental();
    uint8_t getSWRevisionMain();
    uint32_t getSerialNumber();
};

#endif // ANTPLUS_BASEPRODUCTINFORMATION_h
