#include <Profiles/HeartRate/DataPages/ANTPLUS_HeartRateSwimIntervalSummary.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRateDefines.h>

#define INTERVALAVERAGEHEARTRATE_BYTE 1
#define INTERVALMAXIMUMHEARTRATE_BYTE 2
#define SESSIONAVERAGEHEARTRATE_BYTE 3

template<class T>
HeartRateBaseSwimIntervalSummary<T>::HeartRateBaseSwimIntervalSummary() :
    CoreDataPage<T>() {}

template<class T>
uint8_t HeartRateBaseSwimIntervalSummary<T>::getIntervalAverageHeartRate() {
    return this->get8BitValue(INTERVALAVERAGEHEARTRATE_BYTE);
}

template<class T>
uint8_t HeartRateBaseSwimIntervalSummary<T>::getIntervalMaximumHeartRate() {
    return this->get8BitValue(INTERVALMAXIMUMHEARTRATE_BYTE);
}

template<class T>
uint8_t HeartRateBaseSwimIntervalSummary<T>::getSessionAverageHeartRate() {
    return this->get8BitValue(SESSIONAVERAGEHEARTRATE_BYTE);
}

template class HeartRateBaseSwimIntervalSummary<BroadcastData>;
template class HeartRateBaseSwimIntervalSummary<BroadcastDataMsg>;

HeartRateSwimIntervalSummary::HeartRateSwimIntervalSummary(AntRxDataResponse& dp) :
    HeartRateBaseMainDataPage(dp),
    HeartRateBaseSwimIntervalSummary<BroadcastData>() {}

HeartRateSwimIntervalSummaryMsg::HeartRateSwimIntervalSummaryMsg() :
    HeartRateBaseMainDataPageMsg(HEARTRATE_SWIMINTERVALSUMMARY_NUMBER),
    HeartRateBaseSwimIntervalSummary<BroadcastDataMsg>() {
    setIntervalAverageHeartRate(ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_INTERVALAVERAGEHEARTRATE_INVALID);
    setIntervalMaximumHeartRate(ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_INTERVALMAXIMUMHEARTRATE_INVALID);
    setSessionAverageHeartRate(ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_SESSIONAVERAGEHEARTRATE_INVALID);
}

void HeartRateSwimIntervalSummaryMsg::setIntervalAverageHeartRate(uint8_t intervalAverage) {
    set8BitValue(intervalAverage, INTERVALAVERAGEHEARTRATE_BYTE);
}

void HeartRateSwimIntervalSummaryMsg::setIntervalMaximumHeartRate(uint8_t intervalMaximum) {
    set8BitValue(intervalMaximum, INTERVALMAXIMUMHEARTRATE_BYTE);
}

void HeartRateSwimIntervalSummaryMsg::setSessionAverageHeartRate(uint8_t sessionAverage) {
    set8BitValue(sessionAverage, SESSIONAVERAGEHEARTRATE_BYTE);
}

