#include <CommonDataPages/ANTPLUS_MultiComponentSystemProductInformation.h>
#include <CommonDataPages/ANTPLUS_CommonDataPageDefines.h>
#include <ANTPLUS_PrivateDefines.h>

#define COMPONENTIDENTIFIER_BYTE 1
#define COMPONENTIDENTIFIER_NUMBEROFCOMPONENTS_MASK 0x0F
#define COMPONENTIDENTIFIER_IDENTIFIER_MASK 0xF0
#define COMPONENTIDENTIFIER_IDENTIFIER_SHIFT 4
#define SWREVISIONSUPPLEMENTAL_BYTE 2
#define SWREVISIONMAIN_BYTE 3
#define SERIALNUMBER_LSB_BYTE 4
#define SERIALNUMBER_MSB_BYTE 7

template<class T>
BaseMultiComponentSystemProductInformation<T>::BaseMultiComponentSystemProductInformation() :
    CoreDataPage<T>() {}

template<class T>
uint8_t BaseMultiComponentSystemProductInformation<T>::getNumberOfComponents() {
    return this->get8BitValue(COMPONENTIDENTIFIER_BYTE,
            COMPONENTIDENTIFIER_NUMBEROFCOMPONENTS_MASK);
}

template<class T>
uint8_t BaseMultiComponentSystemProductInformation<T>::getComponentIdentifier() {
    return this->get8BitValue(COMPONENTIDENTIFIER_BYTE,
            COMPONENTIDENTIFIER_IDENTIFIER_MASK,
            COMPONENTIDENTIFIER_IDENTIFIER_SHIFT);
}

template<class T>
uint8_t BaseMultiComponentSystemProductInformation<T>::getSWRevisionSupplemental() {
    return this->get8BitValue(SWREVISIONSUPPLEMENTAL_BYTE);
}

template<class T>
uint8_t BaseMultiComponentSystemProductInformation<T>::getSWRevisionMain() {
    return this->get8BitValue(SWREVISIONMAIN_BYTE);
}

template<class T>
uint32_t BaseMultiComponentSystemProductInformation<T>::getSerialNumber() {
    return this->get32BitValue(SERIALNUMBER_LSB_BYTE, SERIALNUMBER_MSB_BYTE);
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
    set8BitValue(ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_NUMBER,
            ANTPLUS_DEFAULT_DATAPAGE_BYTE);
}

void MultiComponentSystemProductInformationMsg::setNumberOfComponents(uint8_t count) {
    set8BitValue(count, COMPONENTIDENTIFIER_BYTE,
            COMPONENTIDENTIFIER_NUMBEROFCOMPONENTS_MASK);
}

void MultiComponentSystemProductInformationMsg::setComponentIdentifier(uint8_t identifier) {
    set8BitValue(identifier, COMPONENTIDENTIFIER_BYTE,
            COMPONENTIDENTIFIER_IDENTIFIER_MASK,
            COMPONENTIDENTIFIER_IDENTIFIER_SHIFT);
}

void MultiComponentSystemProductInformationMsg::setSWRevisionSupplemental(uint8_t revision) {
    set8BitValue(revision, SWREVISIONSUPPLEMENTAL_BYTE);
}

void MultiComponentSystemProductInformationMsg::setSWRevisionMain(uint8_t revision) {
    set8BitValue(revision, SWREVISIONMAIN_BYTE);
}

void MultiComponentSystemProductInformationMsg::setSerialNumber(uint32_t serialNumber) {
    set32BitValue(serialNumber, SERIALNUMBER_LSB_BYTE, SERIALNUMBER_MSB_BYTE);
}
