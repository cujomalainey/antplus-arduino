#include <CommonDataPages/ANTPLUS_ProductInformation.h>
#include <CommonDataPages/ANTPLUS_CommonDataPageDefines.h>
#include <ANTPLUS_PrivateDefines.h>

#define RESERVED_BYTE 1
#define RESERVED_VALUE 0xFF
#define SWREVISIONSUPPLEMENTAL_BYTE 2
#define SWREVISIONMAIN_BYTE 3
#define SERIALNUMBER_LSB_BYTE 4
#define SERIALNUMBER_MSB_BYTE 7

template<class T>
BaseProductInformation<T>::BaseProductInformation() : CoreDataPage<T>() {}

template<class T>
uint8_t BaseProductInformation<T>::getSWRevisionSupplemental() {
    return this->get8BitValue(SWREVISIONSUPPLEMENTAL_BYTE);
}

template<class T>
uint8_t BaseProductInformation<T>::getSWRevisionMain() {
    return this->get8BitValue(SWREVISIONMAIN_BYTE);
}

template<class T>
uint32_t BaseProductInformation<T>::getSerialNumber() {
    return this->get32BitValue(SERIALNUMBER_LSB_BYTE, SERIALNUMBER_MSB_BYTE);
}

template class BaseProductInformation<BroadcastData>;
template class BaseProductInformation<BroadcastDataMsg>;

ProductInformation::ProductInformation(AntRxDataResponse& dp) :
    BaseDataPage<BroadcastData>(dp),
    BaseProductInformation<BroadcastData>() {}

ProductInformationMsg::ProductInformationMsg() :
    BaseDataPageMsg<BroadcastDataMsg>(),
    BaseProductInformation<BroadcastDataMsg>() {
    setDataBuffer(_buffer);
    set8BitValue(ANTPLUS_COMMON_DATAPAGE_PRODUCTINFORMATION_NUMBER, ANTPLUS_DEFAULT_DATAPAGE_BYTE);
    set8BitValue(RESERVED_VALUE, RESERVED_BYTE);
    set8BitValue(ANTPLUS_COMMON_DATAPAGE_PRODUCTINFORMATION_SWREVISIONSUPPLEMENTAL_INVALID, SWREVISIONSUPPLEMENTAL_BYTE);
}

void ProductInformationMsg::setSWRevisionSupplemental(uint8_t revision) {
    set8BitValue(revision, SWREVISIONSUPPLEMENTAL_BYTE);
}

void ProductInformationMsg::setSWRevisionMain(uint8_t revision) {
    set8BitValue(revision, SWREVISIONMAIN_BYTE);
}

void ProductInformationMsg::setSerialNumber(uint32_t serialNumber) {
    set32BitValue(serialNumber, SERIALNUMBER_LSB_BYTE, SERIALNUMBER_MSB_BYTE);
}
