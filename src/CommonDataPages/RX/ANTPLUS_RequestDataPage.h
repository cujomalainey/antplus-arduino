#ifndef ANTPLUS_REQUESTDATAPAGE_h
#define ANTPLUS_REQUESTDATAPAGE_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>

#include "ANT.h"

// Common Page 70

class RequestDataPage : public BaseDataPage<AcknowledgedData> {
public:
    RequestDataPage(AntRxDataResponse& dp);
    uint16_t getSlaveSerialNumber();
    uint8_t getDescriptorByte1();
    uint8_t getDescriptorByte2();
    uint8_t getRequestedPageCount();
    uint8_t getUseAcknowledgedMsgs();
    uint8_t transmitTillAcknowledged();
    uint8_t getRequestedPageNumber();
    uint8_t getCommandType();
};

#endif // ANTPLUS_REQUESTDATAPAGE_h
