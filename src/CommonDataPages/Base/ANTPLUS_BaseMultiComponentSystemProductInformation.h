#ifndef ANTPLUS_BASEMULTICOMPONENTSYSTEMPRODUCTINFORMATION_h
#define ANTPLUS_BASEMULTICOMPONENTSYSTEMPRODUCTINFORMATION_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

// Common page 79

template<class T>
class BaseMultiComponentSystemProductInformation : virtual public CoreDataPage<T> {
public:
    BaseMultiComponentSystemProductInformation();
    uint8_t getNumberOfComponents();
    uint8_t getComponentIdentifier();
    uint8_t getSWRevisionSupplemental();
    uint8_t getSWRevisionMain();
    uint32_t getSerialNumber();
};

#endif // ANTPLUS_BASEMULTICOMPONENTSYSTEMPRODUCTINFORMATION_h
