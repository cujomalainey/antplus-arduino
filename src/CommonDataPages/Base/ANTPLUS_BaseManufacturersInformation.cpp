#include <CommonDataPages/Base/ANTPLUS_BaseManufacturersInformation.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>

template<class T>
BaseManufacturersInformation<T>::BaseManufacturersInformation() : CoreDataPage<T>() {
}

template<class T>
uint8_t BaseManufacturersInformation<T>::getHWRevision() {
    return this->get8BitValue(
            ANTPLUS_COMMON_DATAPAGE_MANUFACTURERSINFORMATION_HWREVISION_BYTE);
}

template<class T>
uint16_t BaseManufacturersInformation<T>::getManufacturerID() {
    return this->get16BitValue(
            ANTPLUS_COMMON_DATAPAGE_MANUFACTURERSINFORMATION_MANUFACTURERID_LSB_BYTE,
            ANTPLUS_COMMON_DATAPAGE_MANUFACTURERSINFORMATION_MANUFACTURERID_MSB_BYTE);
}

template<class T>
uint16_t BaseManufacturersInformation<T>::getModelNumber() {
    return this->get16BitValue(
            ANTPLUS_COMMON_DATAPAGE_MANUFACTURERSINFORMATION_MODELNUMBER_LSB_BYTE,
            ANTPLUS_COMMON_DATAPAGE_MANUFACTURERSINFORMATION_MODELNUMBER_MSB_BYTE);
}

template class BaseManufacturersInformation<BroadcastData>;
template class BaseManufacturersInformation<BroadcastDataMsg>;
