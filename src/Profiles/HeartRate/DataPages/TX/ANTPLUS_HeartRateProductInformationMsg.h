#ifndef ANTPLUS_HEARTRATEPRODUCTIONINFORMATIONMSG_h
#define ANTPLUS_HEARTRATEPRODUCTIONINFORMATIONMSG_h

#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPageMsg.h>
#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseProductInformation.h>

class HeartRateProductInformationMsg : public HeartRateBaseMainDataPageMsg, public HeartRateBaseProductInformation<BroadcastDataMsg> {
public:
    HeartRateProductInformationMsg();
    void setHardwareVersion(uint8_t hwVersion);
    void setSoftwareVersion(uint8_t swVersion);
    void setModelNumber(uint8_t modelNumber);
};

#endif // ANTPLUS_HEARTRATEPRODUCTIONINFORMATIONMSG_h
