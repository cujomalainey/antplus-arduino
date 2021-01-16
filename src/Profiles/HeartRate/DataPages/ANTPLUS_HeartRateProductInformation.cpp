#include <Profiles/HeartRate/DataPages/ANTPLUS_HeartRateProductInformation.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

#define HARDWAREVERSION_BYTE 1
#define SOFTWAREVERSION_BYTE 2
#define MODELNUMBER_BYTE 3

template<class T>
HeartRateBaseProductInformation<T>::HeartRateBaseProductInformation() :
    CoreDataPage<T>() {}

template<class T>
uint8_t HeartRateBaseProductInformation<T>::getHardwareVersion() {
    return this->get8BitValue(HARDWAREVERSION_BYTE);
}

template<class T>
uint8_t HeartRateBaseProductInformation<T>::getSoftwareVersion() {
    return this->get8BitValue(SOFTWAREVERSION_BYTE);
}

template<class T>
uint8_t HeartRateBaseProductInformation<T>::getModelNumber() {
    return this->get8BitValue(MODELNUMBER_BYTE);
}

template class HeartRateBaseProductInformation<BroadcastData>;
template class HeartRateBaseProductInformation<BroadcastDataMsg>;

HeartRateProductInformation::HeartRateProductInformation(AntRxDataResponse& dp) :
    HeartRateBaseMainDataPage(dp),
    HeartRateBaseProductInformation<BroadcastData>() {}

HeartRateProductInformationMsg::HeartRateProductInformationMsg() :
    HeartRateBaseMainDataPageMsg(PRODUCTINFORMATION_NUMBER),
    HeartRateBaseProductInformation<BroadcastDataMsg>() {}

// TODO set to product information API
void HeartRateProductInformationMsg::setHardwareVersion(uint8_t hwVersion) {
    _buffer[HARDWAREVERSION_BYTE] = hwVersion;
}

void HeartRateProductInformationMsg::setSoftwareVersion(uint8_t swVersion) {
    _buffer[SOFTWAREVERSION_BYTE] = swVersion;
}

void HeartRateProductInformationMsg::setModelNumber(uint8_t modelNumber) {
    _buffer[MODELNUMBER_BYTE] = modelNumber;
}
