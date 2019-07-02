#include <Profiles/HeartRate/DataPages/TX/ANTPLUS_HeartRateSwimIntervalSummaryMsg.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRateDefines.h>

HeartRateSwimIntervalSummaryMsg::HeartRateSwimIntervalSummaryMsg() : HeartRateBaseMainDataPageMsg(ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_NUMBER) {
    setIntervalAverageHeartRate(ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_INTERVALAVERAGEHEARTRATE_INVALID);
    setIntervalMaximumHeartRate(ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_INTERVALMAXIMUMHEARTRATE_INVALID);
    setSessionAverageHeartRate(ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_SESSIONAVERAGEHEARTRATE_INVALID);
}

uint8_t HeartRateSwimIntervalSummaryMsg::getIntervalAverageHeartRate() {
    return _buffer[ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_INTERVALAVERAGEHEARTRATE_BYTE];
}

uint8_t HeartRateSwimIntervalSummaryMsg::getIntervalMaximumHeartRate() {
    return _buffer[ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_INTERVALMAXIMUMHEARTRATE_BYTE];
}

uint8_t HeartRateSwimIntervalSummaryMsg::getSessionAverageHeartRate() {
    return _buffer[ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_SESSIONAVERAGEHEARTRATE_BYTE];
}

void HeartRateSwimIntervalSummaryMsg::setIntervalAverageHeartRate(uint8_t intervalAverage) {
    _buffer[ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_INTERVALAVERAGEHEARTRATE_BYTE] = intervalAverage;
}

void HeartRateSwimIntervalSummaryMsg::setIntervalMaximumHeartRate(uint8_t intervalMaximum) {
    _buffer[ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_INTERVALMAXIMUMHEARTRATE_BYTE] = intervalMaximum;
}

void HeartRateSwimIntervalSummaryMsg::setSessionAverageHeartRate(uint8_t sessionAverage) {
    _buffer[ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_SESSIONAVERAGEHEARTRATE_BYTE] = sessionAverage;
}
