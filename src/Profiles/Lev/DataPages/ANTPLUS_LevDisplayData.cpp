#include <Profiles/Lev/DataPages/ANTPLUS_LevDisplayData.h>
#include <Profiles/Lev/ANTPLUS_LevDefines.h>

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
#define DISPLAYCOMMAND_BYTE            4
#define DISPLAYCOMMANDTURNSIGNALRIGHT_MASK  0x1
#define DISPLAYCOMMANDTURNSIGNALLEFT_MASK   0x2
#define DISPLAYCOMMANDTURNSIGNALLEFT_SHIFT  1
#define DISPLAYCOMMANDLIGHTHIGHBEAM_MASK    0x4
#define DISPLAYCOMMANDLIGHTHIGHBEAM_SHIFT   2
#define DISPLAYCOMMANDLIGHTONFOFF_MASK      0x8
#define DISPLAYCOMMANDLIGHTONFOFF_SHIFT     3
#define MANUFACTURERID_LSB_BYTE        6
#define MANUFACTURERID_MSB_BYTE        7

template<class T>
LevBaseDisplayData<T>::LevBaseDisplayData() : CoreDataPage<T>() {}

template<class T>
uint16_t LevBaseDisplayData<T>::getWheelCircumference() {
    return this->get16BitValue(WHEELCIRCUMFERENCE_LSB_BYTE,
            WHEELCIRCUMFERENCE_MSB_BYTE, WHEELCIRCUMFERENCE_MASK);
}

template<class T>
uint8_t LevBaseDisplayData<T>::getCurrentAssistLevel() {
    return this->get8BitValue(CURRENTASSISTLEVEL_BYTE, CURRENTASSISTLEVEL_MASK,
            CURRENTASSISTLEVEL_SHIFT);
}

template<class T>
uint8_t LevBaseDisplayData<T>::getCurrentRegenerativeLevel() {
    return this->get8BitValue(CURRENTREGENERATIVELEVEL_BYTE,
            CURRENTREGENERATIVELEVEL_MASK);
}

template<class T>
uint8_t LevBaseDisplayData<T>::getCurrentRearGear() {
    // This is a 16 bit call because the 4 bits spans 2 bytes
    return (uint8_t)this->get16BitValue(CURRENTREARGEAR_LSB_BYTE,
            CURRENTREARGEAR_MSB_BYTE, CURRENTREARGEAR_MASK,
            CURRENTREARGEAR_SHIFT);
}

template<class T>
uint8_t LevBaseDisplayData<T>::getCurrentFrontGear() {
    return this->get8BitValue(CURRENTFRONTGEAR_BYTE, CURRENTFRONTGEAR_MASK,
            CURRENTFRONTGEAR_SHIFT);
}

template<class T>
bool LevBaseDisplayData<T>::getDisplayCommandTurnSignalRight() {
    return this->get8BitValue(DISPLAYCOMMAND_BYTE,
            DISPLAYCOMMANDTURNSIGNALRIGHT_MASK);
}

template<class T>
bool LevBaseDisplayData<T>::getDisplayCommandTurnSignalLeft() {
    return this->get8BitValue(DISPLAYCOMMAND_BYTE,
            DISPLAYCOMMANDTURNSIGNALLEFT_MASK,
            DISPLAYCOMMANDTURNSIGNALLEFT_SHIFT);
}

template<class T>
bool LevBaseDisplayData<T>::getDisplayCommandLightHighBeam() {
    return this->get8BitValue(DISPLAYCOMMAND_BYTE,
            DISPLAYCOMMANDLIGHTHIGHBEAM_MASK,
            DISPLAYCOMMANDLIGHTHIGHBEAM_SHIFT);
}

template<class T>
bool LevBaseDisplayData<T>::getDisplayCommandLightOnOff() {
    return this->get8BitValue(DISPLAYCOMMAND_BYTE,
            DISPLAYCOMMANDLIGHTONFOFF_MASK,
            DISPLAYCOMMANDLIGHTONFOFF_SHIFT);
}

template<class T>
uint16_t LevBaseDisplayData<T>::getManufacturerID() {
    return this->get16BitValue(MANUFACTURERID_LSB_BYTE, MANUFACTURERID_MSB_BYTE);
}

template class LevBaseDisplayData<AcknowledgedData>;
template class LevBaseDisplayData<AcknowledgedDataMsg>;

LevDisplayDataMsg::LevDisplayDataMsg() :
    LevBaseMainDataPageMsg<AcknowledgedDataMsg>(ANTPLUS_LEV_DATAPAGE_DISPLAYDATA_NUMBER),
    LevBaseDisplayData() {
    set8BitValue(RESERVED1_VALUE, RESERVED1_BYTE);
    set8BitValue(RESERVED2_VALUE, RESERVED2_BYTE);
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

void LevDisplayDataMsg::setDisplayCommandTurnSignalRight(bool rightSignal) {
    set8BitValue(rightSignal, DISPLAYCOMMAND_BYTE,
            DISPLAYCOMMANDTURNSIGNALRIGHT_MASK);
}

void LevDisplayDataMsg::setDisplayCommandTurnSignalLeft(bool leftSignal) {
    set8BitValue(leftSignal, DISPLAYCOMMAND_BYTE,
            DISPLAYCOMMANDTURNSIGNALLEFT_MASK,
            DISPLAYCOMMANDTURNSIGNALLEFT_SHIFT);
}

void LevDisplayDataMsg::setDisplayCommandLightHighBeam(bool highBeam) {
    set8BitValue(highBeam, DISPLAYCOMMAND_BYTE,
            DISPLAYCOMMANDLIGHTHIGHBEAM_MASK,
            DISPLAYCOMMANDLIGHTHIGHBEAM_SHIFT);
}

void LevDisplayDataMsg::setDisplayCommandLightOnOff(bool onOff) {
    set8BitValue(onOff, DISPLAYCOMMAND_BYTE,
            DISPLAYCOMMANDLIGHTONFOFF_MASK,
            DISPLAYCOMMANDLIGHTONFOFF_SHIFT);
}

void LevDisplayDataMsg::setManufacturerID(uint16_t id) {
    set16BitValue(id, MANUFACTURERID_LSB_BYTE, MANUFACTURERID_MSB_BYTE);
}
