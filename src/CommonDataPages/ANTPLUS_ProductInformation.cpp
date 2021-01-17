#include <CommonDataPages/ANTPLUS_ProductInformation.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

template<class T>
BaseProductInformation<T>::BaseProductInformation() : CoreDataPage<T>() {}

template<class T>
uint8_t BaseProductInformation<T>::getSWRevisionSupplemental() {
    return this->get8BitValue(
            ANTPLUS_COMMON_DATAPAGE_PRODUCTINFORMATION_SWREVISIONSUPPLEMENTAL_BYTE);
}

template<class T>
uint8_t BaseProductInformation<T>::getSWRevisionMain() {
    return this->get8BitValue(
            ANTPLUS_COMMON_DATAPAGE_PRODUCTINFORMATION_SWREVISIONMAIN_BYTE);
}

template<class T>
uint32_t BaseProductInformation<T>::getSerialNumber() {
    return this->get32BitValue(
            ANTPLUS_COMMON_DATAPAGE_PRODUCTINFORMATION_SERIALNUMBER_LSB_BYTE,
            ANTPLUS_COMMON_DATAPAGE_PRODUCTINFORMATION_SERIALNUMBER_MSB_BYTE);
}

template class BaseProductInformation<BroadcastData>;
template class BaseProductInformation<BroadcastDataMsg>;

ProductInformation::ProductInformation(AntRxDataResponse& dp) :
    BaseDataPage<BroadcastData>(dp),
    BaseProductInformation<BroadcastData>() {}

ProductInformationMsg::ProductInformationMsg() :
    BaseDataPageMsg<BroadcastDataMsg>(),
    BaseProductInformation<BroadcastDataMsg>() {
    // TODO set default values
    setDataBuffer(_buffer);
    _buffer[ANTPLUS_DEFAULT_DATAPAGE_BYTE] = ANTPLUS_COMMON_DATAPAGE_PRODUCTINFORMATION_NUMBER;
    _buffer[1] = 0xFF;
}

void ProductInformationMsg::setSWRevisionSupplemental(uint8_t revision) {
    set8BitValue(revision,
            ANTPLUS_COMMON_DATAPAGE_PRODUCTINFORMATION_SWREVISIONSUPPLEMENTAL_BYTE);
}

void ProductInformationMsg::setSWRevisionMain(uint8_t revision) {
    set8BitValue(revision,
            ANTPLUS_COMMON_DATAPAGE_PRODUCTINFORMATION_SWREVISIONMAIN_BYTE);
}

void ProductInformationMsg::setSerialNumber(uint32_t serialNumber) {
    set32BitValue(serialNumber,
            ANTPLUS_COMMON_DATAPAGE_PRODUCTINFORMATION_SERIALNUMBER_LSB_BYTE,
            ANTPLUS_COMMON_DATAPAGE_PRODUCTINFORMATION_SERIALNUMBER_MSB_BYTE);
}
