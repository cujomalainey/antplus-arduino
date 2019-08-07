#include <CommonDataPages/Base/ANTPLUS_BaseProductInformation.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>

template<class T>
BaseProductInformation<T>::BaseProductInformation() : CoreDataPage<T>() {
}

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
