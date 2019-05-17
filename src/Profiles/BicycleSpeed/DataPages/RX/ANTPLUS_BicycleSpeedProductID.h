#ifndef ANTPLUS_BICYCLESPEEDPRODUCTIONID_h
#define ANTPLUS_BICYCLESPEEDPRODUCTIONID_h

#include <Profiles/BicycleSpeed/DataPages/Base/ANTPLUS_BicycleSpeedBaseMainDataPage.h>

class BicycleSpeedProductID : public BicycleSpeedBaseMainDataPage {
public:
    BicycleSpeedProductID(AntRxDataResponse& dp);
    uint8_t getHardwareVersion();
    uint8_t getSoftwareVersion();
    uint8_t getModelNumber();
};

#endif // ANTPLUS_BICYCLESPEEDPRODUCTIONID_h
