#include <CommonDataPages/ANTPLUS_MultiComponentSystemManufacturersInformation.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

template<class T>
BaseMultiComponentSystemManufacturersInformation<T>::BaseMultiComponentSystemManufacturersInformation() :
    CoreDataPage<T>() {}

template<class T>
uint8_t BaseMultiComponentSystemManufacturersInformation<T>::getNumberOfComponents() {
    return this->get8BitValue(
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_COMPONENTIDENTIFIER_BYTE,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_COMPONENTIDENTIFIER_NUMBERCOMPONENTS_MASK);
}

template<class T>
uint8_t BaseMultiComponentSystemManufacturersInformation<T>::getComponentIdentifier() {
    return this->get8BitValue(
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_COMPONENTIDENTIFIER_BYTE,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_COMPONENTIDENTIFIER_IDENTIFIER_MASK,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_COMPONENTIDENTIFIER_IDENTIFIER_SHIFT);
}

template<class T>
uint8_t BaseMultiComponentSystemManufacturersInformation<T>::getHWRevision() {
    return this->get8BitValue(
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_HWREVISION_BYTE);
}

template<class T>
uint16_t BaseMultiComponentSystemManufacturersInformation<T>::getManufacturerId() {
    return this->get16BitValue(
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_MANUFACTURERID_LSB_BYTE,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_MANUFACTURERID_MSB_BYTE);
}

template<class T>
uint16_t BaseMultiComponentSystemManufacturersInformation<T>::getModelNumber() {
    return this->get16BitValue(
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_MODELNUMBER_LSB_BYTE,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_MODELNUMBER_MSB_BYTE);
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
}

void MultiComponentSystemManufacturersInformationMsg::setNumberOfComponents(uint8_t count) {
    set8BitValue(count,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_COMPONENTIDENTIFIER_BYTE,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_COMPONENTIDENTIFIER_NUMBERCOMPONENTS_MASK);
}

void MultiComponentSystemManufacturersInformationMsg::setComponentIdentifier(uint8_t identifier) {
    set8BitValue(identifier,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_COMPONENTIDENTIFIER_BYTE,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_COMPONENTIDENTIFIER_IDENTIFIER_MASK,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_COMPONENTIDENTIFIER_IDENTIFIER_SHIFT);
}

void MultiComponentSystemManufacturersInformationMsg::setHWRevision(uint8_t rev) {
    set8BitValue(rev,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_HWREVISION_BYTE);
}

void MultiComponentSystemManufacturersInformationMsg::setManufacturerId(uint16_t id) {
    set16BitValue(id,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_MANUFACTURERID_LSB_BYTE,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_MANUFACTURERID_MSB_BYTE);
}

void MultiComponentSystemManufacturersInformationMsg::setModelNumber(uint16_t model) {
    set16BitValue(model,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_MODELNUMBER_LSB_BYTE,
            ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_MODELNUMBER_MSB_BYTE);
}
