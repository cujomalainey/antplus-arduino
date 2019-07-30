#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseCapabilities.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

template<class T>
HeartRateBaseCapabilities<T>::HeartRateBaseCapabilities() : CoreDataPage<T>() {
}

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
