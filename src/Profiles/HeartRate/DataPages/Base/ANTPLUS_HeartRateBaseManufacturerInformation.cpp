#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseManufacturerInformation.h>
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
