#include <Profiles/HeartRate/DataPages/RX/ANTPLUS_HeartRateSwimIntervalSummary.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

HeartRateSwimIntervalSummary::HeartRateSwimIntervalSummary(AntRxDataResponse& dp) : HeartRateBaseMainDataPage(dp) {

}

uint8_t HeartRateSwimIntervalSummary::getIntervalAverageHeartRate() {
    return getData(ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_INTERVALAVERAGEHEARTRATE_BYTE);
}

uint8_t HeartRateSwimIntervalSummary::getIntervalMaximumHeartRate() {
    return getData(ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_INTERVALMAXIMUMHEARTRATE_BYTE);
}

uint8_t HeartRateSwimIntervalSummary::getSessionAverageHeartRate() {
    return getData(ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_SESSIONAVERAGEHEARTRATE_BYTE);
}
