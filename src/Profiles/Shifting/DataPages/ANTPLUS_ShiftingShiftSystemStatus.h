#ifndef ANTPLUS_SHIFTINGSHIFTSYSTEMSTATUS_h
#define ANTPLUS_SHIFTINGSHIFTSYSTEMSTATUS_h

#include <Profiles/Shifting/DataPages/ANTPLUS_ShiftingBaseMainDataPage.h>

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

class ShiftingShiftSystemStatus : public ShiftingBaseMainDataPage, public ShiftingBaseShiftSystemStatus<BroadcastData> {
public:
    explicit ShiftingShiftSystemStatus(AntRxDataResponse& dp);
};

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

#endif // ANTPLUS_SHIFTINGSHIFTSYSTEMSTATUS_h
