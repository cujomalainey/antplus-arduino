#ifndef ANTPLUS_FECMANUFACTURERINFORMATION_h
#define ANTPLUS_FECMANUFACTURERINFORMATION_h

#include <Profiles/Fec/DataPages/ANTPLUS_FecBaseMainDataPage.h>

template<class T>
class FecBaseManufacturerInformation : virtual public CoreDataPage<T> {
public:
    FecBaseManufacturerInformation();
    uint16_t getManufacturerId();
    uint8_t getHardwareRevision();
    uint16_t getModelNumber();
};

class FecManufacturerInformation : public FecBaseMainDataPage, public FecBaseManufacturerInformation<BroadcastData> {
public:
    explicit FecManufacturerInformation(AntRxDataResponse& dp);
};

class FecManufacturerInformationMsg : public FecBaseMainDataPageMsg, public FecBaseManufacturerInformation<BroadcastDataMsg> {
public:
    FecManufacturerInformationMsg();
    void setManufacturerId(uint16_t id);
    void setModelNumber(uint16_t ModelNumber);
    void setHardwareRevision(uint8_t HardwareRevision);
};

#endif // ANTPLUS_FECMANUFACTURERINFORMATION_h
