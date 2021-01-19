#include <Profiles/BicycleSpeed/DataPages/ANTPLUS_BicycleSpeedProductID.h>
#include <Profiles/BicycleSpeed/ANTPLUS_BicycleSpeedPrivateDefines.h>

#define HARDWAREVERSION_BYTE 1
#define SOFTWAREVERSION_BYTE 2
#define MODELNUMBER_BYTE 3

template<class T>
BicycleSpeedBaseProductID<T>::BicycleSpeedBaseProductID() : CoreDataPage<T>() {}

template<class T>
uint8_t BicycleSpeedBaseProductID<T>::getHardwareVersion() {
    return this->get8BitValue(HARDWAREVERSION_BYTE);
}

template<class T>
uint8_t BicycleSpeedBaseProductID<T>::getSoftwareVersion() {
    return this->get8BitValue(SOFTWAREVERSION_BYTE);
}

template<class T>
uint8_t BicycleSpeedBaseProductID<T>::getModelNumber() {
    return this->get8BitValue(MODELNUMBER_BYTE);
}

template class BicycleSpeedBaseProductID<BroadcastData>;
template class BicycleSpeedBaseProductID<BroadcastDataMsg>;

BicycleSpeedProductID::BicycleSpeedProductID(AntRxDataResponse& dp) :
    BicycleSpeedBaseMainDataPage(dp),
    BicycleSpeedBaseProductID<BroadcastData>() {}
