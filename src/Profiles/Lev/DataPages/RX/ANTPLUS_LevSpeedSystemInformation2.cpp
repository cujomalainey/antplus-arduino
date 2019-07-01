#include <Profiles/Lev/DataPages/RX/ANTPLUS_LevSpeedSystemInformation2.h>
#include <Profiles/Lev/ANTPLUS_LevPrivateDefines.h>

LevSpeedSystemInformation2::LevSpeedSystemInformation2(AntRxDataResponse& dp) : LevBaseSpeedSystemInformation(dp) {
}

uint8_t LevSpeedSystemInformation2::getBatterySOC() {
    return getData(ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION2_BATTERYSOC_BYTE);
}

uint8_t LevSpeedSystemInformation2::getBatteryEmptyWarning() {
    return getData(ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION2_BATTERYSOC_BYTE);
}

uint8_t LevSpeedSystemInformation2::getPercentAssist() {
    return getData(5);
}
