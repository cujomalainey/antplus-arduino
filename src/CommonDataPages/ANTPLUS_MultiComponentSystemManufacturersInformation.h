#ifndef ANTPLUS_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_h
#define ANTPLUS_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>
#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>

// Common page 78

template<class T>
class BaseMultiComponentSystemManufacturersInformation : virtual public CoreDataPage<T> {
public:
    BaseMultiComponentSystemManufacturersInformation();
    uint8_t getNumberOfComponents();
    uint8_t getComponentIdentifier();
    uint8_t getHWRevision();
    uint16_t getManufacturerId();
    uint16_t getModelNumber();
};

class MultiComponentSystemManufacturersInformation : public BaseDataPage<BroadcastData>, public BaseMultiComponentSystemManufacturersInformation<BroadcastData> {
public:
    explicit MultiComponentSystemManufacturersInformation(AntRxDataResponse& dp);
};

class MultiComponentSystemManufacturersInformationMsg : public BaseDataPageMsg<BroadcastDataMsg>, public BaseMultiComponentSystemManufacturersInformation<BroadcastDataMsg> {
public:
    MultiComponentSystemManufacturersInformationMsg();
    void setNumberOfComponents(uint8_t count);
    void setComponentIdentifier(uint8_t identifier);
    void setHWRevision(uint8_t rev);
    void setManufacturerId(uint16_t id);
    void setModelNumber(uint16_t model);
private:
    uint8_t _buffer[MESSAGE_SIZE] = {0};
};

#endif // ANTPLUS_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_h
