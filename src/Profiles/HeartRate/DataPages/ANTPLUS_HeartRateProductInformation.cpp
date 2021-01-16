#include <Profiles/HeartRate/DataPages/ANTPLUS_HeartRateProductInformation.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

template<class T>
HeartRateBaseProductInformation<T>::HeartRateBaseProductInformation() : CoreDataPage<T>() {}

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

HeartRateProductInformation::HeartRateProductInformation(AntRxDataResponse& dp) : HeartRateBaseMainDataPage(dp), HeartRateBaseProductInformation<BroadcastData>() {}

HeartRateProductInformationMsg::HeartRateProductInformationMsg() : HeartRateBaseMainDataPageMsg(ANTPLUS_HEARTRATE_DATAPAGE_PRODUCTINFORMATION_NUMBER) {}

void HeartRateProductInformationMsg::setHardwareVersion(uint8_t hwVersion) {
    _buffer[ANTPLUS_HEARTRATE_DATAPAGE_PRODUCTINFORMATION_HARDWAREVERSION_BYTE] = hwVersion;
}

void HeartRateProductInformationMsg::setSoftwareVersion(uint8_t swVersion) {
    _buffer[ANTPLUS_HEARTRATE_DATAPAGE_PRODUCTINFORMATION_SOFTWAREVERSION_BYTE] = swVersion;
}

void HeartRateProductInformationMsg::setModelNumber(uint8_t modelNumber) {
    _buffer[ANTPLUS_HEARTRATE_DATAPAGE_PRODUCTINFORMATION_MODELNUMBER_BYTE] = modelNumber;
}
