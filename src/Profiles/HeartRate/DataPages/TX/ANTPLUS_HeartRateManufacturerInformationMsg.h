#ifndef ANTPLUS_HEARTRATEMANUFACTURERINFORMATIONMSG_h
#define ANTPLUS_HEARTRATEMANUFACTURERINFORMATIONMSG_h

#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPageMsg.h>

class HeartRateManufacturerInformationMsg : public HeartRateBaseMainDataPageMsg {
public:
    HeartRateManufacturerInformationMsg();
    uint8_t getManufacturerIdLsb();
    uint16_t getSerialNumber();
    void setManufacturerIdLsb(uint8_t id);
    void setSerialNumber(uint16_t serialNumber);
};

#endif // ANTPLUS_HEARTRATEMANUFACTURERINFORMATIONMSG_h