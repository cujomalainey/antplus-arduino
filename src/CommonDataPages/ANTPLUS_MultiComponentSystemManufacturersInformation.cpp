#include <CommonDataPages/ANTPLUS_MultiComponentSystemManufacturersInformation.h>
#include <CommonDataPages/ANTPLUS_CommonDataPageDefines.h>
#include <ANTPLUS_PrivateDefines.h>

#define RESERVED_BYTE 1
#define RESERVED_VALUE 0xFF
#define COMPONENTIDENTIFIER_BYTE 2
#define COMPONENTIDENTIFIER_NUMBERCOMPONENTS_MASK 0x0F
#define COMPONENTIDENTIFIER_IDENTIFIER_MASK  0xF0
#define COMPONENTIDENTIFIER_IDENTIFIER_SHIFT 4
#define HWREVISION_BYTE 3
#define MANUFACTURERID_LSB_BYTE 4
#define MANUFACTURERID_MSB_BYTE 5
#define MODELNUMBER_LSB_BYTE 6
#define MODELNUMBER_MSB_BYTE 7

template<class T>
BaseMultiComponentSystemManufacturersInformation<T>::BaseMultiComponentSystemManufacturersInformation() :
    CoreDataPage<T>() {}

template<class T>
uint8_t BaseMultiComponentSystemManufacturersInformation<T>::getNumberOfComponents() {
    return this->get8BitValue(COMPONENTIDENTIFIER_BYTE,
            COMPONENTIDENTIFIER_NUMBERCOMPONENTS_MASK);
}

template<class T>
uint8_t BaseMultiComponentSystemManufacturersInformation<T>::getComponentIdentifier() {
    return this->get8BitValue(COMPONENTIDENTIFIER_BYTE,
            COMPONENTIDENTIFIER_IDENTIFIER_MASK,
            COMPONENTIDENTIFIER_IDENTIFIER_SHIFT);
}

template<class T>
uint8_t BaseMultiComponentSystemManufacturersInformation<T>::getHWRevision() {
    return this->get8BitValue(HWREVISION_BYTE);
}

template<class T>
uint16_t BaseMultiComponentSystemManufacturersInformation<T>::getManufacturerId() {
    return this->get16BitValue(MANUFACTURERID_LSB_BYTE, MANUFACTURERID_MSB_BYTE);
}

template<class T>
uint16_t BaseMultiComponentSystemManufacturersInformation<T>::getModelNumber() {
    return this->get16BitValue(MODELNUMBER_LSB_BYTE, MODELNUMBER_MSB_BYTE);
}

template class BaseMultiComponentSystemManufacturersInformation<BroadcastData>;
template class BaseMultiComponentSystemManufacturersInformation<BroadcastDataMsg>;

MultiComponentSystemManufacturersInformation::MultiComponentSystemManufacturersInformation(AntRxDataResponse& dp) :
    BaseDataPage<BroadcastData>(dp),
    BaseMultiComponentSystemManufacturersInformation<BroadcastData>() {}

MultiComponentSystemManufacturersInformationMsg::MultiComponentSystemManufacturersInformationMsg() :
    BaseDataPageMsg<BroadcastDataMsg>(),
    BaseMultiComponentSystemManufacturersInformation<BroadcastDataMsg>() {
    setDataBuffer(_buffer);
    set8BitValue(
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_NUMBER,
            ANTPLUS_DEFAULT_DATAPAGE_BYTE);
    set8BitValue(RESERVED_VALUE, RESERVED_BYTE);
}

void MultiComponentSystemManufacturersInformationMsg::setNumberOfComponents(uint8_t count) {
    set8BitValue(count, COMPONENTIDENTIFIER_BYTE,
            COMPONENTIDENTIFIER_NUMBERCOMPONENTS_MASK);
}

void MultiComponentSystemManufacturersInformationMsg::setComponentIdentifier(uint8_t identifier) {
    set8BitValue(identifier, COMPONENTIDENTIFIER_BYTE,
            COMPONENTIDENTIFIER_IDENTIFIER_MASK,
            COMPONENTIDENTIFIER_IDENTIFIER_SHIFT);
}

void MultiComponentSystemManufacturersInformationMsg::setHWRevision(uint8_t rev) {
    set8BitValue(rev, HWREVISION_BYTE);
}

void MultiComponentSystemManufacturersInformationMsg::setManufacturerId(uint16_t id) {
    set16BitValue(id, MANUFACTURERID_LSB_BYTE, MANUFACTURERID_MSB_BYTE);
}

void MultiComponentSystemManufacturersInformationMsg::setModelNumber(uint16_t model) {
    set16BitValue(model, MODELNUMBER_LSB_BYTE, MODELNUMBER_MSB_BYTE);
}
