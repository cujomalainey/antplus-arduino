#include <Profiles/BicycleSpeed/DataPages/ANTPLUS_BicycleSpeedManufacturerID.h>
#include <Profiles/BicycleSpeed/ANTPLUS_BicycleSpeedPrivateDefines.h>

#define MANUFACTUREREID_BYTE 1
#define SERIALNUMBER_LSB_BYTE 2
#define SERIALNUMBER_MSB_BYTE 3

template<class T>
BicycleSpeedBaseManufacturerID<T>::BicycleSpeedBaseManufacturerID() :
    CoreDataPage<T>() {}

template<class T>
uint8_t BicycleSpeedBaseManufacturerID<T>::getManufacturerId() {
    return this->get8BitValue(MANUFACTUREREID_BYTE);
}

template<class T>
uint16_t BicycleSpeedBaseManufacturerID<T>::getSerialNumber() {
    return this->get16BitValue(SERIALNUMBER_LSB_BYTE, SERIALNUMBER_MSB_BYTE);
}

template class BicycleSpeedBaseManufacturerID<BroadcastData>;
template class BicycleSpeedBaseManufacturerID<BroadcastDataMsg>;

BicycleSpeedManufacturerID::BicycleSpeedManufacturerID(AntRxDataResponse& dp) :
    BicycleSpeedBaseMainDataPage(dp),
    BicycleSpeedBaseManufacturerID<BroadcastData>() {}
