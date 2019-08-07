#ifndef ANTPLUS_SHIFTINGSHIFTSYSTEMSTATUSMSG_h
#define ANTPLUS_SHIFTINGSHIFTSYSTEMSTATUSMSG_h

#include <Profiles/Shifting/DataPages/Base/ANTPLUS_ShiftingBaseShiftSystemStatus.h>
#include <Profiles/Shifting/DataPages/Base/ANTPLUS_ShiftingBaseMainDataPageMsg.h>

#include "ANT.h"

class ShiftingShiftSystemStatusMsg : public ShiftingBaseMainDataPageMsg, public ShiftingBaseShiftSystemStatus<BroadcastDataMsg> {
public:
    ShiftingShiftSystemStatusMsg();
    void setEventCount(uint8_t n);
    void setCurrentGearRear(uint8_t cgr);
    void setCurrentGearFront(uint8_t cgf);
    void setTotalNumbersGearRear(uint8_t tgr);
    void setTotalNumbersGearFront(uint8_t tgf);
    void setInvalidInboardShiftCountRear(uint8_t isr);
    void setInvalidOutboardShiftCountRear(uint8_t osr);
    void setInvalidInboardShiftCountFront(uint8_t isf);
    void setInvalidOutboardShiftCountFront(uint8_t osf);
    void setShiftFailureCountRear(uint8_t sfr);
    void setShiftFailureCountFront(uint8_t sff);
};

#endif // ANTPLUS_SHIFTINGSHIFTSYSTEMSTATUSMSG_h
