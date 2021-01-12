#include <Profiles/Shifting/DataPages/Base/ANTPLUS_ShiftingBaseShiftSystemStatus.h>
#include <Profiles/Shifting/ANTPLUS_ShiftingPrivateDefines.h>

template<class T>
ShiftingBaseShiftSystemStatus<T>::ShiftingBaseShiftSystemStatus() : CoreDataPage<T>() {
}

template<class T>
uint8_t ShiftingBaseShiftSystemStatus<T>::getEventCount() {
    return this->get8BitValue(1);
}

template<class T>
uint8_t ShiftingBaseShiftSystemStatus<T>::getCurrentGearRear() {
    return this->get8BitValue(3, 0x1F);
}

template<class T>
uint8_t ShiftingBaseShiftSystemStatus<T>::getCurrentGearFront() {
    return this->get8BitValue(3, 0xE0, 5);
}

template<class T>
uint8_t ShiftingBaseShiftSystemStatus<T>::getTotalNumbersGearRear() {
    return this->get8BitValue(4, 0x1F);
}

template<class T>
uint8_t ShiftingBaseShiftSystemStatus<T>::getTotalNumbersGearFront() {
    return this->get8BitValue(4, 0xE0, 5);
}

template<class T>
uint8_t ShiftingBaseShiftSystemStatus<T>::getInvalidInboardShiftCountRear() {
    return this->get8BitValue(5, 0x0F);
}

template<class T>
uint8_t ShiftingBaseShiftSystemStatus<T>::getInvalidOutboardShiftCountRear() {
    return this->get8BitValue(5, 0xF0, 4);
}

template<class T>
uint8_t ShiftingBaseShiftSystemStatus<T>::getInvalidInboardShiftCountFront() {
    return this->get8BitValue(6, 0x0F);
}

template<class T>
uint8_t ShiftingBaseShiftSystemStatus<T>::getInvalidOutboardShiftCountFront() {
    return this->get8BitValue(6, 0xF0, 4);
}

template<class T>
uint8_t ShiftingBaseShiftSystemStatus<T>::getShiftFailureCountRear() {
    return this->get8BitValue(7, 0x0F);
}

template<class T>
uint8_t ShiftingBaseShiftSystemStatus<T>::getShiftFailureCountFront() {
    return this->get8BitValue(7, 0xF0, 4);
}

template class ShiftingBaseShiftSystemStatus<BroadcastDataMsg>;
