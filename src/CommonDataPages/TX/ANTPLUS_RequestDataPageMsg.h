#ifndef ANTPLUS_REQUESTDATAPAGEMSG_h
#define ANTPLUS_REQUESTDATAPAGEMSG_h

#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>
#include <CommonDataPages/Base/ANTPLUS_BaseRequestDataPage.h>

#include "ANT.h"

// Common Page 70

class RequestDataPageMsg : public BaseDataPageMsg<AcknowledgedDataMsg>, public BaseRequestDataPage<AcknowledgedDataMsg> {
public:
    RequestDataPageMsg();
    void setSlaveSerialNumber(uint16_t serialNumber);
    void setDescriptorByte1(uint8_t descriptorByte);
    void setDescriptorByte2(uint8_t descriptorByte);
    void setRequestedTransmissionResponseCount(uint8_t count);
    void setRequestedTransmissionUseAcknowledged(uint8_t useAcknowledged);
    void setRequestedPageNumber(uint8_t pageNumber);
    void setCommandType(uint8_t commandType);
private:
    uint8_t _buffer[MESSAGE_SIZE];
};

#endif // ANTPLUS_REQUESTDATAPAGEMSG_h
