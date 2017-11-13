#ifndef ANTPLUS_PRODUCTINFORMATION_h
#define ANTPLUS_PRODUCTINFORMATION_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>

#include "ANT.h"

// Common page 81

class ProductInformation : public BaseDataPage<BroadcastData> {
public:
    ProductInformation(BroadcastData& dp);
    // TODO
};

#endif // AANTPLUS_PRODUCTINFORMATION_h
