#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateCoreMainDataPage.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

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
