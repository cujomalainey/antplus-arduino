#ifndef ANTPLUS_HEARTRATEPRODUCTIONINFORMATION_h
#define ANTPLUS_HEARTRATEPRODUCTIONINFORMATION_h

#include <Profiles/HeartRate/DataPages/ANTPLUS_HeartRateBaseMainDataPage.h>

template<class T>
class HeartRateBaseProductInformation : virtual public CoreDataPage<T> {
public:
    HeartRateBaseProductInformation();
    uint8_t getHardwareVersion();
    uint8_t getSoftwareVersion();
    uint8_t getModelNumber();
};

class HeartRateProductInformation : public HeartRateBaseMainDataPage, public HeartRateBaseProductInformation<BroadcastData> {
public:
    explicit HeartRateProductInformation(AntRxDataResponse& dp);
};

class HeartRateProductInformationMsg : public HeartRateBaseMainDataPageMsg, public HeartRateBaseProductInformation<BroadcastDataMsg> {
public:
    HeartRateProductInformationMsg();
    void setHardwareVersion(uint8_t hwVersion);
    void setSoftwareVersion(uint8_t swVersion);
    void setModelNumber(uint8_t modelNumber);
};

#endif // ANTPLUS_HEARTRATEPRODUCTIONINFORMATION_h
