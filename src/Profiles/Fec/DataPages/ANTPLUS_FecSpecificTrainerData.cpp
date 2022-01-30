#include <Profiles/Fec/DataPages/ANTPLUS_FecSpecificTrainerData.h>
#include <Profiles/Fec/ANTPLUS_FecPrivateDefines.h>

#define UPDATEEVENTCOUNT_BYTE 1
#define INSTANTANEOUSCADENCE_BYTE 2
#define ACCUMULATEDPOWER_LSB_BYTE 3
#define ACCUMULATEDPOWER_MSB_BYTE 4
#define INSTANTANEOUSPOWER_LSB_BYTE 5
#define INSTANTANEOUSPOWER_MSB_BYTE 6
#define INSTANTANEOUSPOWER_MSB_MASK 0x0FFF
#define BICYCLEPOWERCALIBRATION_BYTE 6
#define BICYCLEPOWERCALIBRATION_MASK 0x10
#define BICYCLEPOWERCALIBRATION_SHIFT 4
#define RESISTANCECALIBRATION_BYTE 6
#define RESISTANCECALIBRATION_MASK 0x20
#define RESISTANCECALIBRATION_SHIFT 5
#define USERCONFIGURATION_BYTE 6
#define USERCONFIGURATION_MASK 0x40
#define USERCONFIGURATION_SHIFT 6
#define TARGETPOWERLIMITS_BYTE 7
#define TARGETPOWERLIMITS_MASK 0x03

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
uint16_t FecBaseSpecificTrainerData<T>::getAccumulatedPower() {
    return this->get16BitValue(ACCUMULATEDPOWER_LSB_BYTE,
            ACCUMULATEDPOWER_MSB_BYTE);
}

template<class T>
uint16_t FecBaseSpecificTrainerData<T>::getInstantaneousPower() {
    return this->get16BitValue(INSTANTANEOUSPOWER_LSB_BYTE,
            INSTANTANEOUSPOWER_MSB_BYTE,
            INSTANTANEOUSPOWER_MSB_MASK);
}

template<class T>
uint8_t FecBaseSpecificTrainerData<T>::getBicyclePowerCalibration() {
    return this->get8BitValue(BICYCLEPOWERCALIBRATION_BYTE,
            BICYCLEPOWERCALIBRATION_MASK,
            BICYCLEPOWERCALIBRATION_SHIFT);
}

template<class T>
uint8_t FecBaseSpecificTrainerData<T>::getResistanceCalibration() {
    return this->get8BitValue(RESISTANCECALIBRATION_BYTE,
            RESISTANCECALIBRATION_MASK,
            RESISTANCECALIBRATION_SHIFT);
}

template<class T>
uint8_t FecBaseSpecificTrainerData<T>::getUserConfiguration() {
    return this->get8BitValue(USERCONFIGURATION_BYTE,
            USERCONFIGURATION_MASK,
            USERCONFIGURATION_SHIFT);
}

template<class T>
uint8_t FecBaseSpecificTrainerData<T>::getTargetPowerLimits() {
    return this->get8BitValue(TARGETPOWERLIMITS_BYTE, TARGETPOWERLIMITS_MASK);
}

template<class T>
uint8_t FecBaseSpecificTrainerData<T>::getFeState() {
    return this->get8BitValue(FESTATE_BYTE, FESTATE_MASK, FESTATE_SHIFT);
}

template<class T>
uint8_t FecBaseSpecificTrainerData<T>::getLapToggleBit() {
    return this->get8BitValue(LAPTOGGLEBIT_BYTE, LAPTOGGLEBIT_MASK, LAPTOGGLEBIT_SHIFT);
}

template class FecBaseSpecificTrainerData<BroadcastData>;
template class FecBaseSpecificTrainerData<BroadcastDataMsg>;

FecSpecificTrainerData::FecSpecificTrainerData(AntRxDataResponse& dp) :
    BaseDataPage<BroadcastData>(dp),
    FecBaseSpecificTrainerData<BroadcastData>() {}
