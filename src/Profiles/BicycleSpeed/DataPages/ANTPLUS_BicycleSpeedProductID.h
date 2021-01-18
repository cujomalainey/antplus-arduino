#ifndef ANTPLUS_BICYCLESPEEDPRODUCTIONID_h
#define ANTPLUS_BICYCLESPEEDPRODUCTIONID_h

#include <Profiles/BicycleSpeed/DataPages/ANTPLUS_BicycleSpeedBaseMainDataPage.h>

template<class T>
class BicycleSpeedBaseProductID : virtual public CoreDataPage<T> {
public:
    BicycleSpeedBaseProductID();
    uint8_t getHardwareVersion();
    uint8_t getSoftwareVersion();
    uint8_t getModelNumber();
};

class BicycleSpeedProductID : public BicycleSpeedBaseMainDataPage, public BicycleSpeedBaseProductID<BroadcastData> {
public:
    explicit BicycleSpeedProductID(AntRxDataResponse& dp);
};

#endif // ANTPLUS_BICYCLESPEEDPRODUCTIONID_h
