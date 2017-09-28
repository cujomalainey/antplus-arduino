#include <Profiles/HeartRate/DataPages/TX/ANTPLUS_HeartRateSwimIntervalSummaryMsg.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

HeartRateSwimIntervalSummaryMsg::HeartRateSwimIntervalSummaryMsg() : HeartRateBaseMainDataPageMsg(ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_NUMBER) {

}

uint8_t HeartRateSwimIntervalSummaryMsg::getIntervalAverageHeartRate() {
    // TODO
}

uint8_t HeartRateSwimIntervalSummaryMsg::getIntervalMaximumHeartRate() {
    // TODO
}

uint8_t HeartRateSwimIntervalSummaryMsg::getSessionAverageHeartRate() {
    // TODO
}

void HeartRateSwimIntervalSummaryMsg::setIntervalAverageHeartRate(uint8_t intervalAverage) {
    // TODO
}

void HeartRateSwimIntervalSummaryMsg::setIntervalMaximumHeartRate(uint8_t intervalMaximum) {
    // TODO
}

void HeartRateSwimIntervalSummaryMsg::setSessionAverageHeartRate(uint8_t sessionAverage) {
    // TODO
}
