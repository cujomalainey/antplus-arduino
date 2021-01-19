#include <Profiles/FEC/DataPages/ANTPLUS_FECGeneralMainDataPage.h>
#include <Profiles/FEC/ANTPLUS_FECPrivateDefines.h>

template<class T>
FECGeneralMainDataPage<T>::FECGeneralMainDataPage() : CoreDataPage<T>() {
}

template<class T>
uint8_t FECGeneralMainDataPage<T>::getDataPageNumber() {
    return this->get8BitValue(
            ANTPLUS_FEC_DATAPAGE_GENERAL_MAIN_DATAPAGE_BYTE);
}

template<class T>
uint8_t FECGeneralMainDataPage<T>::getEquipmentTypeBits() {
    return this->get8BitValue(
            ANTPLUS_FEC_DATAPAGE_GENERAL_MAIN_EQUIPMENT_TYPE_BIT_BYTE);
}

template<class T>
uint8_t FECGeneralMainDataPage<T>::getElapsedTime() {
    return this->get8BitValue(
            ANTPLUS_FEC_DATAPAGE_GENERAL_MAIN_ELAPSED_TIME_BYTE);
}

template<class T>
uint8_t FECGeneralMainDataPage<T>::getDistanceTraveled() {
    return this->get8BitValue(
            ANTPLUS_FEC_DATAPAGE_GENERAL_MAIN_DISTANCE_TRAVELED_BYTE);
}

template<class T>
uint8_t FECGeneralMainDataPage<T>::getHeartRate() {
    return this->get8BitValue(
            ANTPLUS_FEC_DATAPAGE_GENERAL_MAIN_HEARTRATE_BYTE);
}

template<class T>
uint8_t FECGeneralMainDataPage<T>::getCapabilitiesBits() {
    return this->get8BitValue(
            ANTPLUS_FEC_DATAPAGE_GENERAL_MAIN_CAPBILITY_FESTATE_BIT_BYTE) & 0x0F;
}

template<class T>
uint8_t FECGeneralMainDataPage<T>::getFEStateBits() {
    return (this->get8BitValue(
            ANTPLUS_FEC_DATAPAGE_GENERAL_MAIN_CAPBILITY_FESTATE_BIT_BYTE) & 0xF0) >> 4;
}

template<class T>
uint16_t FECGeneralMainDataPage<T>::getSpeed() {
    return this->get16BitValue(
            ANTPLUS_FEC_DATAPAGE_GENERAL_MAIN_SPEED_LSB_BYTE,
            ANTPLUS_FEC_DATAPAGE_GENERAL_MAIN_SPEED_MSB_BYTE);
}

template class FECGeneralMainDataPage<BroadcastData>;
template class FECGeneralMainDataPage<BroadcastDataMsg>;
