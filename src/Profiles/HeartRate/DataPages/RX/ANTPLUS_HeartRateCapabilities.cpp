#include <Profiles/HeartRate/DataPages/RX/ANTPLUS_HeartRateCapabilities.h>

HeartRateCapabilities::HeartRateCapabilities(AntRxDataResponse& dp) : HeartRateBaseMainDataPage(dp) {
    // TODO
}

uint8_t HeartRateCapabilities::getFeaturesSupported() {
    // TODO
}

uint8_t HeartRateCapabilities::getFeaturesEnabled() {
    // TODO
}
