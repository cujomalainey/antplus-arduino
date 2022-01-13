#include <Profiles/Fec/DataPages/ANTPLUS_FecManufacturerInformation.h>
#include <Profiles/Fec/ANTPLUS_FecPrivateDefines.h>

//#define DP_NUMBER_BYTE 1
#define RESERVED_BYTE 1
#define RESERVER_BYTE2 2
#define HW_REVISION_BYTE 3
#define MANUFACTUREREIDLSB_BYTE 4
#define MANUFACTUREREIDMSB_BYTE 5
#define MODELNUMBER_LSB_BYTE 6
#define MODELNUMBER_MSB_BYTE 7

template<class T>
FecBaseManufacturerInformation<T>::FecBaseManufacturerInformation() :
    CoreDataPage<T>() {}

template<class T>
uint16_t FecBaseManufacturerInformation<T>::getManufacturerId() {
    return this->get16BitValue(MANUFACTUREREIDLSB_BYTE, MANUFACTUREREIDMSB_BYTE);
}

template<class T>
uint16_t FecBaseManufacturerInformation<T>::getModelNumber() {
    return this->get16BitValue(MODELNUMBER_LSB_BYTE, MODELNUMBER_MSB_BYTE);
}

template<class T>
uint8_t FecBaseManufacturerInformation<T>::getHardwareRevision() {
    return this->get8BitValue(HW_REVISION_BYTE);
}

template class FecBaseManufacturerInformation<BroadcastData>;
template class FecBaseManufacturerInformation<BroadcastDataMsg>;

FecManufacturerInformation::FecManufacturerInformation(AntRxDataResponse& dp) :
    FecBaseMainDataPage(dp),
    FecBaseManufacturerInformation<BroadcastData>() {}

FecManufacturerInformationMsg::FecManufacturerInformationMsg() :
    FecBaseMainDataPageMsg(ANTPLUS_FEC_MANUFACTURERINFORMATION_NUMBER),
    FecBaseManufacturerInformation<BroadcastDataMsg>() {}

void FecManufacturerInformationMsg::setManufacturerId(uint16_t id) {
    set16BitValue(id, MANUFACTUREREIDLSB_BYTE, MANUFACTUREREIDMSB_BYTE);
}

void FecManufacturerInformationMsg::setModelNumber(uint16_t ModelNumber) {
    set16BitValue(ModelNumber, MODELNUMBER_LSB_BYTE, MODELNUMBER_MSB_BYTE);
}

void FecManufacturerInformationMsg::setHardwareRevision(uint8_t HardwareRevision) {
    set8BitValue(HardwareRevision, HW_REVISION_BYTE);
}

