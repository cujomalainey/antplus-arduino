#ifndef ANTPLUS_BICYCLESPEEDPRODUCTIONID_h
#define ANTPLUS_BICYCLESPEEDPRODUCTIONID_h

#include <Profiles/BicycleSpeed/DataPages/Base/ANTPLUS_BicycleSpeedBaseMainDataPage.h>
#include <Profiles/BicycleSpeed/DataPages/Base/ANTPLUS_BicycleSpeedBaseProductID.h>

class BicycleSpeedProductID : public BicycleSpeedBaseMainDataPage, public BicycleSpeedBaseProductID<BroadcastData> {
public:
    BicycleSpeedProductID(AntRxDataResponse& dp);
};

#endif // ANTPLUS_BICYCLESPEEDPRODUCTIONID_h
