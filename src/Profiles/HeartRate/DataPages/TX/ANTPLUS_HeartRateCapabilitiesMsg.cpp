#include <Profiles/HeartRate/DataPages/TX/ANTPLUS_HeartRateCapabilitiesMsg.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

HeartRateCapabilitiesMsg::HeartRateCapabilitiesMsg() : HeartRateBaseMainDataPageMsg() {
    // TODO Magic Numbers
    _buffer[0] = ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_NUMBER;
}

uint8_t HeartRateCapabilitiesMsg::getFeaturesSupported() {
    return _buffer[ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_FEATURESSUPPORTED_BYTE];
}

uint8_t HeartRateCapabilitiesMsg::getFeaturesEnabled() {
    return _buffer[ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_FEATURESENABLED_BYTE];
}

void HeartRateCapabilitiesMsg::setFeaturesSupported(uint8_t supported) {
    _buffer[ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_FEATURESSUPPORTED_BYTE] = supported & ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_FEATURES_MASK;
}

void HeartRateCapabilitiesMsg::setFeaturesEnabled(uint8_t enabled) {
    _buffer[ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_FEATURESENABLED_BYTE] = enabled & ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_FEATURES_MASK;
}
