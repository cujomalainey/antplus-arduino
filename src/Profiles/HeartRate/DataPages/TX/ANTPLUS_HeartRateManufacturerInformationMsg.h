#ifndef ANTPLUS_HEARTRATEMANUFACTURERINFORMATIONMSG_h
#define ANTPLUS_HEARTRATEMANUFACTURERINFORMATIONMSG_h

#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPageMsg.h>
#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseManufacturerInformation.h>

class HeartRateManufacturerInformationMsg : public HeartRateBaseMainDataPageMsg, public HeartRateBaseManufacturerInformation<BroadcastDataMsg> {
public:
    HeartRateManufacturerInformationMsg();
    void setManufacturerIdLsb(uint8_t id);
    void setSerialNumber(uint16_t serialNumber);
};

#endif // ANTPLUS_HEARTRATEMANUFACTURERINFORMATIONMSG_h
