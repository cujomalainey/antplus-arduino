#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseSwimIntervalSummary.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

template<class T>
HeartRateBaseSwimIntervalSummary<T>::HeartRateBaseSwimIntervalSummary() : CoreDataPage<T>() {
}

template<class T>
uint8_t HeartRateBaseSwimIntervalSummary<T>::getIntervalAverageHeartRate() {
    return this->get8BitValue(
            ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_INTERVALAVERAGEHEARTRATE_BYTE);
}

template<class T>
uint8_t HeartRateBaseSwimIntervalSummary<T>::getIntervalMaximumHeartRate() {
    return this->get8BitValue(
            ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_INTERVALMAXIMUMHEARTRATE_BYTE);
}

template<class T>
uint8_t HeartRateBaseSwimIntervalSummary<T>::getSessionAverageHeartRate() {
    return this->get8BitValue(
            ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_SESSIONAVERAGEHEARTRATE_BYTE);
}

template class HeartRateBaseSwimIntervalSummary<BroadcastData>;
template class HeartRateBaseSwimIntervalSummary<BroadcastDataMsg>;
