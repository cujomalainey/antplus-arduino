#include <CommonDataPages/Base/ANTPLUS_BaseModeSettings.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>

template<class T>
BaseModeSettings<T>::BaseModeSettings() : CoreDataPage<T>() {
}

template<class T>
uint8_t BaseModeSettings<T>::getSportMode() {
    return this->get8BitValue(
            ANTPLUS_COMMON_DATAPAGE_MODESETTINGS_SPORTSMODE_BYTE);
}

template class BaseModeSettings<BroadcastData>;
template class BaseModeSettings<BroadcastDataMsg>;
