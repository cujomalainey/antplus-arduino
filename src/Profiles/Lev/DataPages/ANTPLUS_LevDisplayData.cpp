#include <Profiles/Lev/DataPages/ANTPLUS_LevDisplayData.h>
#include <Profiles/Lev/ANTPLUS_LevPrivateDefines.h>

#define WHEELCIRCUMFERENCE_LSB_BYTE    1
#define WHEELCIRCUMFERENCE_MSB_BYTE    2
#define WHEELCIRCUMFERENCE_MASK        0xFFF
#define RESERVED1_BYTE                 2
#define RESERVED1_VALUE                0xF0
#define RESERVED2_BYTE                 5
#define RESERVED2_VALUE                0
#define CURRENTASSISTLEVEL_BYTE        3
#define CURRENTASSISTLEVEL_MASK        0x38
#define CURRENTASSISTLEVEL_SHIFT       3
#define CURRENTREGENERATIVELEVEL_BYTE  3
#define CURRENTREGENERATIVELEVEL_MASK  0x7
#define CURRENTREARGEAR_LSB_BYTE       4
#define CURRENTREARGEAR_MSB_BYTE       5
#define CURRENTREARGEAR_MASK           0x3C0
#define CURRENTREARGEAR_SHIFT          6
#define CURRENTFRONTGEAR_BYTE          4
#define CURRENTFRONTGEAR_MASK          0x30
#define CURRENTFRONTGEAR_SHIFT         4
#define CURRENTLIGHTMODE_BYTE          4
#define CURRENTLIGHTMODE_MASK          0xF
#define MANUFACTURERID_LSB_BYTE        6
#define MANUFACTURERID_MSB_BYTE        7

LevDisplayDataMsg::LevDisplayDataMsg() : LevBaseMainDataPageMsg(DISPLAYDATA_NUMBER) {
    set8BitValue(RESERVED1_VALUE, RESERVED1_BYTE);
    set8BitValue(RESERVED2_VALUE, RESERVED2_BYTE);
}

uint16_t LevDisplayDataMsg::getWheelCircumference() {
    return this->get16BitValue(WHEELCIRCUMFERENCE_LSB_BYTE,
            WHEELCIRCUMFERENCE_MSB_BYTE, WHEELCIRCUMFERENCE_MASK);
}

uint8_t LevDisplayDataMsg::getCurrentAssistLevel() {
    return this->get8BitValue(CURRENTASSISTLEVEL_BYTE, CURRENTASSISTLEVEL_MASK,
            CURRENTASSISTLEVEL_SHIFT);
}

uint8_t LevDisplayDataMsg::getCurrentRegenerativeLevel() {
    return this->get8BitValue(CURRENTREGENERATIVELEVEL_BYTE,
            CURRENTREGENERATIVELEVEL_MASK);
}

uint8_t LevDisplayDataMsg::getCurrentRearGear() {
    // This is a 16 bit call because the 4 bits spans 2 bytes
    return (uint8_t)this->get16BitValue(CURRENTREARGEAR_LSB_BYTE,
            CURRENTREARGEAR_MSB_BYTE, CURRENTREARGEAR_MASK,
            CURRENTREARGEAR_SHIFT);
}

uint8_t LevDisplayDataMsg::getCurrentFrontGear() {
    return this->get8BitValue(CURRENTFRONTGEAR_BYTE, CURRENTFRONTGEAR_MASK,
            CURRENTFRONTGEAR_SHIFT);
}

// TODO break apart bitfield
uint8_t LevDisplayDataMsg::getCurrentLightMode() {
    return this->get8BitValue(CURRENTLIGHTMODE_BYTE, CURRENTLIGHTMODE_MASK);
}

uint16_t LevDisplayDataMsg::getManufacturerID() {
    return this->get16BitValue(MANUFACTURERID_LSB_BYTE, MANUFACTURERID_MSB_BYTE);
}

void LevDisplayDataMsg::setWheelCircumference(uint16_t circumference) {
    set16BitValue(circumference, WHEELCIRCUMFERENCE_LSB_BYTE,
            WHEELCIRCUMFERENCE_MSB_BYTE, WHEELCIRCUMFERENCE_MASK);
}

void LevDisplayDataMsg::setCurrentAssistLevel(uint8_t level) {
    set8BitValue(level, CURRENTASSISTLEVEL_BYTE, CURRENTASSISTLEVEL_MASK,
            CURRENTASSISTLEVEL_SHIFT);
}

void LevDisplayDataMsg::setCurrentRegenerativeLevel(uint8_t level) {
    set8BitValue(level, CURRENTREGENERATIVELEVEL_BYTE,
            CURRENTREGENERATIVELEVEL_MASK);
}

void LevDisplayDataMsg::setCurrentRearGear(uint8_t gear) {
    set16BitValue(gear, CURRENTREARGEAR_LSB_BYTE, CURRENTREARGEAR_MSB_BYTE,
            CURRENTREARGEAR_MASK, CURRENTREARGEAR_SHIFT);
}

void LevDisplayDataMsg::setCurrentFrontGear(uint8_t gear) {
    set8BitValue(gear, CURRENTFRONTGEAR_BYTE, CURRENTFRONTGEAR_MASK,
            CURRENTFRONTGEAR_SHIFT);
}

void LevDisplayDataMsg::setCurrentLightMode(uint8_t state) {
    set8BitValue(state, CURRENTLIGHTMODE_BYTE, CURRENTLIGHTMODE_MASK);
}

void LevDisplayDataMsg::setManufacturerID(uint16_t id) {
    set16BitValue(id, MANUFACTURERID_LSB_BYTE, MANUFACTURERID_MSB_BYTE);
}
