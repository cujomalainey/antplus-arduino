#include <Profiles/HeartRate/DataPages/ANTPLUS_HeartRateCapabilities.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

#define FEATURESSUPPORTED_BYTE 2
#define FEATURESENABLED_BYTE   3
#define FEATURES_MASK 0xC7

template<class T>
HeartRateBaseCapabilities<T>::HeartRateBaseCapabilities() :
    CoreDataPage<T>() {}

template<class T>
uint8_t HeartRateBaseCapabilities<T>::getFeaturesSupported() {
    return this->get8BitValue(FEATURESSUPPORTED_BYTE);
}

template<class T>
uint8_t HeartRateBaseCapabilities<T>::getFeaturesEnabled() {
    return this->get8BitValue(FEATURESENABLED_BYTE);
}

template class HeartRateBaseCapabilities<BroadcastData>;
template class HeartRateBaseCapabilities<BroadcastDataMsg>;

HeartRateCapabilities::HeartRateCapabilities(AntRxDataResponse& dp) :
    HeartRateBaseMainDataPage(dp),
    HeartRateBaseCapabilities<BroadcastData>() {}

HeartRateCapabilitiesMsg::HeartRateCapabilitiesMsg() :
    HeartRateBaseMainDataPageMsg(HEARTRATE_CAPABILITIES_NUMBER),
    HeartRateBaseCapabilities<BroadcastDataMsg>() {}

void HeartRateCapabilitiesMsg::setFeaturesSupported(uint8_t supported) {
    set8BitValue(supported, FEATURESSUPPORTED_BYTE, FEATURES_MASK);
}

void HeartRateCapabilitiesMsg::setFeaturesEnabled(uint8_t enabled) {
    set8BitValue(enabled, FEATURESENABLED_BYTE, FEATURES_MASK);
}
