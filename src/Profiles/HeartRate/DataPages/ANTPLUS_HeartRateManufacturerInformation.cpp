#include <Profiles/HeartRate/DataPages/ANTPLUS_HeartRateManufacturerInformation.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

#define MANUFACTUREREIDLSB_BYTE 1
#define SERIALNUMBERLSB_BYTE 2
#define SERIALNUMBERMSB_BYTE 3

template<class T>
HeartRateBaseManufacturerInformation<T>::HeartRateBaseManufacturerInformation() :
    CoreDataPage<T>() {}

template<class T>
uint8_t HeartRateBaseManufacturerInformation<T>::getManufacturerIdLsb() {
    return this->get8BitValue(MANUFACTUREREIDLSB_BYTE);
}

template<class T>
uint16_t HeartRateBaseManufacturerInformation<T>::getSerialNumber() {
    return this->get16BitValue(SERIALNUMBERLSB_BYTE, SERIALNUMBERMSB_BYTE);
}

template class HeartRateBaseManufacturerInformation<BroadcastData>;
template class HeartRateBaseManufacturerInformation<BroadcastDataMsg>;

HeartRateManufacturerInformation::HeartRateManufacturerInformation(AntRxDataResponse& dp) :
    HeartRateBaseMainDataPage(dp),
    HeartRateBaseManufacturerInformation<BroadcastData>() {}

HeartRateManufacturerInformationMsg::HeartRateManufacturerInformationMsg() :
    HeartRateBaseMainDataPageMsg(MANUFACTURERINFORMATION_NUMBER),
    HeartRateBaseManufacturerInformation<BroadcastDataMsg>() {}

void HeartRateManufacturerInformationMsg::setManufacturerIdLsb(uint8_t id) {
    set8BitValue(id, MANUFACTUREREIDLSB_BYTE);
}

void HeartRateManufacturerInformationMsg::setSerialNumber(uint16_t serialNumber) {
    set16BitValue(serialNumber, SERIALNUMBERLSB_BYTE, SERIALNUMBERMSB_BYTE);
}
