#include <Profiles/HeartRate/DataPages/RX/ANTPLUS_HeartRatePreviousHeartBeat.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

HeartRatePreviousHeartBeat::HeartRatePreviousHeartBeat(AntRxDataResponse& dp) : HeartRateBaseMainDataPage(dp) {

}

uint8_t HeartRatePreviousHeartBeat::getManufacturerSpecific() {
    return getData(ANTPLUS_HEARTRATE_DATAPAGE_PREVIOUSHEARTBEAT_MANUFACTURERSPECIFIC_BYTE);
}

uint16_t HeartRatePreviousHeartBeat::getPreviousHeartBeatEventTime() {
    return getData(ANTPLUS_HEARTRATE_DATAPAGE_PREVIOUSHEARTBEAT_PREVIOUSHEARTBEATEVENTTIMELSB_BYTE) | (getData(ANTPLUS_HEARTRATE_DATAPAGE_PREVIOUSHEARTBEAT_PREVIOUSHEARTBEATEVENTTIMEMSB_BYTE) << ANTPLUS_HEARTRATE_DATAPAGE_PREVIOUSHEARTBEAT_PREVIOUSHEARTBEATEVENTTIMEMSB_SHIFT);
}
