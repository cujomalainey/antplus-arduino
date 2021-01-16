#ifndef ANTPLUS_MANUFACTURERSINFORMATION_h
#define ANTPLUS_MANUFACTURERSINFORMATION_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>
#include <CommonDataPages/Base/ANTPLUS_BaseManufacturersInformation.h>

#include "ANT.h"

// Common page 80

class ManufacturersInformation : public BaseDataPage<BroadcastData>, public BaseManufacturersInformation<BroadcastData> {
public:
    explicit ManufacturersInformation(AntRxDataResponse& dp);
};

#endif // ANTPLUS_MANUFACTURERSINFORMATION_h
