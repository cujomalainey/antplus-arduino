#ifndef ANTPLUS_MANUFACTURERSINFORMATIONMSG_h
#define ANTPLUS_MANUFACTURERSINFORMATIONMSG_h

#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>
#include <CommonDataPages/Base/ANTPLUS_BaseManufacturersInformation.h>

#include "ANT.h"

// Common page 80

class ManufacturersInformationMsg : public BaseDataPageMsg<BroadcastDataMsg>, BaseManufacturersInformation<BroadcastDataMsg> {
public:
    ManufacturersInformationMsg();
    void setHWRevision(uint8_t revision);
    void setManufacturerId(uint16_t id);
    void setModelNumber(uint16_t modelNumber);
private:
    uint8_t _buffer[MESSAGE_SIZE];
};

#endif // ANTPLUS_MANUFACTURERSINFORMATIONMSG_h
