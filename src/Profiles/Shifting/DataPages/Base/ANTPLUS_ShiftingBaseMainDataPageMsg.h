#ifndef ANTPLUS_SHIFTINGBASEMAINDATAPAGEMSG_h
#define ANTPLUS_SHIFTINGBASEMAINDATAPAGEMSG_h

#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>
#include <Profiles/Shifting/ANTPLUS_ShiftingPrivateDefines.h>

#include "ANT.h"

class ShiftingBaseGenericMsg : public BaseDataPageMsg<BroadcastDataMsg> {
public:
    ShiftingBaseGenericMsg();

    void copyData(uint8_t * buf, size_t len) { memcpy(_buffer, buf, len); }

protected:
    uint8_t _buffer[MESSAGE_SIZE];
};

class ShiftingBaseMainDataPageMsg : public ShiftingBaseGenericMsg {
public:
    ShiftingBaseMainDataPageMsg(uint8_t dataPageNumber = ANTPLUS_SHIFTING_DATAPAGE_SHIFTSYSTEMSTATUS_NUMBER);

    void setCurrentGearFront( uint8_t cgf );
    void setCurrentGearRear( uint8_t cgr );
    void setTotalNumbersGearFront( uint8_t tgr );
    void setTotalNumbersGearRear( uint8_t tgr );
    void setEventCount(uint8_t n);
};

#endif // ANTPLUS_SHIFTINGBASEMAINDATAPAGEMSG_h
