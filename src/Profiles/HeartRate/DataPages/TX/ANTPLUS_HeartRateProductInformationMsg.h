#ifndef ANTPLUS_HEARTRATEPRODUCTIONINFORMATIONMSG_h
#define ANTPLUS_HEARTRATEPRODUCTIONINFORMATIONMSG_h

#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPageMsg.h>

class HeartRateProductionInformationMsg : public HeartRateBaseMainDataPageMsg {
public:
    HeartRateProductionInformationMsg();
    uint8_t getHardwareVersion();
    uint8_t getSoftwareVersion();
    uint8_t getModelNumber();
    void setHardwareVersion(uint8_t hwVersion);
    void setSoftwareVersion(uint8_t swVersion);
    void setModelNumber(uint8_t modelNumber);
};

#endif // ANTPLUS_HEARTRATEPRODUCTIONINFORMATIONMSG_h