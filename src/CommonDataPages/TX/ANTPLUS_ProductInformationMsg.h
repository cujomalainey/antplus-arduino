#ifndef ANTPLUS_PRODUCTINFORMATIONMSG_h
#define ANTPLUS_PRODUCTINFORMATIONMSG_h

#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>

#include "ANT.h"

// Common page 81

class ProductInformationMsg : public BaseDataPageMsg<BroadcastDataMsg> {
public:
    ProductInformationMsg();
    uint8_t getSWRevisionSupplemental();
    uint8_t getSWRevisionMain();
    uint32_t getSerialNumber();
    void setSWRevisionSupplemental(uint8_t revision);
    void setSWRevisionMain(uint8_t revision);
    void setSerialNumber(uint32_t serialNumber);
private:
    uint8_t _buffer[MESSAGE_SIZE];
};

#endif // ANTPLUS_PRODUCTINFORMATIONMSG_h
