#include <CommonDataPages/ANTPLUS_ModeSettings.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>

#define SPORTSMODE_BYTE     7

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

// TODO ModeSettingsMsg
