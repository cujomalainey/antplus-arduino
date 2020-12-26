#include <Profiles/BicyclePower/DataPages/RX/ANTPLUS_BicyclePowerProductID.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerPrivateDefines.h>

template<class T>
BicyclePowerBaseProductID<T>::BicyclePowerBaseProductID() : CoreDataPage<T>() {
}

template<class T>
uint8_t BicyclePowerBaseProductID<T>::getSoftwareVersionSupplemental() {
    return this->get8BitValue(
            ANTPLUS_BICYCLEPOWER_DATAPAGE_PRODUCTID_SOFTWAREVERSIONSUPP_BYTE);
}

template<class T>
uint8_t BicyclePowerBaseProductID<T>::getSoftwareVersion() {
    return this->get8BitValue(
            ANTPLUS_BICYCLEPOWER_DATAPAGE_PRODUCTID_SOFTWAREVERSION_BYTE);
}

template<class T>
uint32_t BicyclePowerBaseProductID<T>::getSerialNumber() {
    return this->get32BitValue(
            ANTPLUS_BICYCLEPOWER_DATAPAGE_PRODUCTID_SERIALNUMBERLSB_BYTE,
			ANTPLUS_BICYCLEPOWER_DATAPAGE_PRODUCTID_SERIALNUMBERMSB_BYTE);
}

template class BicyclePowerBaseProductID<BroadcastData>;
template class BicyclePowerBaseProductID<BroadcastDataMsg>;
