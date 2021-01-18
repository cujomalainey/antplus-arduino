#include <Profiles/HeartRate/DataPages/ANTPLUS_HeartRateManufacturerInformation.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

#define MANUFACTUREREIDLSB_BYTE 1
#define SERIALNUMBER_LSB_BYTE 2
#define SERIALNUMBER_MSB_BYTE 3

template<class T>
HeartRateBaseManufacturerInformation<T>::HeartRateBaseManufacturerInformation() :
    CoreDataPage<T>() {}

template<class T>
uint8_t HeartRateBaseManufacturerInformation<T>::getManufacturerIdLsb() {
    return this->get8BitValue(MANUFACTUREREIDLSB_BYTE);
}

template<class T>
uint16_t HeartRateBaseManufacturerInformation<T>::getSerialNumber() {
    return this->get16BitValue(SERIALNUMBER_LSB_BYTE, SERIALNUMBER_MSB_BYTE);
}

template class HeartRateBaseManufacturerInformation<BroadcastData>;
template class HeartRateBaseManufacturerInformation<BroadcastDataMsg>;

HeartRateManufacturerInformation::HeartRateManufacturerInformation(AntRxDataResponse& dp) :
    HeartRateBaseMainDataPage(dp),
    HeartRateBaseManufacturerInformation<BroadcastData>() {}

HeartRateManufacturerInformationMsg::HeartRateManufacturerInformationMsg() :
    HeartRateBaseMainDataPageMsg(HEARTRATE_MANUFACTURERINFORMATION_NUMBER),
    HeartRateBaseManufacturerInformation<BroadcastDataMsg>() {}

void HeartRateManufacturerInformationMsg::setManufacturerIdLsb(uint8_t id) {
    set8BitValue(id, MANUFACTUREREIDLSB_BYTE);
}

void HeartRateManufacturerInformationMsg::setSerialNumber(uint16_t serialNumber) {
    set16BitValue(serialNumber, SERIALNUMBER_LSB_BYTE, SERIALNUMBER_MSB_BYTE);
}
