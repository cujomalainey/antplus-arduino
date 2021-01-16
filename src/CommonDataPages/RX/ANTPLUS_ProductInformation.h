#ifndef ANTPLUS_PRODUCTINFORMATION_h
#define ANTPLUS_PRODUCTINFORMATION_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>
#include <CommonDataPages/Base/ANTPLUS_BaseProductInformation.h>

#include "ANT.h"

// Common page 81

class ProductInformation : public BaseDataPage<BroadcastData>, public BaseProductInformation<BroadcastData> {
public:
    explicit ProductInformation(AntRxDataResponse& dp);
};

#endif // ANTPLUS_PRODUCTINFORMATION_h
