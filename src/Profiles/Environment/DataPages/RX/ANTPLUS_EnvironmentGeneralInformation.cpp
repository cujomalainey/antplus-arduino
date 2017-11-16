#include <Profiles/Environment/DataPages/RX/ANTPLUS_EnvironmentGeneralInformation.h>

EnvironmentGeneralInformation::EnvironmentGeneralInformation(AntRxDataResponse& dp) : EnvironmentBaseDataPage(dp) {
}

uint8_t EnvironmentGeneralInformation::getTransmissionInfoLocalTime() {
    // TODO
}

uint8_t EnvironmentGeneralInformation::getTransmissionInfoUtcTime() {
    // TODO
}

uint8_t EnvironmentGeneralInformation::getTransmissionInfoDefaultTransmissionRate() {
    // TODO
}

uint32_t EnvironmentGeneralInformation::getSupportedPages() {
    // TODO
}
