#ifndef ANTPLUS_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_h
#define ANTPLUS_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>
#include <CommonDataPages/Base/ANTPLUS_BaseMultiComponentSystemManufacturersInformation.h>

#include "ANT.h"

// Common page 78

class MultiComponentSystemManufacturersInformation : public BaseDataPage<BroadcastData>, public BaseMultiComponentSystemManufacturersInformation<BroadcastData> {
public:
    MultiComponentSystemManufacturersInformation(AntRxDataResponse& dp);
};

#endif // ANTPLUS_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_h
