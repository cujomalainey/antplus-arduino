#include <Profiles/HeartRate/DataPages/TX/ANTPLUS_HeartRatePreviousHeartBeatMsg.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

HeartRatePreviousHeartBeatMsg::HeartRatePreviousHeartBeatMsg() : HeartRateBaseMainDataPageMsg(ANTPLUS_HEARTRATE_DATAPAGE_PREVIOUSHEARTBEAT_NUMBER) {
    setManufacturerSpecific(ANTPLUS_HEARTRATE_DATAPAGE_PREVIOUSHEARTBEAT_MANUFACTURERSPECIFIC_INVALID);
}

uint8_t HeartRatePreviousHeartBeatMsg::getManufacturerSpecific() {
    // TODO
}

uint16_t HeartRatePreviousHeartBeatMsg::getPreviousHeartBeatEventTime() {
    // TODO
}

void HeartRatePreviousHeartBeatMsg::setManufacturerSpecific(uint8_t specificByte) {
    _buffer[ANTPLUS_HEARTRATE_DATAPAGE_PREVIOUSHEARTBEAT_MANUFACTURERSPECIFIC_BYTE] = specificByte;
}

void HeartRatePreviousHeartBeatMsg::setPreviousHeartBeatEventTime(uint16_t eventTime) {
    // TODO
}
