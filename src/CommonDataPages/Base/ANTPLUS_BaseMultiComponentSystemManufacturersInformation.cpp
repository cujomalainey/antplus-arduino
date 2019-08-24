#include <CommonDataPages/Base/ANTPLUS_BaseMultiComponentSystemManufacturersInformation.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>

template<class T>
BaseMultiComponentSystemManufacturersInformation<T>::BaseMultiComponentSystemManufacturersInformation() : CoreDataPage<T>() {
}

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
uint16_t BaseMultiComponentSystemManufacturersInformation<T>::getManufacturerID() {
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
