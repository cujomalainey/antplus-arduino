#include <Profiles/HeartRate/DataPages/TX/ANTPLUS_HeartRatePreviousHeartBeatMsg.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

HeartRatePreviousHeartBeatMsg::HeartRatePreviousHeartBeatMsg() : HeartRateBaseMainDataPageMsg(ANTPLUS_HEARTRATE_DATAPAGE_PREVIOUSHEARTBEAT_NUMBER) {

}

uint8_t HeartRatePreviousHeartBeatMsg::getManufacturerSpecific() {
    // TODO
}

uint16_t HeartRatePreviousHeartBeatMsg::getPreviousHeartBeatEventTime() {
    // TODO
}

void HeartRatePreviousHeartBeatMsg::setManufacturerSpecific(uint8_t specificByte) {
    // TODO
}

void HeartRatePreviousHeartBeatMsg::setPreviousHeartBeatEventTime(uint16_t eventTime) {
    // TODO
}
