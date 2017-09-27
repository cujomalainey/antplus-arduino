#include <Profiles/HeartRate/DataPages/RX/ANTPLUS_HeartRateCapabilities.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

HeartRateCapabilities::HeartRateCapabilities(AntRxDataResponse& dp) : HeartRateBaseMainDataPage(dp) {

}

uint8_t HeartRateCapabilities::getFeaturesSupported() {
    return getData(ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_FEATURESSUPPORTED_BYTE);
}

uint8_t HeartRateCapabilities::getFeaturesEnabled() {
    return getData(ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_FEATURESENABLED_BYTE);
}
