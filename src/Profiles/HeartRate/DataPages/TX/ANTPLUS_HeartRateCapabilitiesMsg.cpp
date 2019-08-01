#include <Profiles/HeartRate/DataPages/TX/ANTPLUS_HeartRateCapabilitiesMsg.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

HeartRateCapabilitiesMsg::HeartRateCapabilitiesMsg() : HeartRateBaseMainDataPageMsg(ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_NUMBER), HeartRateBaseCapabilities<BroadcastDataMsg>() {
}

void HeartRateCapabilitiesMsg::setFeaturesSupported(uint8_t supported) {
    set8BitValue(supported,
            ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_FEATURESSUPPORTED_BYTE,
            ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_FEATURES_MASK);
}

void HeartRateCapabilitiesMsg::setFeaturesEnabled(uint8_t enabled) {
    set8BitValue(enabled,
            ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_FEATURESENABLED_BYTE,
            ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_FEATURES_MASK);
}
