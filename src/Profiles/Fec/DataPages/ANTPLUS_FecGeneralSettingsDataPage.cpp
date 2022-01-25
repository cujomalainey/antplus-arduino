#include <Profiles/Fec/DataPages/ANTPLUS_FecGeneralSettingsDataPage.h>
#include <Profiles/Fec/ANTPLUS_FecPrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

// TODO this is a mixture of datapages
#define CYCLE_LENGTH_BYTE 3
#define INCLINE_LSB_BYTE 4
#define INCLINE_MSB_BYTE 5
#define RESISTANTCE_LEVEL_BYTE 6
#define CAPABILITIESBITFIELD_BYTE 7
#define CAPABILITIESBITFIELD_MASK 0x0F
#define FESTATEBITFIELD_BYTE  7
#define FESTATEBITFIELD_MASK  0xF0
#define FESTATEBITFIELD_SHIFT 4

template<class T>
FecBaseGeneralSettingsDataPage<T>::FecBaseGeneralSettingsDataPage() :
    CoreDataPage<T>() {}

template<class T>
uint8_t FecBaseGeneralSettingsDataPage<T>::getCycleLength() {
    return this->get8BitValue(CYCLE_LENGTH_BYTE);
}

template<class T>
uint8_t FecBaseGeneralSettingsDataPage<T>::getInclineValue() {
    return this->get16BitValue(INCLINE_MSB_BYTE, INCLINE_LSB_BYTE);
}

template<class T>
uint8_t FecBaseGeneralSettingsDataPage<T>::getResistanceLevel() {
    return this->get8BitValue(RESISTANTCE_LEVEL_BYTE);
}

template<class T>
uint8_t FecBaseGeneralSettingsDataPage<T>::getCapabilitiesBits() {
    return this->get8BitValue(CAPABILITIESBITFIELD_BYTE,
            CAPABILITIESBITFIELD_MASK);
}

template<class T>
uint8_t FecBaseGeneralSettingsDataPage<T>::getFEStateBits() {
    return this->get8BitValue(FESTATEBITFIELD_BYTE, FESTATEBITFIELD_MASK,
            FESTATEBITFIELD_SHIFT);
}

template class FecBaseGeneralSettingsDataPage<BroadcastData>;
template class FecBaseGeneralSettingsDataPage<BroadcastDataMsg>;

FecGeneralSettingsDataPage::FecGeneralSettingsDataPage(AntRxDataResponse& dp) :
    FecBaseMainDataPage(dp),
    FecBaseGeneralSettingsDataPage<BroadcastData>() {}

FecGeneralSettingsDataMsg::FecGeneralSettingsDataMsg() :
    FecBaseMainDataPageMsg(ANTPLUS_FEC_GENERAL_SETTINGS_NUMBER),
    FecBaseGeneralSettingsDataPage<BroadcastDataMsg>() {}

void FecGeneralSettingsDataMsg::setResistanceLevel(uint8_t ResistanceLevel) {
    set8BitValue(ResistanceLevel, RESISTANTCE_LEVEL_BYTE);
}
