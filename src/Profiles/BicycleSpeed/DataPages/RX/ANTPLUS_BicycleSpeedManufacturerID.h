#ifndef ANTPLUS_BICYCLESPEEDMANUFACTURERID_h
#define ANTPLUS_BICYCLESPEEDMANUFACTURERID_h

#include <Profiles/BicycleSpeed/DataPages/Base/ANTPLUS_BicycleSpeedBaseMainDataPage.h>
#include <Profiles/BicycleSpeed/DataPages/Base/ANTPLUS_BicycleSpeedBaseManufacturerID.h>

class BicycleSpeedManufacturerID : public BicycleSpeedBaseMainDataPage, public BicycleSpeedBaseManufacturerID<BroadcastData> {
public:
    BicycleSpeedManufacturerID(AntRxDataResponse& dp);
};

#endif // ANTPLUS_BICYCLESPEEDMANUFACTURERID_h
