#include <Profiles/HeartRate/DataPages/ANTPLUS_HeartRateBaseMainDataPage.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>
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
HeartRateCoreMainDataPage<T>::HeartRateCoreMainDataPage() : CoreDataPage<T>() {}

template<class T>
uint8_t HeartRateCoreMainDataPage<T>::getDataPageNumber() {
    return this->get8BitValue(DATAPAGE_BYTE, DATAPAGE_MASK);
}

template<class T>
uint8_t HeartRateCoreMainDataPage<T>::getPageChangeToggle() {
    return this->get8BitValue(TOGGLE_BYTE, TOGGLE_MASK, TOGGLE_SHIFT);
}

template<class T>
uint16_t HeartRateCoreMainDataPage<T>::getHeartBeatEventTime() {
    return this->get16BitValue(HEARTBEATEVENTTIME_LSB_BYTE, HEARTBEATEVENTTIME_MSB_BYTE);
}

template<class T>
uint8_t HeartRateCoreMainDataPage<T>::getHeartBeatCount() {
    return this->get8BitValue(HEARTBEATCOUNT_BYTE);
}

template<class T>
uint8_t HeartRateCoreMainDataPage<T>::getComputedHeartRate() {
    return this->get8BitValue(COMPUTEDHEARTRATE_BYTE);
}

template class HeartRateCoreMainDataPage<BroadcastData>;
template class HeartRateCoreMainDataPage<BroadcastDataMsg>;

HeartRateBaseMainDataPage::HeartRateBaseMainDataPage(AntRxDataResponse& dp) :
    BaseDataPage<BroadcastData>(dp),
    HeartRateCoreMainDataPage<BroadcastData>() {}

HeartRateBaseMainDataPageMsg::HeartRateBaseMainDataPageMsg(uint8_t dataPageNumber) :
    BaseDataPageMsg<BroadcastDataMsg>(),
    HeartRateCoreMainDataPage<BroadcastDataMsg>() {
    setDataBuffer(_buffer);
    set8BitValue(dataPageNumber, ANTPLUS_DEFAULT_DATAPAGE_BYTE);
}

void HeartRateBaseMainDataPageMsg::setPageChangeToggle(uint8_t toggle) {
    set8BitValue(toggle ? 1 : 0, TOGGLE_BYTE, TOGGLE_MASK, TOGGLE_SHIFT);
}

void HeartRateBaseMainDataPageMsg::setHeartBeatEventTime(uint16_t time) {
    set16BitValue(time, HEARTBEATEVENTTIME_LSB_BYTE,
            HEARTBEATEVENTTIME_MSB_BYTE);
}

void HeartRateBaseMainDataPageMsg::setHeartBeatCount(uint8_t count) {
    set8BitValue(count, HEARTBEATCOUNT_BYTE);
}

void HeartRateBaseMainDataPageMsg::setComputedHeartRate(uint8_t heartRate) {
    set8BitValue(heartRate, COMPUTEDHEARTRATE_BYTE);
}
