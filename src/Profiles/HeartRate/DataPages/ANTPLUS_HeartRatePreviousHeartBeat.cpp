#include <Profiles/HeartRate/DataPages/ANTPLUS_HeartRatePreviousHeartBeat.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRateDefines.h>

#define MANUFACTURERSPECIFIC_BYTE 1
#define PREVIOUSHEARTBEATEVENTTIME_LSB_BYTE 2
#define PREVIOUSHEARTBEATEVENTTIME_MSB_BYTE 3

template<class T>
HeartRateBasePreviousHeartBeat<T>::HeartRateBasePreviousHeartBeat() :
    CoreDataPage<T>() {}

template<class T>
uint8_t HeartRateBasePreviousHeartBeat<T>::getManufacturerSpecific() {
    return this->get8BitValue(MANUFACTURERSPECIFIC_BYTE);
}

template<class T>
uint16_t HeartRateBasePreviousHeartBeat<T>::getPreviousHeartBeatEventTime() {
    return this->get16BitValue(
            PREVIOUSHEARTBEATEVENTTIME_LSB_BYTE,
            PREVIOUSHEARTBEATEVENTTIME_MSB_BYTE);
}

template class HeartRateBasePreviousHeartBeat<BroadcastData>;
template class HeartRateBasePreviousHeartBeat<BroadcastDataMsg>;

HeartRatePreviousHeartBeat::HeartRatePreviousHeartBeat(AntRxDataResponse& dp) :
    HeartRateBaseMainDataPage(dp),
    HeartRateBasePreviousHeartBeat<BroadcastData>() {}

// TODO add isValid method to manufactueres byte
HeartRatePreviousHeartBeatMsg::HeartRatePreviousHeartBeatMsg() :
    HeartRateBaseMainDataPageMsg(PREVIOUSHEARTBEAT_NUMBER),
    HeartRateBasePreviousHeartBeat<BroadcastDataMsg>() {
    setManufacturerSpecific(
            ANTPLUS_HEARTRATE_DATAPAGE_PREVIOUSHEARTBEAT_MANUFACTURERSPECIFIC_INVALID);
}

void HeartRatePreviousHeartBeatMsg::setManufacturerSpecific(uint8_t specificByte) {
    set8BitValue(specificByte, MANUFACTURERSPECIFIC_BYTE);
}

void HeartRatePreviousHeartBeatMsg::setPreviousHeartBeatEventTime(uint16_t eventTime) {
    set16BitValue(eventTime,
            PREVIOUSHEARTBEATEVENTTIME_LSB_BYTE,
            PREVIOUSHEARTBEATEVENTTIME_MSB_BYTE);
}
