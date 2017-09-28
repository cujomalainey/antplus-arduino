#include <Profiles/HeartRate/DataPages/TX/ANTPLUS_HeartRateProductInformationMsg.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

HeartRateProductInformationMsg::HeartRateProductInformationMsg() : HeartRateBaseMainDataPageMsg(ANTPLUS_HEARTRATE_DATAPAGE_PRODUCTINFORMATION_NUMBER) {

}

uint8_t HeartRateProductInformationMsg::getHardwareVersion() {
    // TODO
}

uint8_t HeartRateProductInformationMsg::getSoftwareVersion() {
    // TODO
}

uint8_t HeartRateProductInformationMsg::getModelNumber() {
    // TODO
}

void HeartRateProductInformationMsg::setHardwareVersion(uint8_t hwVersion) {
    // TODO
}

void HeartRateProductInformationMsg::setSoftwareVersion(uint8_t swVersion) {
    // TODO
}

void HeartRateProductInformationMsg::setModelNumber(uint8_t modelNumber) {
    // TODO
}
