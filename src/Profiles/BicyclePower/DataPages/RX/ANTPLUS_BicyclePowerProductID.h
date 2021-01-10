#ifndef ANTPLUS_BICYCLEPOWERPRODUCTIONID_h
#define ANTPLUS_BICYCLEPOWERPRODUCTIONID_h

#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerBaseMainDataPage.h>
#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerBaseProductID.h>

class BicyclePowerProductID : public BicyclePowerBaseMainDataPage, public BicyclePowerBaseProductID<BroadcastData> {
public:
    BicyclePowerProductID(AntRxDataResponse& dp);
};

#endif // ANTPLUS_BICYCLEPOWERPRODUCTIONID_h
