#include <Profiles/FEC/DataPages/Base/ANTPLUS_FECTrainerDataPage.h>
#include <Profiles/FEC/ANTPLUS_FECPrivateDefines.h>

template<class T>
FECTrainerDataPage<T>::FECTrainerDataPage() : CoreDataPage<T>() {
}

template<class T>
uint8_t FECTrainerDataPage<T>::getDataPageNumber() {
    return this->get8BitValue(
            ANTPLUS_FEC_DATAPAGE_TRAINER_DATA_DATAPAGE_BYTE);
}

template<class T>
uint8_t FECTrainerDataPage<T>::getUpdateEventCount() {
    return this->get8BitValue(
            ANTPLUS_FEC_DATAPAGE_TRAINER_DATA_UPDATE_EVENT_COUNT_BYTE);
}

template<class T>
uint8_t FECTrainerDataPage<T>::getInstantaneousCadence() {
    return this->get8BitValue(
            ANTPLUS_FEC_DATAPAGE_TRAINER_DATA_INSTANTANEOUS_CADENCE_BYTE);
}

template<class T>
uint8_t FECTrainerDataPage<T>::getFlagsBits() {
    return this->get8BitValue(
            ANTPLUS_FEC_DATAPAGE_TRAINER_DATA_FLAGS_FESTATE_BIT_BYTE) & 0x0F;
}

template<class T>
uint8_t FECTrainerDataPage<T>::getFEStateBits() {
    return (this->get8BitValue(
            ANTPLUS_FEC_DATAPAGE_GENERAL_MAIN_CAPBILITY_FESTATE_BIT_BYTE) & 0xF0) >> 4;
}

template<class T>
uint16_t FECTrainerDataPage<T>::getAccumulatedPower() {
    return this->get16BitValue(
            ANTPLUS_FEC_DATAPAGE_TRAINER_DATA_ACCUMULATED_POWER_LSB_BYTE,
            ANTPLUS_FEC_DATAPAGE_TRAINER_DATA_ACCUMULATED_POWER_MSB_BYTE);
}

template<class T>
uint16_t FECTrainerDataPage<T>::getInstantaneousPower() {
    return this->get16BitValue(
            ANTPLUS_FEC_DATAPAGE_TRAINER_DATA_INSTANTANEOUS_POWER_LSB_BYTE,
            ANTPLUS_FEC_DATAPAGE_TRAINER_DATA_INSTANTANEOUS_POWER_MSB_BYTE) & 0x0FFF;
}

template<class T>
uint8_t FECTrainerDataPage<T>::getTrainerStatusBits() {
    return (this->get8BitValue(
            ANTPLUS_FEC_DATAPAGE_TRAINER_DATA_TRAINER_STATUS_BYTE) & 0xF0) >> 4;
}

template class FECTrainerDataPage<BroadcastData>;
template class FECTrainerDataPage<BroadcastDataMsg>;
