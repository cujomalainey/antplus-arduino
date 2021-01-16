#include <Profiles/HeartRate/DataPages/ANTPLUS_HeartRatePreviousHeartBeat.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRateDefines.h>

template<class T>
HeartRateBasePreviousHeartBeat<T>::HeartRateBasePreviousHeartBeat() : CoreDataPage<T>() {
}

template<class T>
uint8_t HeartRateBasePreviousHeartBeat<T>::getManufacturerSpecific() {
    return this->get8BitValue(
            ANTPLUS_HEARTRATE_DATAPAGE_PREVIOUSHEARTBEAT_MANUFACTURERSPECIFIC_BYTE);
}

template<class T>
uint16_t HeartRateBasePreviousHeartBeat<T>::getPreviousHeartBeatEventTime() {
    return this->get16BitValue(
            ANTPLUS_HEARTRATE_DATAPAGE_PREVIOUSHEARTBEAT_PREVIOUSHEARTBEATEVENTTIMELSB_BYTE,
            ANTPLUS_HEARTRATE_DATAPAGE_PREVIOUSHEARTBEAT_PREVIOUSHEARTBEATEVENTTIMEMSB_BYTE);
}

template class HeartRateBasePreviousHeartBeat<BroadcastData>;
template class HeartRateBasePreviousHeartBeat<BroadcastDataMsg>;

HeartRatePreviousHeartBeat::HeartRatePreviousHeartBeat(AntRxDataResponse& dp) : HeartRateBaseMainDataPage(dp), HeartRateBasePreviousHeartBeat<BroadcastData>() {}

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
