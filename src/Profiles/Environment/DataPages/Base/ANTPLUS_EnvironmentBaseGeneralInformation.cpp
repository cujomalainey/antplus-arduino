#include <Profiles/Environment/DataPages/RX/ANTPLUS_EnvironmentGeneralInformation.h>
#include <Profiles/Environment/ANTPLUS_EnvironmentPrivateDefines.h>

template<class T>
EnvironmentBaseGeneralInformation<T>::EnvironmentBaseGeneralInformation() : CoreDataPage<T>() {
}

template<class T>
uint8_t EnvironmentBaseGeneralInformation<T>::getTransmissionInfoLocalTime() {
    return this->get8BitValue(
            ANTPLUS_ENVIRONMENT_DATAPAGE_GENERALINFORMATION_TRANSMISSIONINFO_BYTE,
            ANTPLUS_ENVIRONMENT_DATAPAGE_GENERALINFORMATION_TRANSMISSIONINFO_LOCALTIME_MASK,
            ANTPLUS_ENVIRONMENT_DATAPAGE_GENERALINFORMATION_TRANSMISSIONINFO_LOCALTIME_SHIFT);
}

template<class T>
uint8_t EnvironmentBaseGeneralInformation<T>::getTransmissionInfoUtcTime() {
    return this->get8BitValue(
            ANTPLUS_ENVIRONMENT_DATAPAGE_GENERALINFORMATION_TRANSMISSIONINFO_BYTE,
            ANTPLUS_ENVIRONMENT_DATAPAGE_GENERALINFORMATION_TRANSMISSIONINFO_UTCTIME_MASK,
            ANTPLUS_ENVIRONMENT_DATAPAGE_GENERALINFORMATION_TRANSMISSIONINFO_UTCTIME_SHIFT);
}

template<class T>
uint8_t EnvironmentBaseGeneralInformation<T>::getTransmissionInfoDefaultTransmissionRate() {
    return this->get8BitValue(
            ANTPLUS_ENVIRONMENT_DATAPAGE_GENERALINFORMATION_TRANSMISSIONINFO_BYTE,
            ANTPLUS_ENVIRONMENT_DATAPAGE_GENERALINFORMATION_TRANSMISSIONINFO_DEFAULTTRANSMISSIONRATE_MASK);
}

template<class T>
uint32_t EnvironmentBaseGeneralInformation<T>::getSupportedPages() {
    return this->get32BitValue(
            ANTPLUS_ENVIRONMENT_DATAPAGE_GENERALINFORMATION_SUPPORTEDPAGES_LSB_BYTE,
            ANTPLUS_ENVIRONMENT_DATAPAGE_GENERALINFORMATION_SUPPORTEDPAGES_MSB_BYTE);
}

template class EnvironmentBaseGeneralInformation<BroadcastData>;
template class EnvironmentBaseGeneralInformation<BroadcastDataMsg>;
