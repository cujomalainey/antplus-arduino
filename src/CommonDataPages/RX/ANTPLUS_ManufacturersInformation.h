#ifndef ANTPLUS_MANUFACTURERSINFORMATION_h
#define ANTPLUS_MANUFACTURERSINFORMATION_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>

#include "ANT.h"

// Common page 80

class ManufacturersInformation : public BaseDataPage<BroadcastData> {
public:
    ManufacturersInformation(AntRxDataResponse& dp);
    uint8_t getHWRevision();
    uint16_t getManufacturerID();
    uint16_t getModelNumber();
};

#endif // ANTPLUS_MANUFACTURERSINFORMATION_h
