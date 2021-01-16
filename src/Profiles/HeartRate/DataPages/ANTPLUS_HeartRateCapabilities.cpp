#include <Profiles/HeartRate/DataPages/ANTPLUS_HeartRateCapabilities.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

template<class T>
HeartRateBaseCapabilities<T>::HeartRateBaseCapabilities() : CoreDataPage<T>() {}

template<class T>
uint8_t HeartRateBaseCapabilities<T>::getFeaturesSupported() {
    return this->get8BitValue(
            ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_FEATURESSUPPORTED_BYTE);
}

template<class T>
uint8_t HeartRateBaseCapabilities<T>::getFeaturesEnabled() {
    return this->get8BitValue(
            ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_FEATURESENABLED_BYTE);
}

template class HeartRateBaseCapabilities<BroadcastData>;
template class HeartRateBaseCapabilities<BroadcastDataMsg>;

HeartRateCapabilities::HeartRateCapabilities(AntRxDataResponse& dp) : HeartRateBaseMainDataPage(dp), HeartRateBaseCapabilities<BroadcastData>() {}

HeartRateCapabilitiesMsg::HeartRateCapabilitiesMsg() : HeartRateBaseMainDataPageMsg(ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_NUMBER), HeartRateBaseCapabilities<BroadcastDataMsg>() {}

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
