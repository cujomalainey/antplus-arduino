#ifndef ANTPLUS_BASEREQUESTDATAPAGE_h
#define ANTPLUS_BASEREQUESTDATAPAGE_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

// Common Page 70

template<class T>
class BaseRequestDataPage : virtual public CoreDataPage<T> {
public:
    BaseRequestDataPage();
    uint16_t getSlaveSerialNumber();
    uint8_t getDescriptorByte1();
    uint8_t getDescriptorByte2();
    uint8_t getRequestedTransmissionResponseCount();
    uint8_t getRequestedTransmissionUseAcknowledged();
    uint8_t getRequestedPageNumber();
    uint8_t getCommandType();
};

#endif // ANTPLUS_BASEREQUESTDATAPAGE_h
