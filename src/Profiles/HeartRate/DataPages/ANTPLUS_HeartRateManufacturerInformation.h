#ifndef ANTPLUS_HEARTRATEMANUFACTURERINFORMATION_h
#define ANTPLUS_HEARTRATEMANUFACTURERINFORMATION_h

#include <Profiles/HeartRate/DataPages/ANTPLUS_HeartRateBaseMainDataPage.h>

template<class T>
class HeartRateBaseManufacturerInformation : virtual public CoreDataPage<T> {
public:
    HeartRateBaseManufacturerInformation();
    uint8_t getManufacturerIdLsb();
    uint16_t getSerialNumber();
};

class HeartRateManufacturerInformation : public HeartRateBaseMainDataPage, public HeartRateBaseManufacturerInformation<BroadcastData> {
public:
    explicit HeartRateManufacturerInformation(AntRxDataResponse& dp);
};

class HeartRateManufacturerInformationMsg : public HeartRateBaseMainDataPageMsg, public HeartRateBaseManufacturerInformation<BroadcastDataMsg> {
public:
    HeartRateManufacturerInformationMsg();
    void setManufacturerIdLsb(uint8_t id);
    void setSerialNumber(uint16_t serialNumber);
};

#endif // ANTPLUS_HEARTRATEMANUFACTURERINFORMATION_h
