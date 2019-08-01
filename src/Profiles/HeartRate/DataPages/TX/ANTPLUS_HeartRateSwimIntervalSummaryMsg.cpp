#include <Profiles/HeartRate/DataPages/TX/ANTPLUS_HeartRateSwimIntervalSummaryMsg.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRateDefines.h>

HeartRateSwimIntervalSummaryMsg::HeartRateSwimIntervalSummaryMsg() : HeartRateBaseMainDataPageMsg(ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_NUMBER), HeartRateBaseSwimIntervalSummary<BroadcastDataMsg>() {
    setIntervalAverageHeartRate(ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_INTERVALAVERAGEHEARTRATE_INVALID);
    setIntervalMaximumHeartRate(ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_INTERVALMAXIMUMHEARTRATE_INVALID);
    setSessionAverageHeartRate(ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_SESSIONAVERAGEHEARTRATE_INVALID);
}

void HeartRateSwimIntervalSummaryMsg::setIntervalAverageHeartRate(uint8_t intervalAverage) {
    set8BitValue(intervalAverage,
            ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_INTERVALAVERAGEHEARTRATE_BYTE);
}

void HeartRateSwimIntervalSummaryMsg::setIntervalMaximumHeartRate(uint8_t intervalMaximum) {
    set8BitValue(intervalMaximum,
            ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_INTERVALMAXIMUMHEARTRATE_BYTE);
}

void HeartRateSwimIntervalSummaryMsg::setSessionAverageHeartRate(uint8_t sessionAverage) {
    set8BitValue(sessionAverage,
            ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_SESSIONAVERAGEHEARTRATE_BYTE);
}
