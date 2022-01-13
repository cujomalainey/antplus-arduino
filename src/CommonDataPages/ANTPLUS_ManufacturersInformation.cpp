#include <CommonDataPages/ANTPLUS_ManufacturersInformation.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

#define HWREVISION_BYTE 3
#define MANUFACTURERID_LSB_BYTE 4
#define MANUFACTURERID_MSB_BYTE 5
#define MODELNUMBER_LSB_BYTE 6
#define MODELNUMBER_MSB_BYTE 7
#define RESERVED_LSB_BYTE 1
#define RESERVED_MSB_BYTE 2
#define RESERVED_VALUE 0xFFFF

template<class T>
BaseManufacturersInformation<T>::BaseManufacturersInformation() :
    CoreDataPage<T>() {}

template<class T>
uint8_t BaseManufacturersInformation<T>::getHWRevision() {
    return this->get8BitValue(HWREVISION_BYTE);
}

template<class T>
uint16_t BaseManufacturersInformation<T>::getManufacturerID() {
    return this->get16BitValue(MANUFACTURERID_LSB_BYTE,
            MANUFACTURERID_MSB_BYTE);
}

template<class T>
uint16_t BaseManufacturersInformation<T>::getModelNumber() {
    return this->get16BitValue(MODELNUMBER_LSB_BYTE, MODELNUMBER_MSB_BYTE);
}

template class BaseManufacturersInformation<BroadcastData>;
template class BaseManufacturersInformation<BroadcastDataMsg>;

ManufacturersInformation::ManufacturersInformation(AntRxDataResponse& dp) :
    BaseDataPage<BroadcastData>(dp),
    BaseManufacturersInformation<BroadcastData>() {}

ManufacturersInformationMsg::ManufacturersInformationMsg() :
    BaseDataPageMsg<BroadcastDataMsg>(),
    BaseManufacturersInformation<BroadcastDataMsg>() {
    setDataBuffer(_buffer);
    set8BitValue(COMMON_MANUFACTURERSINFORMATION_NUMBER,
            ANTPLUS_DEFAULT_DATAPAGE_BYTE);
    set16BitValue(RESERVED_VALUE, RESERVED_LSB_BYTE, RESERVED_MSB_BYTE);
}

void ManufacturersInformationMsg::setHWRevision(uint8_t revision) {
    set8BitValue(revision, HWREVISION_BYTE);
}

void ManufacturersInformationMsg::setManufacturerId(uint16_t id) {
    set16BitValue(id, MANUFACTURERID_LSB_BYTE, MANUFACTURERID_MSB_BYTE);
}

void ManufacturersInformationMsg::setModelNumber(uint16_t modelNumber) {
    set16BitValue(modelNumber, MODELNUMBER_LSB_BYTE, MODELNUMBER_MSB_BYTE);
}
