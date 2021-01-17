#include <CommonDataPages/ANTPLUS_ManufacturersInformation.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

template<class T>
BaseManufacturersInformation<T>::BaseManufacturersInformation() :
    CoreDataPage<T>() {}

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

ManufacturersInformation::ManufacturersInformation(AntRxDataResponse& dp) :
    BaseDataPage<BroadcastData>(dp),
    BaseManufacturersInformation<BroadcastData>() {}

// TODO Magic numbers
ManufacturersInformationMsg::ManufacturersInformationMsg() :
    BaseDataPageMsg<BroadcastDataMsg>(),
    BaseManufacturersInformation<BroadcastDataMsg>() {
    setDataBuffer(_buffer);
    _buffer[ANTPLUS_DEFAULT_DATAPAGE_BYTE] = ANTPLUS_COMMON_DATAPAGE_MANUFACTURERSINFORMATION_NUMBER;
    _buffer[1] = 0xFF;
    _buffer[2] = 0xFF;
}

void ManufacturersInformationMsg::setHWRevision(uint8_t revision) {
    set8BitValue(revision,
            ANTPLUS_COMMON_DATAPAGE_MANUFACTURERSINFORMATION_HWREVISION_BYTE);
}

void ManufacturersInformationMsg::setManufacturerId(uint16_t id) {
    set16BitValue(id,
            ANTPLUS_COMMON_DATAPAGE_MANUFACTURERSINFORMATION_MANUFACTURERID_LSB_BYTE,
            ANTPLUS_COMMON_DATAPAGE_MANUFACTURERSINFORMATION_MANUFACTURERID_MSB_BYTE);
}

void ManufacturersInformationMsg::setModelNumber(uint16_t modelNumber) {
    set16BitValue(modelNumber,
            ANTPLUS_COMMON_DATAPAGE_MANUFACTURERSINFORMATION_MODELNUMBER_LSB_BYTE,
            ANTPLUS_COMMON_DATAPAGE_MANUFACTURERSINFORMATION_MODELNUMBER_MSB_BYTE);
}
