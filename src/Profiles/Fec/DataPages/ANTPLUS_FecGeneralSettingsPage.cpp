#include <Profiles/Fec/DataPages/ANTPLUS_FecGeneralSettingsPage.h>
#include <Profiles/Fec/ANTPLUS_FecPrivateDefines.h>

#define CYCLE_LENGTH_BYTE 3
#define INCLINE_LSB_BYTE 4
#define INCLINE_MSB_BYTE 5
#define RESISTANTCE_LEVEL_BYTE 6

template<class T>
FecBaseGeneralSettingsPage<T>::FecBaseGeneralSettingsPage() :
    CoreDataPage<T>() {}

template<class T>
uint8_t FecBaseGeneralSettingsPage<T>::getCycleLength() {
    return this->get8BitValue(CYCLE_LENGTH_BYTE);
}

template<class T>
uint16_t FecBaseGeneralSettingsPage<T>::getIncline() {
    return this->get16BitValue(INCLINE_LSB_BYTE, INCLINE_MSB_BYTE);
}

template<class T>
uint8_t FecBaseGeneralSettingsPage<T>::getResistanceLevel() {
    return this->get8BitValue(RESISTANTCE_LEVEL_BYTE);
}

template<class T>
uint8_t FecBaseGeneralSettingsPage<T>::getFeState() {
    return this->get8BitValue(FESTATE_BYTE, FESTATE_MASK, FESTATE_SHIFT);
}

template<class T>
uint8_t FecBaseGeneralSettingsPage<T>::getLapToggleBit() {
    return this->get8BitValue(LAPTOGGLEBIT_BYTE, LAPTOGGLEBIT_MASK, LAPTOGGLEBIT_SHIFT);
}

template class FecBaseGeneralSettingsPage<BroadcastData>;
template class FecBaseGeneralSettingsPage<BroadcastDataMsg>;

FecGeneralSettingsPage::FecGeneralSettingsPage(AntRxDataResponse& dp) :
    FecBaseMainDataPage(dp),
    FecBaseGeneralSettingsPage<BroadcastData>() {}

FecGeneralSettingsPageMsg::FecGeneralSettingsPageMsg() :
    FecBaseMainDataPageMsg(ANTPLUS_FEC_DATAPAGE_GENERALSETTINGSPAGE_NUMBER),
    FecBaseGeneralSettingsPage<BroadcastDataMsg>() {
    setCycleLength(ANTPLUS_FEC_DATAPAGE_GENERALSETTINGSPAGE_CYCLELENGTH_INVALID);
    setIncline(ANTPLUS_FEC_DATAPAGE_GENERALSETTINGSPAGE_INCLINE_INVALID);
    setResistanceLevel(ANTPLUS_FEC_DATAPAGE_GENERALSETTINGSPAGE_RESISTANCELEVEL_INVALID);
    setFeState(ANTPLUS_FEC_DATAPAGE_FESTATE_INUSE);
}

void FecGeneralSettingsPageMsg::setCycleLength(uint8_t cycleLength) {
    set8BitValue(cycleLength, CYCLE_LENGTH_BYTE);
}

void FecGeneralSettingsPageMsg::setIncline(uint16_t incline) {
    set16BitValue(incline, INCLINE_LSB_BYTE, INCLINE_MSB_BYTE);
}

void FecGeneralSettingsPageMsg::setResistanceLevel(uint8_t resistanceLevel) {
    set8BitValue(resistanceLevel, RESISTANTCE_LEVEL_BYTE);
}

void FecGeneralSettingsPageMsg::setFeState(uint8_t state) {
    set8BitValue(state, FESTATE_BYTE, FESTATE_MASK, FESTATE_SHIFT);
}

void FecGeneralSettingsPageMsg::setLapToggleBit(uint8_t bit) {
    set8BitValue(bit, LAPTOGGLEBIT_BYTE, LAPTOGGLEBIT_MASK, LAPTOGGLEBIT_SHIFT);
}
