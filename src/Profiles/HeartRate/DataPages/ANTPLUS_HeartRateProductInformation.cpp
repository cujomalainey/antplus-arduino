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
    HeartRateBaseMainDataPageMsg(HEARTRATE_PRODUCTINFORMATION_NUMBER),
    HeartRateBaseProductInformation<BroadcastDataMsg>() {}

void HeartRateProductInformationMsg::setHardwareVersion(uint8_t hwVersion) {
    this->set8BitValue(hwVersion, HARDWAREVERSION_BYTE);
}

void HeartRateProductInformationMsg::setSoftwareVersion(uint8_t swVersion) {
    this->set8BitValue(swVersion, SOFTWAREVERSION_BYTE);
}

void HeartRateProductInformationMsg::setModelNumber(uint8_t modelNumber) {
    this->set8BitValue(modelNumber, MODELNUMBER_BYTE);
}
