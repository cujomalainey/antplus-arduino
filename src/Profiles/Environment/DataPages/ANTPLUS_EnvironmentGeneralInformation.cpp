#include <Profiles/Environment/DataPages/ANTPLUS_EnvironmentGeneralInformation.h>
#include <Profiles/Environment/ANTPLUS_EnvironmentPrivateDefines.h>

#define TRANSMISSIONINFO_BYTE 3
#define TRANSMISSIONINFO_LOCALTIME_MASK 0x30
#define TRANSMISSIONINFO_UTCTIME_MASK 0x0C
#define TRANSMISSIONINFO_DEFAULTTRANSMISSIONRATE_MASK 0x03
#define TRANSMISSIONINFO_LOCALTIME_SHIFT 4
#define TRANSMISSIONINFO_UTCTIME_SHIFT 2
#define SUPPORTEDPAGES_LSB_BYTE 4
#define SUPPORTEDPAGES_MSB_BYTE 7

template<class T>
EnvironmentBaseGeneralInformation<T>::EnvironmentBaseGeneralInformation() :
    CoreDataPage<T>() {}

template<class T>
uint8_t EnvironmentBaseGeneralInformation<T>::getTransmissionInfoLocalTime() {
    return this->get8BitValue(TRANSMISSIONINFO_BYTE,
            TRANSMISSIONINFO_LOCALTIME_MASK, TRANSMISSIONINFO_LOCALTIME_SHIFT);
}

template<class T>
uint8_t EnvironmentBaseGeneralInformation<T>::getTransmissionInfoUtcTime() {
    return this->get8BitValue(TRANSMISSIONINFO_BYTE,
            TRANSMISSIONINFO_UTCTIME_MASK, TRANSMISSIONINFO_UTCTIME_SHIFT);
}

template<class T>
uint8_t EnvironmentBaseGeneralInformation<T>::getTransmissionInfoDefaultTransmissionRate() {
    return this->get8BitValue(TRANSMISSIONINFO_BYTE,
            TRANSMISSIONINFO_DEFAULTTRANSMISSIONRATE_MASK);
}

template<class T>
uint32_t EnvironmentBaseGeneralInformation<T>::getSupportedPages() {
    return this->get32BitValue(SUPPORTEDPAGES_LSB_BYTE,
            SUPPORTEDPAGES_MSB_BYTE);
}

template class EnvironmentBaseGeneralInformation<BroadcastData>;
template class EnvironmentBaseGeneralInformation<BroadcastDataMsg>;

EnvironmentGeneralInformation::EnvironmentGeneralInformation(AntRxDataResponse& dp) :
    EnvironmentBaseDataPage(dp),
    EnvironmentBaseGeneralInformation<BroadcastData>() {}
