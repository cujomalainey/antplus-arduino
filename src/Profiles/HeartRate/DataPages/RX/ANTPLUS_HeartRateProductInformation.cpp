#include <Profiles/HeartRate/DataPages/RX/ANTPLUS_HeartRateProductInformation.h>

HeartRateProductInformation::HeartRateProductInformation(AntRxDataResponse& dp) : HeartRateBaseMainDataPage(dp) {

}

uint8_t HeartRateProductInformation::getHardwareVersion() {
    // TODO
}

uint8_t HeartRateProductInformation::getSoftwareVersion() {
    // TODO
}

uint8_t HeartRateProductInformation::getModelNumber() {
    // TODO
}
