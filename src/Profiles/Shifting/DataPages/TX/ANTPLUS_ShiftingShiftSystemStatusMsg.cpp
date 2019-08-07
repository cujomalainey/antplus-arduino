#include <Profiles/Shifting/DataPages/TX/ANTPLUS_ShiftingShiftSystemStatusMsg.h>
#include <Profiles/Shifting/ANTPLUS_ShiftingPrivateDefines.h>

ShiftingShiftSystemStatusMsg::ShiftingShiftSystemStatusMsg() : ShiftingBaseMainDataPageMsg(ANTPLUS_SHIFTING_DATAPAGE_SHIFTSYSTEMSTATUS_NUMBER), ShiftingBaseShiftSystemStatus<BroadcastDataMsg>() {
}

void ShiftingShiftSystemStatusMsg::setEventCount(uint8_t n) {
    set8BitValue(n, 1);
}

void ShiftingShiftSystemStatusMsg::setCurrentGearRear(uint8_t cgr) {
    set8BitValue(cgr, 3, 0x1F);
}

void ShiftingShiftSystemStatusMsg::setCurrentGearFront(uint8_t cgf) {
    set8BitValue(cgf, 3, 0xE0, 5);
}

void ShiftingShiftSystemStatusMsg::setTotalNumbersGearRear(uint8_t tgr) {
    set8BitValue(tgr, 4, 0x1F);
}

void ShiftingShiftSystemStatusMsg::setTotalNumbersGearFront(uint8_t tgf) {
    set8BitValue(tgf, 4, 0xE0, 5);
}

void ShiftingShiftSystemStatusMsg::setInvalidInboardShiftCountRear(uint8_t isr) {
    set8BitValue(isr, 5, 0x0F);
}

void ShiftingShiftSystemStatusMsg::setInvalidOutboardShiftCountRear(uint8_t osr) {
    set8BitValue(osr, 0xF0, 4);
}

void ShiftingShiftSystemStatusMsg::setInvalidInboardShiftCountFront(uint8_t isf) {
    set8BitValue(isf, 6, 0x0F);
}

void ShiftingShiftSystemStatusMsg::setInvalidOutboardShiftCountFront(uint8_t osf) {
    set8BitValue(osf, 6, 0xF0, 4);
}

void ShiftingShiftSystemStatusMsg::setShiftFailureCountRear(uint8_t sfr) {
    set8BitValue(sfr, 7, 0x0F);
}

void ShiftingShiftSystemStatusMsg::setShiftFailureCountFront(uint8_t sff) {
    set8BitValue(sff, 7, 0xF0, 4);
}
