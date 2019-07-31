#ifndef ANTPLUS_PRODUCTINFORMATIONMSG_h
#define ANTPLUS_PRODUCTINFORMATIONMSG_h

#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>
#include <CommonDataPages/Base/ANTPLUS_BaseProductInformation.h>

#include "ANT.h"

// Common page 81

class ProductInformationMsg : public BaseDataPageMsg<BroadcastDataMsg>, public BaseProductInformation<BroadcastDataMsg> {
public:
    ProductInformationMsg();
    void setSWRevisionSupplemental(uint8_t revision);
    void setSWRevisionMain(uint8_t revision);
    void setSerialNumber(uint32_t serialNumber);
private:
    uint8_t _buffer[MESSAGE_SIZE];
};

#endif // ANTPLUS_PRODUCTINFORMATIONMSG_h
