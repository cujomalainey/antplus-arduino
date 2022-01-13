#include <Profiles/Fec/DataPages/ANTPLUS_FecBaseMainDataPage.h>
#include <Profiles/Fec/ANTPLUS_FecPrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

#define DATAPAGE_BYTE 0
#define TOGGLE_BYTE   0
#define HEARTBEATEVENTTIME_LSB_BYTE 4
#define HEARTBEATEVENTTIME_MSB_BYTE 5
#define HEARTBEATCOUNT_BYTE 6
#define COMPUTEDHEARTRATE_BYTE 7
#define DATAPAGE_MASK 0x7F
#define TOGGLE_MASK   0x80
#define TOGGLE_SHIFT  7

template<class T>
FecCoreMainDataPage<T>::FecCoreMainDataPage() : CoreDataPage<T>() {}

template<class T>
uint8_t FecCoreMainDataPage<T>::getDataPageNumber() {
    return this->get8BitValue(DATAPAGE_BYTE, DATAPAGE_MASK);
}

template<class T>
uint8_t FecCoreMainDataPage<T>::getPageChangeToggle() {
    return this->get8BitValue(TOGGLE_BYTE, TOGGLE_MASK, TOGGLE_SHIFT);
}

template<class T>
uint16_t FecCoreMainDataPage<T>::getHeartBeatEventTime() {
    return this->get16BitValue(HEARTBEATEVENTTIME_LSB_BYTE, HEARTBEATEVENTTIME_MSB_BYTE);
}

template<class T>
uint8_t FecCoreMainDataPage<T>::getHeartBeatCount() {
    return this->get8BitValue(HEARTBEATCOUNT_BYTE);
}

template<class T>
uint8_t FecCoreMainDataPage<T>::getComputedHeartRate() {
    return this->get8BitValue(COMPUTEDHEARTRATE_BYTE);
}

template class FecCoreMainDataPage<BroadcastData>;
template class FecCoreMainDataPage<BroadcastDataMsg>;

FecBaseMainDataPage::FecBaseMainDataPage(AntRxDataResponse& dp) :
    BaseDataPage<BroadcastData>(dp),
    FecCoreMainDataPage<BroadcastData>() {}

FecBaseMainDataPageMsg::FecBaseMainDataPageMsg(uint8_t dataPageNumber) :
    BaseDataPageMsg<BroadcastDataMsg>(),
    FecCoreMainDataPage<BroadcastDataMsg>() {
    setDataBuffer(_buffer);
    set8BitValue(dataPageNumber, ANTPLUS_DEFAULT_DATAPAGE_BYTE);
}

void FecBaseMainDataPageMsg::setPageChangeToggle(uint8_t toggle) {
    set8BitValue(toggle ? 1 : 0, TOGGLE_BYTE, TOGGLE_MASK, TOGGLE_SHIFT);
}

void FecBaseMainDataPageMsg::setHeartBeatEventTime(uint16_t time) {
    set16BitValue(time, HEARTBEATEVENTTIME_LSB_BYTE,
            HEARTBEATEVENTTIME_MSB_BYTE);
}

void FecBaseMainDataPageMsg::setHeartBeatCount(uint8_t count) {
    set8BitValue(count, HEARTBEATCOUNT_BYTE);
}

void FecBaseMainDataPageMsg::setComputedHeartRate(uint8_t heartRate) {
    set8BitValue(heartRate, COMPUTEDHEARTRATE_BYTE);
}
