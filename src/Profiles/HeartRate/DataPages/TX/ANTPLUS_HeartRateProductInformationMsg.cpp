#include <Profiles/HeartRate/DataPages/TX/ANTPLUS_HeartRateProductInformationMsg.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

HeartRateProductInformationMsg::HeartRateProductInformationMsg() : HeartRateBaseMainDataPageMsg(ANTPLUS_HEARTRATE_DATAPAGE_PRODUCTINFORMATION_NUMBER) {

}

void HeartRateProductInformationMsg::setHardwareVersion(uint8_t hwVersion) {
    _buffer[ANTPLUS_HEARTRATE_DATAPAGE_PRODUCTINFORMATION_HARDWAREVERSION_BYTE] = hwVersion;
}

void HeartRateProductInformationMsg::setSoftwareVersion(uint8_t swVersion) {
    _buffer[ANTPLUS_HEARTRATE_DATAPAGE_PRODUCTINFORMATION_SOFTWAREVERSION_BYTE] = swVersion;
}

void HeartRateProductInformationMsg::setModelNumber(uint8_t modelNumber) {
    _buffer[ANTPLUS_HEARTRATE_DATAPAGE_PRODUCTINFORMATION_MODELNUMBER_BYTE] = modelNumber;
}
