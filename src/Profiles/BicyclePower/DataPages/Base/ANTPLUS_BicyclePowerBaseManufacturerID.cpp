#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerBaseManufacturerID.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerPrivateDefines.h>

template<class T>
BicyclePowerBaseManufacturerID<T>::BicyclePowerBaseManufacturerID() : CoreDataPage<T>() {
}

template<class T>
uint8_t BicyclePowerBaseManufacturerID<T>::getHardwareVersion() {
    return this->get8BitValue(
    		ANTPLUS_BICYCLEPOWER_DATAPAGE_MANUFACTURERID_HARDWAREVERSION_BYTE);
}

template<class T>
uint16_t BicyclePowerBaseManufacturerID<T>::getManufacturerId() {
    return this->get16BitValue(
            ANTPLUS_BICYCLEPOWER_DATAPAGE_MANUFACTURERID_MANUFACTURERIDLSB_BYTE,
			ANTPLUS_BICYCLEPOWER_DATAPAGE_MANUFACTURERID_MANUFACTURERIDMSB_BYTE);
}

template<class T>
uint16_t BicyclePowerBaseManufacturerID<T>::getModelNumber() {
    return this->get16BitValue(
            ANTPLUS_BICYCLEPOWER_DATAPAGE_MANUFACTURERID_MODELNUMBERLSB_BYTE,
            ANTPLUS_BICYCLEPOWER_DATAPAGE_MANUFACTURERID_MODELNUMBERMSB_BYTE);
}

template class BicyclePowerBaseManufacturerID<BroadcastData>;
template class BicyclePowerBaseManufacturerID<BroadcastDataMsg>;
