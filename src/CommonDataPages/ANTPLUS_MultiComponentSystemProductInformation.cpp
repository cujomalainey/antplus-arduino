#include <CommonDataPages/ANTPLUS_MultiComponentSystemProductInformation.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

template<class T>
BaseMultiComponentSystemProductInformation<T>::BaseMultiComponentSystemProductInformation() :
    CoreDataPage<T>() {}

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

MultiComponentSystemProductInformation::MultiComponentSystemProductInformation(AntRxDataResponse& dp) :
    BaseDataPage<BroadcastData>(dp),
    BaseMultiComponentSystemProductInformation<BroadcastData>() {}

MultiComponentSystemProductInformationMsg::MultiComponentSystemProductInformationMsg() :
    BaseDataPageMsg<BroadcastDataMsg>(),
    BaseMultiComponentSystemProductInformation<BroadcastDataMsg>() {
    setDataBuffer(_buffer);
    set8BitValue(
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_NUMBER,
            ANTPLUS_DEFAULT_DATAPAGE_BYTE);
}

void MultiComponentSystemProductInformationMsg::setNumberOfComponents(uint8_t count) {
    set8BitValue(count,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_COMPONENTIDENTIFIER_BYTE,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_COMPONENTIDENTIFIER_NUMBEROFCOMPONENTS_MASK);
}

void MultiComponentSystemProductInformationMsg::setComponentIdentifier(uint8_t identifier) {
    set8BitValue(identifier,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_COMPONENTIDENTIFIER_BYTE,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_COMPONENTIDENTIFIER_IDENTIFIER_MASK,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_COMPONENTIDENTIFIER_IDENTIFIER_SHIFT);
}

void MultiComponentSystemProductInformationMsg::setSWRevisionSupplemental(uint8_t revision) {
    set8BitValue(revision,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_SWREVISIONSUPPLEMENTAL_BYTE);
}

void MultiComponentSystemProductInformationMsg::setSWRevisionMain(uint8_t revision) {
    set8BitValue(revision,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_SWREVISIONMAIN_BYTE);
}

void MultiComponentSystemProductInformationMsg::setSerialNumber(uint32_t serialNumber) {
    set32BitValue(serialNumber,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_SERIALNUMBER_LSB_BYTE,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_SERIALNUMBER_MSB_BYTE);
}
