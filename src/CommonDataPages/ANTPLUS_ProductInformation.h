#ifndef ANTPLUS_PRODUCTINFORMATION_h
#define ANTPLUS_PRODUCTINFORMATION_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>
#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>

// Common page 81

template<class T>
class BaseProductInformation : virtual public CoreDataPage<T> {
public:
    BaseProductInformation();
    uint8_t getSWRevisionSupplemental();
    uint8_t getSWRevisionMain();
    uint32_t getSerialNumber();
};

class ProductInformation : public BaseDataPage<BroadcastData>, public BaseProductInformation<BroadcastData> {
public:
    explicit ProductInformation(AntRxDataResponse& dp);
};

class ProductInformationMsg : public BaseDataPageMsg<BroadcastDataMsg>, public BaseProductInformation<BroadcastDataMsg> {
public:
    ProductInformationMsg();
    void setSWRevisionSupplemental(uint8_t revision);
    void setSWRevisionMain(uint8_t revision);
    void setSerialNumber(uint32_t serialNumber);
private:
    uint8_t _buffer[MESSAGE_SIZE];
};

#endif // ANTPLUS_PRODUCTINFORMATION_h
