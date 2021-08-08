#ifndef ANTPLUS_SHIFTINGBASEMAINDATAPAGEMSG_h
#define ANTPLUS_SHIFTINGBASEMAINDATAPAGEMSG_h

#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>

#include "ANT.h"

class ShiftingBaseMainDataPageMsg : public BaseDataPageMsg<BroadcastDataMsg> {
public:
    explicit ShiftingBaseMainDataPageMsg(uint8_t dataPageNumber);
protected:
    uint8_t _buffer[MESSAGE_SIZE] = {0};
};

#endif // ANTPLUS_SHIFTINGBASEMAINDATAPAGEMSG_h
