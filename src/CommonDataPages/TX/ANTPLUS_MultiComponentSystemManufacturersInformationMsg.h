#ifndef ANTPLUS_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATIONMSG_h
#define ANTPLUS_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATIONMSG_h

#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>
#include <CommonDataPages/Base/ANTPLUS_BaseMultiComponentSystemManufacturersInformation.h>

#include "ANT.h"

// Common page 78

class MultiComponentSystemManufacturersInformationMsg : public BaseDataPageMsg<BroadcastDataMsg>, public BaseMultiComponentSystemManufacturersInformation<BroadcastDataMsg> {
public:
    MultiComponentSystemManufacturersInformationMsg();
    void setNumberOfComponents(uint8_t count);
    void setComponentIdentifier(uint8_t identifier);
    void setHWRevision(uint8_t rev);
    void setManufacturerID(uint16_t id);
    void setModelNumber(uint16_t model);
};

#endif // ANTPLUS_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATIONMSG_h
