#include <CommonDataPages/ANTPLUS_ModeSettings.h>
#include <CommonDataPages/ANTPLUS_CommonDataPageDefines.h>
#include <ANTPLUS_PrivateDefines.h>

#define SPORTSMODE_BYTE     7
#define RESERVED_BYTE       0xFF

template<class T>
BaseModeSettings<T>::BaseModeSettings() : CoreDataPage<T>() {}

template<class T>
uint8_t BaseModeSettings<T>::getSportMode() {
    return this->get8BitValue(SPORTSMODE_BYTE);
}

template class BaseModeSettings<BroadcastData>;
template class BaseModeSettings<BroadcastDataMsg>;

ModeSettings::ModeSettings(AntRxDataResponse& dp) :
    BaseDataPage<BroadcastData>(dp),
    BaseModeSettings<BroadcastData>() {}

ModeSettingsMsg::ModeSettingsMsg() :
    BaseDataPageMsg<BroadcastDataMsg>(),
    BaseModeSettings<BroadcastDataMsg>() {
    setDataBuffer(_buffer);
    set8BitValue(ANTPLUS_COMMON_DATAPAGE_MODESETTINGS_NUMBER, ANTPLUS_DEFAULT_DATAPAGE_BYTE);
    set8BitValue(RESERVED_BYTE, 1);
    set8BitValue(RESERVED_BYTE, 2);
    set8BitValue(RESERVED_BYTE, 3);
    set8BitValue(RESERVED_BYTE, 4);
    set8BitValue(RESERVED_BYTE, 5);
    set8BitValue(RESERVED_BYTE, 6);
}

void ModeSettingsMsg::setSportMode(uint8_t sportsMode) {
    set8BitValue(sportsMode, SPORTSMODE_BYTE);
}
