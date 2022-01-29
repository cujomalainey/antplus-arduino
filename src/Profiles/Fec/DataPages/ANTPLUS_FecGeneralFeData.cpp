#include <Profiles/Fec/DataPages/ANTPLUS_FecGeneralFeData.h>
#include <Profiles/Fec/ANTPLUS_FecPrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

#define FETYPE_BYTE 1
#define FETYPE_MASK 0x0F
#define ELAPSEDTIME_BYTE 2
#define DISTANCETRAVELED_BYTE 3
#define SPEED_LSB_BYTE 4
#define SPEED_MSB_BYTE 5
#define HEARTRATE_BYTE 6
#define HRDATASOURCE_BYTE 7
#define HRDATASOURCE_MASK 0x03
#define DISTANCETRAVELEDENABLED_BYTE 7
#define DISTANCETRAVELEDENABLED_MASK 0x04
#define DISTANCETRAVELEDENABLED_SHIFT 2
#define VIRTUALSPEEDFLAG_BYTE 7
#define VIRTUALSPEEDFLAG_MASK 0x08
#define VIRTUALSPEEDFLAG_SHIFT 3

template<class T>
FecBaseGeneralFeData<T>::FecBaseGeneralFeData() : CoreDataPage<T>() {}

template<class T>
uint8_t FecBaseGeneralFeData<T>::getFeType() {
    return this->get8BitValue(FETYPE_BYTE, FETYPE_MASK);
}

template<class T>
uint8_t FecBaseGeneralFeData<T>::getElapsedTime() {
    return this->get8BitValue(ELAPSEDTIME_BYTE);
}

template<class T>
uint8_t FecBaseGeneralFeData<T>::getDistanceTraveled() {
    return this->get8BitValue(DISTANCETRAVELED_BYTE);
}

template<class T>
uint16_t FecBaseGeneralFeData<T>::getSpeed() {
    return this->get16BitValue(SPEED_LSB_BYTE, SPEED_MSB_BYTE);
}

template<class T>
uint8_t FecBaseGeneralFeData<T>::getHeartRate() {
    return this->get8BitValue(HEARTRATE_BYTE);
}

template<class T>
uint8_t FecBaseGeneralFeData<T>::getHrDataSource() {
    return this->get8BitValue(HRDATASOURCE_BYTE, HRDATASOURCE_MASK);
}

template<class T>
uint8_t FecBaseGeneralFeData<T>::getDistanceTraveledEnabled() {
    return this->get8BitValue(DISTANCETRAVELEDENABLED_BYTE,
            DISTANCETRAVELEDENABLED_MASK,
            DISTANCETRAVELEDENABLED_SHIFT);
}

template<class T>
uint8_t FecBaseGeneralFeData<T>::getVirtualSpeedFlag() {
    return this->get8BitValue(VIRTUALSPEEDFLAG_BYTE,
            VIRTUALSPEEDFLAG_MASK,
            VIRTUALSPEEDFLAG_SHIFT);
}

template<class T>
uint8_t FecBaseGeneralFeData<T>::getFeState() {
    return this->get8BitValue(FESTATE_BYTE, FESTATE_MASK, FESTATE_SHIFT);
}

template<class T>
uint8_t FecBaseGeneralFeData<T>::getLapToggleBit() {
    return this->get8BitValue(LAPTOGGLEBIT_BYTE, LAPTOGGLEBIT_MASK, LAPTOGGLEBIT_SHIFT);
}

template class FecBaseGeneralFeData<BroadcastData>;
template class FecBaseGeneralFeData<BroadcastDataMsg>;

FecGeneralFeData::FecGeneralFeData(AntRxDataResponse& dp) :
    FecBaseMainDataPage(dp),
    FecBaseGeneralFeData<BroadcastData>() {}

FecGeneralFeDataMsg::FecGeneralFeDataMsg() :
    FecBaseMainDataPageMsg(GENERAL_FE_DATA_NUMBER),
    FecBaseGeneralFeData<BroadcastDataMsg>() {
    setSpeed(ANTPLUS_FEC_DATAPAGE_GENERALFEDATA_SPEED_INVALID);
    setHeartRate(ANTPLUS_FEC_DATAPAGE_GENERALFEDATA_HEARTRATE_INVALID);
    setFeType(ANTPLUS_FEC_DATAPAGE_GENERALFEDATA_FETYPE_GENERAL);
    setHrDataSource(ANTPLUS_FEC_DATAPAGE_GENERALFEDATA_HRDATASOURCE_INVALID);
    setFeState(ANTPLUS_FEC_DATAPAGE_FESTATE_INUSE);
}

void FecGeneralFeDataMsg::setFeType(uint8_t fe_type) {
}

void FecGeneralFeDataMsg::setElapsedTime(uint8_t time) {
    set8BitValue(time, ELAPSEDTIME_BYTE);
}

void FecGeneralFeDataMsg::setDistanceTraveled(uint8_t distance) {
    set8BitValue(distance, DISTANCETRAVELED_BYTE);
}

void FecGeneralFeDataMsg::setSpeed(uint16_t speed) {
    set16BitValue(speed, SPEED_LSB_BYTE, SPEED_MSB_BYTE);
}

void FecGeneralFeDataMsg::setHeartRate(uint8_t hr) {
    set8BitValue(hr, HEARTRATE_BYTE);
}

void FecGeneralFeDataMsg::setHrDataSource(uint8_t source) {
    set8BitValue(source, HRDATASOURCE_BYTE, HRDATASOURCE_MASK);
}

void FecGeneralFeDataMsg::setDistanceTraveledEnabled(uint8_t enabled) {
    set8BitValue(enabled,
            DISTANCETRAVELEDENABLED_BYTE,
            DISTANCETRAVELEDENABLED_MASK,
            DISTANCETRAVELEDENABLED_SHIFT);
}

void FecGeneralFeDataMsg::setVirtualSpeedFlag(uint8_t real) {
    set8BitValue(real, VIRTUALSPEEDFLAG_BYTE, VIRTUALSPEEDFLAG_MASK, VIRTUALSPEEDFLAG_SHIFT);
}

void FecGeneralFeDataMsg::setFeState(uint8_t state) {
    set8BitValue(state, FESTATE_BYTE, FESTATE_MASK, FESTATE_SHIFT);
}

void FecGeneralFeDataMsg::setLapToggleBit(uint8_t bit) {
    set8BitValue(bit, LAPTOGGLEBIT_BYTE, LAPTOGGLEBIT_MASK, LAPTOGGLEBIT_SHIFT);
}
