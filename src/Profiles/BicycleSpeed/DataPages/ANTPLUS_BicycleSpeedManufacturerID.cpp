#include <Profiles/BicycleSpeed/DataPages/ANTPLUS_BicycleSpeedManufacturerID.h>
#include <Profiles/BicycleSpeed/ANTPLUS_BicycleSpeedPrivateDefines.h>

template<class T>
BicycleSpeedBaseManufacturerID<T>::BicycleSpeedBaseManufacturerID() :
    CoreDataPage<T>() {}

template<class T>
uint8_t BicycleSpeedBaseManufacturerID<T>::getManufacturerId() {
    return this->get8BitValue(
            ANTPLUS_BICYCLESPEED_DATAPAGE_MANUFACTURERINFORMATION_MANUFACTUREREID_BYTE);
}

template<class T>
uint16_t BicycleSpeedBaseManufacturerID<T>::getSerialNumber() {
    return this->get16BitValue(
            ANTPLUS_BICYCLESPEED_DATAPAGE_MANUFACTURERINFORMATION_SERIALNUMBER_LSB_BYTE,
            ANTPLUS_BICYCLESPEED_DATAPAGE_MANUFACTURERINFORMATION_SERIALNUMBER_MSB_BYTE);
}

template class BicycleSpeedBaseManufacturerID<BroadcastData>;
template class BicycleSpeedBaseManufacturerID<BroadcastDataMsg>;

BicycleSpeedManufacturerID::BicycleSpeedManufacturerID(AntRxDataResponse& dp) :
    BicycleSpeedBaseMainDataPage(dp),
    BicycleSpeedBaseManufacturerID<BroadcastData>() {}
