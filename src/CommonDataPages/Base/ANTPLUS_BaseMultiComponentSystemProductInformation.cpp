#include <CommonDataPages/Base/ANTPLUS_BaseMultiComponentSystemProductInformation.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>

template<class T>
BaseMultiComponentSystemProductInformation<T>::BaseMultiComponentSystemProductInformation() : CoreDataPage<T>() {
}

template<class T>
uint8_t BaseMultiComponentSystemProductInformation<T>::getNumberOfComponents() {
    return this->get8BitValue(
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_COMPONENTIDENTIFIER_BYTE,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_COMPONENTIDENTIFIER_NUMBEROFCOMPONENTS_MASK);
}

template<class T>
uint8_t BaseMultiComponentSystemProductInformation<T>::getComponentIdentifier() {
    return this->get8BitValue(
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_COMPONENTIDENTIFIER_BYTE,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_COMPONENTIDENTIFIER_IDENTIFIER_MASK,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_COMPONENTIDENTIFIER_IDENTIFIER_SHIFT);
}

template<class T>
uint8_t BaseMultiComponentSystemProductInformation<T>::getSWRevisionSupplemental() {
    return this->get8BitValue(
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_SWREVISIONSUPPLEMENTAL_BYTE);
}

template<class T>
uint8_t BaseMultiComponentSystemProductInformation<T>::getSWRevisionMain() {
    return this->get8BitValue(
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_SWREVISIONMAIN_BYTE);
}

template<class T>
uint32_t BaseMultiComponentSystemProductInformation<T>::getSerialNumber() {
    return this->get32BitValue(
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_SERIALNUMBER_LSB_BYTE,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_SERIALNUMBER_MSB_BYTE);
}

template class BaseMultiComponentSystemProductInformation<BroadcastData>;
template class BaseMultiComponentSystemProductInformation<BroadcastDataMsg>;
