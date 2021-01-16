#include <Profiles/HeartRate/DataPages/ANTPLUS_HeartRateBaseMainDataPage.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

template<class T>
HeartRateCoreMainDataPage<T>::HeartRateCoreMainDataPage() : CoreDataPage<T>() {
}

template<class T>
uint8_t HeartRateCoreMainDataPage<T>::getDataPageNumber() {
    return this->get8BitValue(
            ANTPLUS_HEARTRATE_DATAPAGEBASE_DATAPAGE_BYTE,
            ANTPLUS_HEARTRATE_DATAPAGEBASE_DATAPAGE_MASK);
}

template<class T>
uint8_t HeartRateCoreMainDataPage<T>::getPageChangeToggle() {
    return this->get8BitValue(
            ANTPLUS_HEARTRATE_DATAPAGEBASE_TOGGLE_BYTE,
            ANTPLUS_HEARTRATE_DATAPAGEBASE_TOGGLE_MASK,
            ANTPLUS_HEARTRATE_DATAPAGEBASE_TOGGLE_SHIFT);
}

template<class T>
uint16_t HeartRateCoreMainDataPage<T>::getHeartBeatEventTime() {
    return this->get16BitValue(
            ANTPLUS_HEARTRATE_DATAPAGEBASE_HEARTBEATEVENTTIMELSB_BYTE,
            ANTPLUS_HEARTRATE_DATAPAGEBASE_HEARTBEATEVENTTIMEMSB_BYTE);
}

template<class T>
uint8_t HeartRateCoreMainDataPage<T>::getHeartBeatCount() {
    return this->get8BitValue(
            ANTPLUS_HEARTRATE_DATAPAGEBASE_HEARTBEATCOUNT_BYTE);
}

template<class T>
uint8_t HeartRateCoreMainDataPage<T>::getComputedHeartRate() {
    return this->get8BitValue(
            ANTPLUS_HEARTRATE_DATAPAGEBASE_COMPUTEDHEARTRATE_BYTE);
}

template class HeartRateCoreMainDataPage<BroadcastData>;
template class HeartRateCoreMainDataPage<BroadcastDataMsg>;

HeartRateBaseMainDataPage::HeartRateBaseMainDataPage(AntRxDataResponse& dp) : BaseDataPage<BroadcastData>(dp), HeartRateCoreMainDataPage<BroadcastData>() {
}

HeartRateBaseMainDataPageMsg::HeartRateBaseMainDataPageMsg(uint8_t dataPageNumber) : BaseDataPageMsg<BroadcastDataMsg>(), HeartRateCoreMainDataPage<BroadcastDataMsg>() {
    setDataBuffer(_buffer);
    _buffer[ANTPLUS_DEFAULT_DATAPAGE_BYTE] = dataPageNumber;
}

void HeartRateBaseMainDataPageMsg::setPageChangeToggle(uint8_t toggle) {
    set8BitValue(toggle ? 1 : 0,
            ANTPLUS_HEARTRATE_DATAPAGEBASE_TOGGLE_BYTE,
            ANTPLUS_HEARTRATE_DATAPAGEBASE_TOGGLE_MASK,
            ANTPLUS_HEARTRATE_DATAPAGEBASE_TOGGLE_SHIFT);
}

void HeartRateBaseMainDataPageMsg::setHeartBeatEventTime(uint16_t time) {
    set16BitValue(time,
            ANTPLUS_HEARTRATE_DATAPAGEBASE_HEARTBEATEVENTTIMELSB_BYTE,
            ANTPLUS_HEARTRATE_DATAPAGEBASE_HEARTBEATEVENTTIMEMSB_BYTE);
}

void HeartRateBaseMainDataPageMsg::setHeartBeatCount(uint8_t count) {
    set8BitValue(count,
            ANTPLUS_HEARTRATE_DATAPAGEBASE_HEARTBEATCOUNT_BYTE);
}

void HeartRateBaseMainDataPageMsg::setComputedHeartRate(uint8_t heartRate) {
    set8BitValue(heartRate,
            ANTPLUS_HEARTRATE_DATAPAGEBASE_COMPUTEDHEARTRATE_BYTE);
}
