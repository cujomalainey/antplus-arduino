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

LevBaseSpeedSystemInformation::LevBaseSpeedSystemInformation(AntRxDataResponse& dp) :
    LevBaseMainDataPage(dp) {}

uint8_t LevBaseSpeedSystemInformation::getCurrentRegenerativeLevel() {
    return this->get8BitValue(TRAVELMODESTATE_BYTE,
            TRAVELMODESTATE_CURRENTREGENERATIVELEVEL_MASK);
}

uint8_t LevBaseSpeedSystemInformation::getCurrentAssistLevel() {
    return this->get8BitValue(TRAVELMODESTATE_BYTE,
            TRAVELMODESTATE_CURRENTASSISTLEVEL_MASK,
            TRAVELMODESTATE_CURRENTASSISTLEVEL_SHIFT);
}

uint8_t LevBaseSpeedSystemInformation::getSystemState() {
    return this->get8BitValue(SYSTEMSTATE_BYTE);
}

uint8_t LevBaseSpeedSystemInformation::getCurrentFrontGear() {
    return this->get8BitValue(GEARSTATE_BYTE, GEARSTATE_CURRENTFRONTGEAR_MASK);
}

uint8_t LevBaseSpeedSystemInformation::getCurrentRearGear() {
    return this->get8BitValue(GEARSTATE_BYTE, GEARSTATE_CURRENTREARGEAR_MASK,
            GEARSTATE_CURRENTREARGEAR_SHIFT);
}

uint8_t LevBaseSpeedSystemInformation::getManualAutoState() {
    return this->get8BitValue(GEARSTATE_BYTE, GEARSTATE_MANUALAUTO_MASK,
            GEARSTATE_MANUALAUTO_SHIFT);
}

uint8_t LevBaseSpeedSystemInformation::getGearExist() {
    return this->get8BitValue(GEARSTATE_BYTE, GEARSTATE_GEAREXIST_MASK,
            GEARSTATE_GEAREXIST_SHIFT);
}

uint16_t LevBaseSpeedSystemInformation::getSpeed() { // in 1/10 km/h
    return this->get16BitValue(LEVSPEED_LSB_BYTE, LEVSPEED_MSB_BYTE,
            LEVSPEED_MASK);
}
