#include <CommonDataPages/RX/ANTPLUS_ModeSettings.h>
#include <CommonDataPages/ANTPLUS_CommonDataPageDefines.h>

ModeSettings::ModeSettings(BroadcastData& dp) : BaseDataPage<BroadcastData>(dp) {

}

uint8_t ModeSettings::getSportMode() {
    return getData(ANTPLUS_COMMON_DATAPAGE_MODESETTINGS_SPORTSMODE_BYTE);
}
