#ifndef ANTPLUS_REQUESTDATAPAGE_h
#define ANTPLUS_REQUESTDATAPAGE_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>
#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>

// Common Page 70

template<class T>
class BaseRequestDataPage : virtual public CoreDataPage<T> {
public:
    BaseRequestDataPage();
    uint16_t getSlaveSerialNumber();
    uint8_t getDescriptorByte1();
    uint8_t getDescriptorByte2();
    uint8_t getRequestedPageCount();
    uint8_t getUseAcknowledgedMsgs();
    uint8_t transmitTillAcknowledged();
    uint8_t getRequestedPageNumber();
    uint8_t getCommandType();
};

class RequestDataPage : public BaseDataPage<AcknowledgedData>, public BaseRequestDataPage<AcknowledgedData> {
public:
    explicit RequestDataPage(AntRxDataResponse& dp);
};

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

#endif // ANTPLUS_REQUESTDATAPAGE_h
