#ifndef ANTPLUS_LEVBASEMAINDATAPAGEMSG_h
#define ANTPLUS_LEVBASEMAINDATAPAGEMSG_h

#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>

#include "ANT.h"

class LevBaseMainDataPageMsg : public BaseDataPageMsg<AcknowledgedDataMsg> {
public:
    LevBaseMainDataPageMsg(uint8_t dataPageNumber);
protected:
    uint8_t _buffer[MESSAGE_SIZE];
};

#endif // ANTPLUS_LEVBASEMAINDATAPAGEMSG_h
