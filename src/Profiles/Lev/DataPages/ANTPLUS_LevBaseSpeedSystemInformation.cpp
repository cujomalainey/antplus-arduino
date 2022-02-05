#include <Profiles/Lev/DataPages/ANTPLUS_LevBaseSpeedSystemInformation.h>
#include <Profiles/Lev/ANTPLUS_LevPrivateDefines.h>

#define TRAVELMODESTATE_BYTE                           2
#define TRAVELMODESTATE_CURRENTREGENERATIVELEVEL_MASK  0x7
#define TRAVELMODESTATE_CURRENTASSISTLEVEL_SHIFT       3
#define TRAVELMODESTATE_CURRENTASSISTLEVEL_MASK        0x38
#define SYSTEMSTATE_BYTE                               3
#define GEARSTATE_BYTE                                 4
#define GEARSTATE_CURRENTFRONTGEAR_MASK                0x3
#define GEARSTATE_CURRENTREARGEAR_SHIFT                2
#define GEARSTATE_CURRENTREARGEAR_MASK                 0x3C
#define GEARSTATE_MANUALAUTO_SHIFT                     6
#define GEARSTATE_MANUALAUTO_MASK                      0x40
#define GEARSTATE_GEAREXIST_SHIFT                      7
#define GEARSTATE_GEAREXIST_MASK                       0x80
#define LEVSPEED_LSB_BYTE                              6
#define LEVSPEED_MSB_BYTE                              7
#define LEVSPEED_MASK                                  0x0FFF

template<class T>
LevCoreSpeedSystemInformation<T>::LevCoreSpeedSystemInformation() :
    CoreDataPage<T>() {}

template<class T>
uint8_t LevCoreSpeedSystemInformation<T>::getCurrentRegenerativeLevel() {
    return this->get8BitValue(TRAVELMODESTATE_BYTE,
            TRAVELMODESTATE_CURRENTREGENERATIVELEVEL_MASK);
}

template<class T>
uint8_t LevCoreSpeedSystemInformation<T>::getCurrentAssistLevel() {
    return this->get8BitValue(TRAVELMODESTATE_BYTE,
            TRAVELMODESTATE_CURRENTASSISTLEVEL_MASK,
            TRAVELMODESTATE_CURRENTASSISTLEVEL_SHIFT);
}

template<class T>
uint8_t LevCoreSpeedSystemInformation<T>::getSystemState() {
    return this->get8BitValue(SYSTEMSTATE_BYTE);
}

template<class T>
uint8_t LevCoreSpeedSystemInformation<T>::getCurrentFrontGear() {
    return this->get8BitValue(GEARSTATE_BYTE, GEARSTATE_CURRENTFRONTGEAR_MASK);
}

template<class T>
uint8_t LevCoreSpeedSystemInformation<T>::getCurrentRearGear() {
    return this->get8BitValue(GEARSTATE_BYTE, GEARSTATE_CURRENTREARGEAR_MASK,
            GEARSTATE_CURRENTREARGEAR_SHIFT);
}

template<class T>
uint8_t LevCoreSpeedSystemInformation<T>::getManualAutoState() {
    return this->get8BitValue(GEARSTATE_BYTE, GEARSTATE_MANUALAUTO_MASK,
            GEARSTATE_MANUALAUTO_SHIFT);
}

template<class T>
uint8_t LevCoreSpeedSystemInformation<T>::getGearExist() {
    return this->get8BitValue(GEARSTATE_BYTE, GEARSTATE_GEAREXIST_MASK,
            GEARSTATE_GEAREXIST_SHIFT);
}

template<class T>
uint16_t LevCoreSpeedSystemInformation<T>::getSpeed() { // in 1/10 km/h
    return this->get16BitValue(LEVSPEED_LSB_BYTE, LEVSPEED_MSB_BYTE,
            LEVSPEED_MASK);
}

template class LevCoreSpeedSystemInformation<BroadcastData>;
template class LevCoreSpeedSystemInformation<BroadcastDataMsg>;

LevBaseSpeedSystemInformation::LevBaseSpeedSystemInformation(AntRxDataResponse& dp) :
    LevBaseMainDataPage(dp),
    LevCoreSpeedSystemInformation<BroadcastData>() {}

LevBaseSpeedSystemInformationMsg::LevBaseSpeedSystemInformationMsg(uint8_t dataPageNumber) :
    LevBaseMainDataPageMsg<BroadcastDataMsg>(dataPageNumber),
    LevCoreSpeedSystemInformation<BroadcastDataMsg>() {}

void LevBaseSpeedSystemInformationMsg::setCurrentRegenerativeLevel(uint8_t level) {
    set8BitValue(level, TRAVELMODESTATE_BYTE,
            TRAVELMODESTATE_CURRENTREGENERATIVELEVEL_MASK);
}

void LevBaseSpeedSystemInformationMsg::setCurrentAssistLevel(uint8_t level) {
    set8BitValue(level, TRAVELMODESTATE_BYTE,
            TRAVELMODESTATE_CURRENTASSISTLEVEL_MASK,
            TRAVELMODESTATE_CURRENTASSISTLEVEL_SHIFT);
}

void LevBaseSpeedSystemInformationMsg::setSystemState(uint8_t state) {
    set8BitValue(state, SYSTEMSTATE_BYTE);
}

void LevBaseSpeedSystemInformationMsg::setCurrentFrontGear(uint8_t gear) {
    set8BitValue(gear, GEARSTATE_BYTE, GEARSTATE_CURRENTFRONTGEAR_MASK);
}

void LevBaseSpeedSystemInformationMsg::setCurrentRearGear(uint8_t gear) {
    set8BitValue(gear, GEARSTATE_BYTE, GEARSTATE_CURRENTREARGEAR_MASK,
            GEARSTATE_CURRENTREARGEAR_SHIFT);
}

void LevBaseSpeedSystemInformationMsg::setManualAutoState(uint8_t state) {
    set8BitValue(state, GEARSTATE_BYTE, GEARSTATE_MANUALAUTO_MASK,
            GEARSTATE_MANUALAUTO_SHIFT);
}

void LevBaseSpeedSystemInformationMsg::setGearExist(uint8_t exists) {
    set8BitValue(exists, GEARSTATE_BYTE, GEARSTATE_GEAREXIST_MASK,
            GEARSTATE_GEAREXIST_SHIFT);
}

void LevBaseSpeedSystemInformationMsg::setSpeed(uint16_t speed) { // in 1/10 km/h
    set16BitValue(speed, LEVSPEED_LSB_BYTE, LEVSPEED_MSB_BYTE,
            LEVSPEED_MASK);
}
