#ifndef ANTPLUS_MUSCLEOXYGENBASEMAINDATAPAGEMSG_h
#define ANTPLUS_MUSCLEOXYGENBASEMAINDATAPAGEMSG_h

#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>

#include "ANT.h"

class MuscleOxygenBaseMainDataPageMsg : public BaseDataPageMsg<BroadcastDataMsg> {
public:
    MuscleOxygenBaseMainDataPageMsg(uint8_t dataPageNumber);
protected:
    uint8_t _buffer[MESSAGE_SIZE];
};

#endif // ANTPLUS_MUSCLEOXYGENBASEMAINDATAPAGEMSG_h
