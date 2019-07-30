#include <Profiles/HeartRate/DataPages/TX/ANTPLUS_HeartRatePreviousHeartBeatMsg.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRateDefines.h>

HeartRatePreviousHeartBeatMsg::HeartRatePreviousHeartBeatMsg() : HeartRateBaseMainDataPageMsg(ANTPLUS_HEARTRATE_DATAPAGE_PREVIOUSHEARTBEAT_NUMBER), HeartRateBasePreviousHeartBeat<BroadcastDataMsg>() {
    setManufacturerSpecific(ANTPLUS_HEARTRATE_DATAPAGE_PREVIOUSHEARTBEAT_MANUFACTURERSPECIFIC_INVALID);
}

void HeartRatePreviousHeartBeatMsg::setManufacturerSpecific(uint8_t specificByte) {
    set8BitValue(specificByte,
            ANTPLUS_HEARTRATE_DATAPAGE_PREVIOUSHEARTBEAT_MANUFACTURERSPECIFIC_BYTE);
}

void HeartRatePreviousHeartBeatMsg::setPreviousHeartBeatEventTime(uint16_t eventTime) {
    set16BitValue(eventTime,
            ANTPLUS_HEARTRATE_DATAPAGE_PREVIOUSHEARTBEAT_PREVIOUSHEARTBEATEVENTTIMELSB_BYTE,
            ANTPLUS_HEARTRATE_DATAPAGE_PREVIOUSHEARTBEAT_PREVIOUSHEARTBEATEVENTTIMEMSB_BYTE);
}
