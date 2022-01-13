#include <Profiles/Shifting/DataPages/TX/ANTPLUS_ShiftingShiftSystemStatusMsg.h>
#include <Profiles/Shifting/ANTPLUS_ShiftingPrivateDefines.h>

#define EVENTCOUNT_BYTE 1
#define CURRENTGEAR_BYTE 3
#define CURRENTGEAR_REAR_MASK 0x1F
#define CURRENTGEAR_FRONT_MASK 0xE0
#define CURRENTGEAR_FRONT_SHIFT 5
#define TOTALNUMBEROFGEARS_BYTE 4
#define TOTALNUMBEROFGEARS_REAR_MASK 0x1F
#define TOTALNUMBEROFGEARS_FRONT_MASK 0xE0
#define TOTALNUMBEROFGEARS_FRONT_SHIFT 5
#define INVALIDINBOARDSHIFTCOUNT_REAR_BYTE 5
#define INVALIDINBOARDSHIFTCOUNT_REAR_MASK 0x0F
#define INVALIDOUTBOARDSHIFTCOUNT_REAR_BYTE 5
#define INVALIDOUTBOARDSHIFTCOUNT_REAR_MASK 0xF0
#define INVALIDOUTBOARDSHIFTCOUNT_REAR_SHIFT 4
#define INVALIDINBOARDSHIFTCOUNT_FRONT_BYTE 6
#define INVALIDINBOARDSHIFTCOUNT_FRONT_MASK 0x0F
#define INVALIDOUTBOARDSHIFTCOUNT_FRONT_BYTE 6
#define INVALIDOUTBOARDSHIFTCOUNT_FRONT_MASK 0xF0
#define INVALIDOUTBOARDSHIFTCOUNT_FRONT_SHIFT 4
#define SHIFTFAILURECOUNT_BYTE 6
#define SHIFTFAILURECOUNT_REAR_MASK 0x0F
#define SHIFTFAILURECOUNT_FRONT_MASK 0xF0
#define SHIFTFAILURECOUNT_FRONT_SHIFT 4

ShiftingShiftSystemStatusMsg::ShiftingShiftSystemStatusMsg() :
    ShiftingBaseMainDataPageMsg(ANTPLUS_SHIFTING_DATAPAGE_SHIFTSYSTEMSTATUS_NUMBER),
    ShiftingBaseShiftSystemStatus<BroadcastDataMsg>() {}

void ShiftingShiftSystemStatusMsg::setEventCount(uint8_t n) {
    set8BitValue(n, EVENTCOUNT_BYTE);
}

void ShiftingShiftSystemStatusMsg::setCurrentGearRear(uint8_t cgr) {
    set8BitValue(cgr, CURRENTGEAR_BYTE, CURRENTGEAR_REAR_MASK);
}

void ShiftingShiftSystemStatusMsg::setCurrentGearFront(uint8_t cgf) {
    set8BitValue(cgf, CURRENTGEAR_BYTE, CURRENTGEAR_FRONT_MASK,
            CURRENTGEAR_FRONT_SHIFT);
}

void ShiftingShiftSystemStatusMsg::setTotalNumbersGearRear(uint8_t tgr) {
    set8BitValue(tgr, TOTALNUMBEROFGEARS_BYTE, TOTALNUMBEROFGEARS_REAR_MASK);
}

void ShiftingShiftSystemStatusMsg::setTotalNumbersGearFront(uint8_t tgf) {
    set8BitValue(tgf, TOTALNUMBEROFGEARS_BYTE, TOTALNUMBEROFGEARS_FRONT_MASK,
            TOTALNUMBEROFGEARS_FRONT_SHIFT);
}

void ShiftingShiftSystemStatusMsg::setInvalidInboardShiftCountRear(uint8_t isr) {
    set8BitValue(isr, INVALIDINBOARDSHIFTCOUNT_REAR_BYTE,
            INVALIDINBOARDSHIFTCOUNT_REAR_MASK);
}

void ShiftingShiftSystemStatusMsg::setInvalidOutboardShiftCountRear(uint8_t osr) {
    set8BitValue(osr, INVALIDOUTBOARDSHIFTCOUNT_REAR_BYTE,
            INVALIDOUTBOARDSHIFTCOUNT_REAR_MASK,
            INVALIDOUTBOARDSHIFTCOUNT_REAR_SHIFT);
}

void ShiftingShiftSystemStatusMsg::setInvalidInboardShiftCountFront(uint8_t isf) {
    set8BitValue(isf, INVALIDINBOARDSHIFTCOUNT_FRONT_BYTE,
            INVALIDINBOARDSHIFTCOUNT_FRONT_MASK);
}

void ShiftingShiftSystemStatusMsg::setInvalidOutboardShiftCountFront(uint8_t osf) {
    set8BitValue(osf, INVALIDOUTBOARDSHIFTCOUNT_FRONT_BYTE,
            INVALIDOUTBOARDSHIFTCOUNT_FRONT_MASK,
            INVALIDOUTBOARDSHIFTCOUNT_FRONT_SHIFT);
}

void ShiftingShiftSystemStatusMsg::setShiftFailureCountRear(uint8_t sfr) {
    set8BitValue(sfr, SHIFTFAILURECOUNT_BYTE, SHIFTFAILURECOUNT_REAR_MASK);
}

void ShiftingShiftSystemStatusMsg::setShiftFailureCountFront(uint8_t sff) {
    set8BitValue(sff, SHIFTFAILURECOUNT_BYTE, SHIFTFAILURECOUNT_FRONT_MASK,
            SHIFTFAILURECOUNT_FRONT_SHIFT);
}
