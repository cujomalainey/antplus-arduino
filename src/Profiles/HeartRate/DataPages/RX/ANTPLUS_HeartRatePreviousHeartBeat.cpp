#include <Profiles/HeartRate/DataPages/RX/ANTPLUS_HeartRatePreviousHeartBeat.h>

HeartRatePreviousHeartBeat::HeartRatePreviousHeartBeat(AntRxDataResponse& dp) : HeartRateBaseMainDataPage(dp) {

}

uint8_t HeartRatePreviousHeartBeat::getManufacturerSpecific() {
    // TODO
}

uint16_t HeartRatePreviousHeartBeat::getPreviousHeartBeatEventTime() {
    // TODO
}
