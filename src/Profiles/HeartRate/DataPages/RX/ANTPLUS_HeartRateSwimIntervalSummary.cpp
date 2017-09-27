#include <Profiles/HeartRate/DataPages/RX/ANTPLUS_HeartRateSwimIntervalSummary.h>

HeartRateSwimIntervalSummary::HeartRateSwimIntervalSummary(AntRxDataResponse& dp) : HeartRateBaseMainDataPage(dp) {

}

uint8_t HeartRateSwimIntervalSummary::getIntervalAverageHeartRate() {
    // TODO
}

uint8_t HeartRateSwimIntervalSummary::getIntervalMaximumHeartRate() {
    // TODO
}

uint8_t HeartRateSwimIntervalSummary::getSessionAverageHeartRate() {
    // TODO
}
