#ifndef ANTPLUS_MULTICOMPONENTSYSTEMPRODUCTINFORMATIONMSG_h
#define ANTPLUS_MULTICOMPONENTSYSTEMPRODUCTINFORMATIONMSG_h

#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>
#include <CommonDataPages/Base/ANTPLUS_BaseMultiComponentSystemProductInformation.h>

#include "ANT.h"

// Common page 79

class MultiComponentSystemProductInformationMsg : public BaseDataPageMsg<BroadcastDataMsg>, public BaseMultiComponentSystemProductInformation<BroadcastDataMsg> {
public:
    MultiComponentSystemProductInformationMsg();
    void setNumberOfComponents(uint8_t count);
    void setComponentIdentifier(uint8_t identifier);
    void setSWRevisionSupplemental(uint8_t revision);
    void setSWRevisionMain(uint8_t revision);
    void setSerialNumber(uint32_t serialNumber);
};

#endif // ANTPLUS_MULTICOMPONENTSYSTEMPRODUCTINFORMATIONMSG_h
