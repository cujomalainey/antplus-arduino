#include <Profiles/Shifting/DataPages/ANTPLUS_ShiftingShiftSystemStatus.h>
#include <Profiles/Shifting/ANTPLUS_ShiftingDefines.h>

#define EVENTCOUNT_BYTE 1
#define RESERVED_BYTE 2
#define RESERVED_VALUE 0xFF
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
#define SHIFTFAILURECOUNT_BYTE 7
#define SHIFTFAILURECOUNT_REAR_MASK 0x0F
#define SHIFTFAILURECOUNT_FRONT_MASK 0xF0
#define SHIFTFAILURECOUNT_FRONT_SHIFT 4

template<class T>
ShiftingBaseShiftSystemStatus<T>::ShiftingBaseShiftSystemStatus() : CoreDataPage<T>() {}

template<class T>
uint8_t ShiftingBaseShiftSystemStatus<T>::getEventCount() {
    return this->get8BitValue(EVENTCOUNT_BYTE);
}

template<class T>
uint8_t ShiftingBaseShiftSystemStatus<T>::getCurrentGearRear() {
    return this->get8BitValue(CURRENTGEAR_BYTE, CURRENTGEAR_REAR_MASK);
}

template<class T>
uint8_t ShiftingBaseShiftSystemStatus<T>::getCurrentGearFront() {
    return this->get8BitValue(CURRENTGEAR_BYTE,
            CURRENTGEAR_FRONT_MASK,
            CURRENTGEAR_FRONT_SHIFT);
}

template<class T>
uint8_t ShiftingBaseShiftSystemStatus<T>::getTotalNumbersGearRear() {
    return this->get8BitValue(TOTALNUMBEROFGEARS_BYTE, TOTALNUMBEROFGEARS_REAR_MASK);
}

template<class T>
uint8_t ShiftingBaseShiftSystemStatus<T>::getTotalNumbersGearFront() {
    return this->get8BitValue(TOTALNUMBEROFGEARS_BYTE,
            TOTALNUMBEROFGEARS_FRONT_MASK,
            TOTALNUMBEROFGEARS_FRONT_SHIFT);
}

template<class T>
uint8_t ShiftingBaseShiftSystemStatus<T>::getInvalidInboardShiftCountRear() {
    return this->get8BitValue(INVALIDINBOARDSHIFTCOUNT_REAR_BYTE,
            INVALIDINBOARDSHIFTCOUNT_REAR_MASK);
}

template<class T>
uint8_t ShiftingBaseShiftSystemStatus<T>::getInvalidOutboardShiftCountRear() {
    return this->get8BitValue(INVALIDOUTBOARDSHIFTCOUNT_REAR_BYTE,
            INVALIDOUTBOARDSHIFTCOUNT_REAR_MASK,
            INVALIDOUTBOARDSHIFTCOUNT_REAR_SHIFT);
}

template<class T>
uint8_t ShiftingBaseShiftSystemStatus<T>::getInvalidInboardShiftCountFront() {
    return this->get8BitValue(INVALIDINBOARDSHIFTCOUNT_FRONT_BYTE,
            INVALIDINBOARDSHIFTCOUNT_FRONT_MASK);
}

template<class T>
uint8_t ShiftingBaseShiftSystemStatus<T>::getInvalidOutboardShiftCountFront() {
    return this->get8BitValue(INVALIDOUTBOARDSHIFTCOUNT_FRONT_BYTE,
            INVALIDOUTBOARDSHIFTCOUNT_FRONT_MASK,
            INVALIDOUTBOARDSHIFTCOUNT_FRONT_SHIFT);
}

template<class T>
uint8_t ShiftingBaseShiftSystemStatus<T>::getShiftFailureCountRear() {
    return this->get8BitValue(SHIFTFAILURECOUNT_BYTE,  SHIFTFAILURECOUNT_REAR_MASK);
}

template<class T>
uint8_t ShiftingBaseShiftSystemStatus<T>::getShiftFailureCountFront() {
    return this->get8BitValue(SHIFTFAILURECOUNT_BYTE,
            SHIFTFAILURECOUNT_FRONT_MASK,
            SHIFTFAILURECOUNT_FRONT_SHIFT);
}

template class ShiftingBaseShiftSystemStatus<BroadcastData>;
template class ShiftingBaseShiftSystemStatus<BroadcastDataMsg>;

ShiftingShiftSystemStatus::ShiftingShiftSystemStatus(AntRxDataResponse& dp) :
    ShiftingBaseMainDataPage(dp),
    ShiftingBaseShiftSystemStatus<BroadcastData>() {}

ShiftingShiftSystemStatusMsg::ShiftingShiftSystemStatusMsg() :
    ShiftingBaseMainDataPageMsg(ANTPLUS_SHIFTING_DATAPAGE_SHIFTSYSTEMSTATUS_NUMBER),
    ShiftingBaseShiftSystemStatus<BroadcastDataMsg>() {
    set8BitValue(RESERVED_VALUE, RESERVED_BYTE);
}

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
