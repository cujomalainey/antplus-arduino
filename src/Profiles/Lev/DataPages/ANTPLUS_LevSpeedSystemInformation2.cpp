#include <Profiles/Lev/DataPages/ANTPLUS_LevSpeedSystemInformation2.h>
#include <Profiles/Lev/ANTPLUS_LevPrivateDefines.h>

#define BATTERYSOC_BYTE                      1
#define BATTERYSOC_STATEOFCHARGE_MASK        0x7F
#define BATTERYSOC_BATTERYEMPTY_SHIFT        7
#define BATTERYSOC_BATTERYEMPTY_MASK         0x80
#define PERCENTASSIST_BYTE                   5

LevSpeedSystemInformation2::LevSpeedSystemInformation2(AntRxDataResponse& dp) :
    LevBaseSpeedSystemInformation(dp) {}

uint8_t LevSpeedSystemInformation2::getBatterySOC() {
    return this->get8BitValue(BATTERYSOC_BYTE, BATTERYSOC_STATEOFCHARGE_MASK);
}

uint8_t LevSpeedSystemInformation2::getBatteryEmptyWarning() {
    return this->get8BitValue(BATTERYSOC_BYTE, BATTERYSOC_BATTERYEMPTY_MASK, BATTERYSOC_BATTERYEMPTY_SHIFT);
}

uint8_t LevSpeedSystemInformation2::getPercentAssist() {
    return this->get8BitValue(PERCENTASSIST_BYTE);
}
