#ifndef ANTPLUS_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_h
#define ANTPLUS_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>
#include <CommonDataPages/Base/ANTPLUS_BaseMultiComponentSystemProductInformation.h>

#include "ANT.h"

// Common page 79

class MultiComponentSystemProductInformation : public BaseDataPage<BroadcastData>, public BaseMultiComponentSystemProductInformation<BroadcastData> {
public:
    explicit MultiComponentSystemProductInformation(AntRxDataResponse& dp);
};

#endif // ANTPLUS_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_h
