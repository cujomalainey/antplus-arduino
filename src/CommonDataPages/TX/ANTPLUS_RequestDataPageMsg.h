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
    void getSlaveSerialNumber(uint16_t serialNumber);
    void getDescriptorByte1(uint8_t descriptorByte);
    void getDescriptorByte2(uint8_t descriptorByte);
    void getRequestedTransmissionResponse(uint8_t transmissionResponse);
    void getRequestedPageNumber(uint8_t pageNumber);
    void getCommandType(uint8_t commandType);
};

#endif // ANTPLUS_REQUESTDATAPAGEMSG_h