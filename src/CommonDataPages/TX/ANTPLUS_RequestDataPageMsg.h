#ifndef ANTPLUS_REQUESTDATAPAGEMSG_h
#define ANTPLUS_REQUESTDATAPAGEMSG_h

#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>

#include "ANT.h"

// Common Page 70

class RequestDataPageMsg : public BaseDataPageMsg<AcknowledgedDataMsg> {
public:
    RequestDataPageMsg();
    uint16_t getSlaveSerialNumber();
    uint8_t getDescriptorByte1();
    uint8_t getDescriptorByte2();
    uint8_t getRequestedTransmissionResponse();
    uint8_t getRequestedPageNumber();
    uint8_t getCommandType();
    void setSlaveSerialNumber(uint16_t serialNumber);
    void setDescriptorByte1(uint8_t descriptorByte);
    void setDescriptorByte2(uint8_t descriptorByte);
    void setRequestedTransmissionResponse(uint8_t transmissionResponse);
    void setRequestedPageNumber(uint8_t pageNumber);
    void setCommandType(uint8_t commandType);
};

#endif // ANTPLUS_REQUESTDATAPAGEMSG_h