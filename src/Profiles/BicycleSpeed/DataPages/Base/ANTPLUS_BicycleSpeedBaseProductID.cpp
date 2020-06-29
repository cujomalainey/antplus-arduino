#include <Profiles/BicycleSpeed/DataPages/Base/ANTPLUS_BicycleSpeedBaseProductID.h>
#include <Profiles/BicycleSpeed/ANTPLUS_BicycleSpeedPrivateDefines.h>

template<class T>
BicycleSpeedBaseProductID<T>::BicycleSpeedBaseProductID() : CoreDataPage<T>() {
}

template<class T>
uint8_t BicycleSpeedBaseProductID<T>::getHardwareVersion() {
    return this->get8BitValue(
            ANTPLUS_BICYCLESPEED_DATAPAGE_PRODUCTINFORMATION_HARDWAREVERSION_BYTE);
}

template<class T>
uint8_t BicycleSpeedBaseProductID<T>::getSoftwareVersion() {
    return this->get8BitValue(
            ANTPLUS_BICYCLESPEED_DATAPAGE_PRODUCTINFORMATION_SOFTWAREVERSION_BYTE);
}

template<class T>
uint8_t BicycleSpeedBaseProductID<T>::getModelNumber() {
    return this->get8BitValue(
            ANTPLUS_BICYCLESPEED_DATAPAGE_PRODUCTINFORMATION_MODELNUMBER_BYTE);
}

template class BicycleSpeedBaseProductID<BroadcastData>;
template class BicycleSpeedBaseProductID<BroadcastDataMsg>;
