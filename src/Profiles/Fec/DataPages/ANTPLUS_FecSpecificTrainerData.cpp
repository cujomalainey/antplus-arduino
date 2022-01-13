#include <Profiles/Fec/DataPages/ANTPLUS_FecSpecificTrainerData.h>
#include <Profiles/Fec/ANTPLUS_FecPrivateDefines.h>
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
FecBaseSpecificTrainerData<T>::FecBaseSpecificTrainerData() :
    CoreDataPage<T>() {}

template<class T>
uint8_t FecBaseSpecificTrainerData<T>::getUpdateEventCount() {
    return this->get8BitValue(UPDATEEVENTCOUNT_BYTE);
}

template<class T>
uint8_t FecBaseSpecificTrainerData<T>::getInstantaneousCadence() {
    return this->get8BitValue(INSTANTANEOUSCADENCE_BYTE);
}

template<class T>
uint8_t FecBaseSpecificTrainerData<T>::getFlagsBits() {
    return this->get8BitValue(FLAGSFESTATEBIT_BYTE) & 0x0F;
}

template<class T>
uint8_t FecBaseSpecificTrainerData<T>::getFEStateBits() {
    return (this->get8BitValue(FLAGSFESTATEBIT_BYTE) & 0xF0) >> 4;
}

template<class T>
uint16_t FecBaseSpecificTrainerData<T>::getAccumulatedPower() {
    return this->get16BitValue(ACCUMULATEDPOWER_LSB_BYTE,
            ACCUMULATEDPOWER_MSB_BYTE);
}

template<class T>
uint16_t FecBaseSpecificTrainerData<T>::getInstantaneousPower() {
    return this->get16BitValue(INSTANTANEOUSPOWER_LSB_BYTE,
            INSTANTANEOUSPOWER_MSB_BYTE) & 0x0FFF;
}

template<class T>
uint8_t FecBaseSpecificTrainerData<T>::getTrainerStatusBits() {
    return (this->get8BitValue(TRAINERSTATUS_BYTE) & 0xF0) >> 4;
}

template class FecBaseSpecificTrainerData<BroadcastData>;
template class FecBaseSpecificTrainerData<BroadcastDataMsg>;

FecSpecificTrainerData::FecSpecificTrainerData(AntRxDataResponse& dp) :
    BaseDataPage<BroadcastData>(dp),
    FecBaseSpecificTrainerData<BroadcastData>() {}
