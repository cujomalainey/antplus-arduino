#ifndef ANTPLUS_MANUFACTURERSINFORMATION_h
#define ANTPLUS_MANUFACTURERSINFORMATION_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>
#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>

// Common page 80

template<class T>
class BaseManufacturersInformation : virtual public CoreDataPage<T> {
public:
    BaseManufacturersInformation();
    uint8_t getHWRevision();
    uint16_t getManufacturerID();
    uint16_t getModelNumber();
};

class ManufacturersInformation : public BaseDataPage<BroadcastData>, public BaseManufacturersInformation<BroadcastData> {
public:
    explicit ManufacturersInformation(AntRxDataResponse& dp);
};

class ManufacturersInformationMsg : public BaseDataPageMsg<BroadcastDataMsg>, BaseManufacturersInformation<BroadcastDataMsg> {
public:
    ManufacturersInformationMsg();
    void setHWRevision(uint8_t revision);
    void setManufacturerId(uint16_t id);
    void setModelNumber(uint16_t modelNumber);
private:
    uint8_t _buffer[MESSAGE_SIZE] = {0};
};

#endif // ANTPLUS_MANUFACTURERSINFORMATION_h
