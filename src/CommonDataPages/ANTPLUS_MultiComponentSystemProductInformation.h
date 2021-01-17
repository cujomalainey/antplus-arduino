#ifndef ANTPLUS_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_h
#define ANTPLUS_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>
#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>

// Common page 79

template<class T>
class BaseMultiComponentSystemProductInformation : virtual public CoreDataPage<T> {
public:
    BaseMultiComponentSystemProductInformation();
    uint8_t getNumberOfComponents();
    uint8_t getComponentIdentifier();
    uint8_t getSWRevisionSupplemental();
    uint8_t getSWRevisionMain();
    uint32_t getSerialNumber();
};

class MultiComponentSystemProductInformation : public BaseDataPage<BroadcastData>, public BaseMultiComponentSystemProductInformation<BroadcastData> {
public:
    explicit MultiComponentSystemProductInformation(AntRxDataResponse& dp);
};

class MultiComponentSystemProductInformationMsg : public BaseDataPageMsg<BroadcastDataMsg>, public BaseMultiComponentSystemProductInformation<BroadcastDataMsg> {
public:
    MultiComponentSystemProductInformationMsg();
    void setNumberOfComponents(uint8_t count);
    void setComponentIdentifier(uint8_t identifier);
    void setSWRevisionSupplemental(uint8_t revision);
    void setSWRevisionMain(uint8_t revision);
    void setSerialNumber(uint32_t serialNumber);
private:
    uint8_t _buffer[MESSAGE_SIZE];
};

#endif // ANTPLUS_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_h
