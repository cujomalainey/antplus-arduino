#ifndef ANTPLUS_PRODUCTINFORMATION_h
#define ANTPLUS_PRODUCTINFORMATION_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>

#include "ANT.h"

// Common page 81

class ProductInformation : public BaseDataPage<BroadcastData> {
public:
    ProductInformation(AntRxDataResponse& dp);
    uint8_t getSWRevisionSupplemental();
    uint8_t getSWRevisionMain();
    uint32_t getSerialNumber();
};

#endif // ANTPLUS_PRODUCTINFORMATION_h
