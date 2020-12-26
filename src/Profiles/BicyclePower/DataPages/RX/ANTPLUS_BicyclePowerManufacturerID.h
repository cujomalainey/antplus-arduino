#ifndef ANTPLUS_BICYCLEPOWERMANUFACTURERID_h
#define ANTPLUS_BICYCLEPOWERMANUFACTURERID_h

#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerBaseMainDataPage.h>
#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerBaseManufacturerID.h>

class BicyclePowerManufacturerID : public BicyclePowerBaseMainDataPage, public BicyclePowerBaseManufacturerID<BroadcastData> {
public:
    BicyclePowerManufacturerID(AntRxDataResponse& dp);
};

#endif // ANTPLUS_BICYCLEPOWERMANUFACTURERID_h
