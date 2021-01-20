#include <Profiles/FitnessEquipmentControls/DataPages/ANTPLUS_FitnessEquipmentControlsTrainerData.h>
#include <Profiles/FitnessEquipmentControls/ANTPLUS_FitnessEquipmentControlsPrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

// TODO correct names
#define UPDATEEVENTCOUNT_BYTE 1
#define INSTANTANEOUSCADENCE_BYTE 2
#define ACCUMULATEDPOWER_LSB_BYTE 3
#define ACCUMULATEDPOWER_MSB_BYTE 4
#define INSTANTANEOUSPOWER_LSB_BYTE 5
#define INSTANTANEOUSPOWER_MSB_BYTE 6
#define TRAINERSTATUS_BYTE 6
#define FLAGSFESTATEBIT_BYTE 7

template<class T>
FECTrainerDataPage<T>::FECTrainerDataPage() :
    CoreDataPage<T>() {}

template<class T>
uint8_t FECTrainerDataPage<T>::getDataPageNumber() {
    return this->get8BitValue(ANTPLUS_DEFAULT_DATAPAGE_BYTE);
}

template<class T>
uint8_t FECTrainerDataPage<T>::getUpdateEventCount() {
    return this->get8BitValue(UPDATEEVENTCOUNT_BYTE);
}

template<class T>
uint8_t FECTrainerDataPage<T>::getInstantaneousCadence() {
    return this->get8BitValue(INSTANTANEOUSCADENCE_BYTE);
}

template<class T>
uint8_t FECTrainerDataPage<T>::getFlagsBits() {
    return this->get8BitValue(FLAGSFESTATEBIT_BYTE) & 0x0F;
}

template<class T>
uint8_t FECTrainerDataPage<T>::getFEStateBits() {
    return (this->get8BitValue(FLAGSFESTATEBIT_BYTE) & 0xF0) >> 4;
}

template<class T>
uint16_t FECTrainerDataPage<T>::getAccumulatedPower() {
    return this->get16BitValue(ACCUMULATEDPOWER_LSB_BYTE,
            ACCUMULATEDPOWER_MSB_BYTE);
}

template<class T>
uint16_t FECTrainerDataPage<T>::getInstantaneousPower() {
    return this->get16BitValue(INSTANTANEOUSPOWER_LSB_BYTE,
            INSTANTANEOUSPOWER_MSB_BYTE) & 0x0FFF;
}

template<class T>
uint8_t FECTrainerDataPage<T>::getTrainerStatusBits() {
    return (this->get8BitValue(TRAINERSTATUS_BYTE) & 0xF0) >> 4;
}

template class FECTrainerDataPage<BroadcastData>;
template class FECTrainerDataPage<BroadcastDataMsg>;

FECTrainerData::FECTrainerData(AntRxDataResponse& dp) :
    BaseDataPage<BroadcastData>(dp),
    FECTrainerDataPage<BroadcastData>() {}
