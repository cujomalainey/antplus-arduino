#include <Profiles/Lev/DataPages/ANTPLUS_LevSpeedSystemInformation2.h>
#include <Profiles/Lev/ANTPLUS_LevDefines.h>

#define BATTERYSOC_BYTE                      1
#define BATTERYSOC_STATEOFCHARGE_MASK        0x7F
#define BATTERYSOC_BATTERYEMPTY_SHIFT        7
#define BATTERYSOC_BATTERYEMPTY_MASK         0x80
#define PERCENTASSIST_BYTE                   5

template<class T>
LevBaseSpeedSystemInformation2<T>::LevBaseSpeedSystemInformation2() :
    CoreDataPage<T>() {}

template<class T>
uint8_t LevBaseSpeedSystemInformation2<T>::getBatterySOC() {
    return this->get8BitValue(BATTERYSOC_BYTE, BATTERYSOC_STATEOFCHARGE_MASK);
}

template<class T>
uint8_t LevBaseSpeedSystemInformation2<T>::getBatteryEmptyWarning() {
    return this->get8BitValue(BATTERYSOC_BYTE,
            BATTERYSOC_BATTERYEMPTY_MASK,
            BATTERYSOC_BATTERYEMPTY_SHIFT);
}

template<class T>
uint8_t LevBaseSpeedSystemInformation2<T>::getPercentAssist() {
    return this->get8BitValue(PERCENTASSIST_BYTE);
}

template class LevBaseSpeedSystemInformation2<BroadcastData>;
template class LevBaseSpeedSystemInformation2<BroadcastDataMsg>;

LevSpeedSystemInformation2::LevSpeedSystemInformation2(AntRxDataResponse& dp) :
    LevBaseSpeedSystemInformation(dp),
    LevBaseSpeedSystemInformation2<BroadcastData>() {}

LevSpeedSystemInformation2Msg::LevSpeedSystemInformation2Msg() :
    LevBaseSpeedSystemInformationMsg(ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION2_NUMBER),
    LevBaseSpeedSystemInformation2<BroadcastDataMsg>() {}

void LevSpeedSystemInformation2Msg::setBatterySOC(uint8_t soc) {
    set8BitValue(soc, BATTERYSOC_BYTE, BATTERYSOC_STATEOFCHARGE_MASK);
}

void LevSpeedSystemInformation2Msg::setBatteryEmptyWarning(uint8_t warning) {
    set8BitValue(warning, BATTERYSOC_BYTE, BATTERYSOC_BATTERYEMPTY_MASK,
            BATTERYSOC_BATTERYEMPTY_SHIFT);
}

void LevSpeedSystemInformation2Msg::setPercentAssist(uint8_t percent) {
    set8BitValue(percent, PERCENTASSIST_BYTE);
}
