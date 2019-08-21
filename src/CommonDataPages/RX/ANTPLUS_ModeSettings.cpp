#include <CommonDataPages/RX/ANTPLUS_ModeSettings.h>

ModeSettings::ModeSettings(AntRxDataResponse& dp) : BaseDataPage<BroadcastData>(dp), BaseModeSettings<BroadcastData>() {
}
