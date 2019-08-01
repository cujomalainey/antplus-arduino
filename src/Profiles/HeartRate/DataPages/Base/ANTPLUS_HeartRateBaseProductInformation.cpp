#include <Profiles/HeartRate/DataPages/RX/ANTPLUS_HeartRateProductInformation.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

template<class T>
HeartRateBaseProductInformation<T>::HeartRateBaseProductInformation() : CoreDataPage<T>() {
}

template<class T>
uint8_t HeartRateBaseProductInformation<T>::getHardwareVersion() {
    return this->get8BitValue(
            ANTPLUS_HEARTRATE_DATAPAGE_PRODUCTINFORMATION_HARDWAREVERSION_BYTE);
}

template<class T>
uint8_t HeartRateBaseProductInformation<T>::getSoftwareVersion() {
    return this->get8BitValue(
            ANTPLUS_HEARTRATE_DATAPAGE_PRODUCTINFORMATION_SOFTWAREVERSION_BYTE);
}

template<class T>
uint8_t HeartRateBaseProductInformation<T>::getModelNumber() {
    return this->get8BitValue(
            ANTPLUS_HEARTRATE_DATAPAGE_PRODUCTINFORMATION_MODELNUMBER_BYTE);
}

template class HeartRateBaseProductInformation<BroadcastData>;
template class HeartRateBaseProductInformation<BroadcastDataMsg>;
