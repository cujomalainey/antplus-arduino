#ifndef ANTPLUS_SHIFTINGBASESHIFTSYSTEMSTATUS_h
#define ANTPLUS_SHIFTINGBASESHIFTSYSTEMSTATUS_h

#include <Profiles/Shifting/DataPages/Base/ANTPLUS_ShiftingBaseMainDataPageMsg.h>

#include "ANT.h"

template<class T>
class ShiftingBaseShiftSystemStatus : virtual public CoreDataPage<T> {
public:
    ShiftingBaseShiftSystemStatus();
    uint8_t getEventCount();
    uint8_t getCurrentGearRear();
    uint8_t getCurrentGearFront();
    uint8_t getTotalNumbersGearRear();
    uint8_t getTotalNumbersGearFront();
    uint8_t getInvalidInboardShiftCountRear();
    uint8_t getInvalidOutboardShiftCountRear();
    uint8_t getInvalidInboardShiftCountFront();
    uint8_t getInvalidOutboardShiftCountFront();
    uint8_t getShiftFailureCountRear();
    uint8_t getShiftFailureCountFront();
};

#endif // ANTPLUS_SHIFTINGBASESHIFTSYSTEMSTATUS_h
