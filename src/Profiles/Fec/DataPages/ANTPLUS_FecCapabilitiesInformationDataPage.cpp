#include <Profiles/Fec/DataPages/ANTPLUS_FecCapabilitiesInformationDataPage.h>
#include <Profiles/Fec/ANTPLUS_FecPrivateDefines.h>

#define MAX_RESISTANCE_LSB_BYTE 5
#define MAX_RESISTANCE_MSB_BYTE 6
#define FEC_CAPABILITIES_BYTE 7

template<class T>
FecBaseCapabilitiesInformationDatapage<T>::FecBaseCapabilitiesInformationDatapage() :
    CoreDataPage<T>() {}

template<class T>
uint16_t FecBaseCapabilitiesInformationDatapage<T>::getMaximumResistance() {
    return this->get16BitValue(MAX_RESISTANCE_LSB_BYTE, MAX_RESISTANCE_MSB_BYTE);
}

template<class T>
uint8_t FecBaseCapabilitiesInformationDatapage<T>::getCapabilities() {
    return this->get8BitValue(FEC_CAPABILITIES_BYTE);
}

template class FecBaseCapabilitiesInformationDatapage<BroadcastData>;
template class FecBaseCapabilitiesInformationDatapage<BroadcastDataMsg>;

FecCapabilitiesInformationDatapage::FecCapabilitiesInformationDatapage(AntRxDataResponse& dp) :
    FecBaseMainDataPage(dp),
    FecBaseCapabilitiesInformationDatapage<BroadcastData>() {}

FecCapabilitiesInformationMsg::FecCapabilitiesInformationMsg() :
    FecBaseMainDataPageMsg(ANTPLUS_FEC_USER_INFORMATION_NUMBER),
    FecBaseCapabilitiesInformationDatapage<BroadcastDataMsg>() {}

void FecCapabilitiesInformationMsg::setMaximumResistance(uint16_t MaximumResistance) {
    set16BitValue(MaximumResistance, MAX_RESISTANCE_LSB_BYTE, MAX_RESISTANCE_MSB_BYTE);
}

void FecCapabilitiesInformationMsg::setCapabitilies(uint8_t Capabilities) {
    set8BitValue(Capabilities, FEC_CAPABILITIES_BYTE);
}

