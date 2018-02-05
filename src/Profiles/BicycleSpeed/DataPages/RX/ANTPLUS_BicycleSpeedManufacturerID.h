#ifndef ANTPLUS_BICYCLESPEEDMANUFACTURERID_h
#define ANTPLUS_BICYCLESPEEDMANUFACTURERID_h

#include <Profiles/BicycleSpeed/DataPages/Base/ANTPLUS_BicycleSpeedBaseMainDataPage.h>

class BicycleSpeedManufacturerID : public BicycleSpeedBaseMainDataPage {
public:
    BicycleSpeedManufacturerID(AntRxDataResponse& dp);
    uint8_t getManufacturerId();
    uint16_t getSerialNumber();
};

#endif // ANTPLUS_BICYCLESPEEDMANUFACTURERID_h
