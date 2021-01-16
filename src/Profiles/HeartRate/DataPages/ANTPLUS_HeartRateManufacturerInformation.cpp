#include <Profiles/HeartRate/DataPages/ANTPLUS_HeartRateManufacturerInformation.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

template<class T>
HeartRateBaseManufacturerInformation<T>::HeartRateBaseManufacturerInformation() : CoreDataPage<T>() {
}

template<class T>
uint8_t HeartRateBaseManufacturerInformation<T>::getManufacturerIdLsb() {
    return this->get8BitValue(
            ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_MANUFACTUREREIDLSB_BYTE);
}

template<class T>
uint16_t HeartRateBaseManufacturerInformation<T>::getSerialNumber() {
    return this->get16BitValue(
            ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_SERIALNUMBERLSB_BYTE,
            ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_SERIALNUMBERMSB_BYTE);
}

template class HeartRateBaseManufacturerInformation<BroadcastData>;
template class HeartRateBaseManufacturerInformation<BroadcastDataMsg>;

HeartRateManufacturerInformation::HeartRateManufacturerInformation(AntRxDataResponse& dp) : HeartRateBaseMainDataPage(dp), HeartRateBaseManufacturerInformation<BroadcastData>() {
}

HeartRateManufacturerInformationMsg::HeartRateManufacturerInformationMsg() : HeartRateBaseMainDataPageMsg(ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_NUMBER), HeartRateBaseManufacturerInformation<BroadcastDataMsg>() {
}

void HeartRateManufacturerInformationMsg::setManufacturerIdLsb(uint8_t id) {
    set8BitValue(id,
            ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_MANUFACTUREREIDLSB_BYTE);
}

void HeartRateManufacturerInformationMsg::setSerialNumber(uint16_t serialNumber) {
    set16BitValue(serialNumber,
            ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_SERIALNUMBERLSB_BYTE,
            ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_SERIALNUMBERMSB_BYTE);
}
