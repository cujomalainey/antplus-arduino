#ifndef ANTPLUS_BICYCLESPEEDMANUFACTURERID_h
#define ANTPLUS_BICYCLESPEEDMANUFACTURERID_h

#include <Profiles/BicycleSpeed/DataPages/ANTPLUS_BicycleSpeedBaseMainDataPage.h>

template<class T>
class BicycleSpeedBaseManufacturerID : virtual public CoreDataPage<T> {
public:
    BicycleSpeedBaseManufacturerID();
    uint8_t getManufacturerId();
    uint16_t getSerialNumber();
};

class BicycleSpeedManufacturerID : public BicycleSpeedBaseMainDataPage, public BicycleSpeedBaseManufacturerID<BroadcastData> {
public:
    explicit BicycleSpeedManufacturerID(AntRxDataResponse& dp);
};

#endif // ANTPLUS_BICYCLESPEEDMANUFACTURERID_h
