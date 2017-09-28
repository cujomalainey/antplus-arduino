#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPageMsg.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

HeartRateBaseMainDataPageMsg::HeartRateBaseMainDataPageMsg(uint8_t dataPageNumber) : BaseDataPageMsg<BroadcastDataMsg>() {
    setDataBuffer(_buffer);
    _buffer[ANTPLUS_DEFAULT_DATAPAGE_BYTE] = dataPageNumber;
}

uint8_t HeartRateBaseMainDataPageMsg::getPageChangeToggle() {
    return (_buffer[ANTPLUS_HEARTRATE_DATAPAGEBASE_TOGGLE_BYTE] & ANTPLUS_HEARTRATE_DATAPAGEBASE_TOGGLE_MASK) >> ANTPLUS_HEARTRATE_DATAPAGEBASE_TOGGLE_SHIFT;
}

uint16_t HeartRateBaseMainDataPageMsg::getHeartBeatEventTime() {
    return (_buffer[ANTPLUS_HEARTRATE_DATAPAGEBASE_HEARTBEATEVENTTIMEMSB_BYTE] << ANTPLUS_HEARTRATE_DATAPAGEBASE_HEARTBEATEVENTTIMEMSB_SHIFT) | _buffer[ANTPLUS_HEARTRATE_DATAPAGEBASE_HEARTBEATEVENTTIMELSB_BYTE];
}

uint8_t HeartRateBaseMainDataPageMsg::getHeartBeatCount() {
    return _buffer[ANTPLUS_HEARTRATE_DATAPAGEBASE_HEARTBEATCOUNT_BYTE];
}

uint8_t HeartRateBaseMainDataPageMsg::getComputedHeartRate() {
    return _buffer[ANTPLUS_HEARTRATE_DATAPAGEBASE_COMPUTEDHEARTRATE_BYTE];
}

void HeartRateBaseMainDataPageMsg::setPageChangeToggle(uint8_t toggle) {
    _buffer[ANTPLUS_HEARTRATE_DATAPAGEBASE_TOGGLE_BYTE] = _buffer[ANTPLUS_HEARTRATE_DATAPAGEBASE_TOGGLE_BYTE] & ~ANTPLUS_HEARTRATE_DATAPAGEBASE_TOGGLE_MASK;
    _buffer[ANTPLUS_HEARTRATE_DATAPAGEBASE_TOGGLE_BYTE] |= toggle ? ANTPLUS_HEARTRATE_DATAPAGEBASE_TOGGLE_MASK : 0;
}

void HeartRateBaseMainDataPageMsg::setHeartBeatEventTime(uint16_t time) {
    _buffer[ANTPLUS_HEARTRATE_DATAPAGEBASE_HEARTBEATEVENTTIMEMSB_BYTE] = time >> ANTPLUS_HEARTRATE_DATAPAGEBASE_HEARTBEATEVENTTIMEMSB_SHIFT;
    _buffer[ANTPLUS_HEARTRATE_DATAPAGEBASE_HEARTBEATEVENTTIMELSB_BYTE] = time & 0xFF;
    // TODO magic numbers
}

void HeartRateBaseMainDataPageMsg::setHeartBeatCount(uint8_t count) {
    _buffer[ANTPLUS_HEARTRATE_DATAPAGEBASE_HEARTBEATCOUNT_BYTE] = count;
}

void HeartRateBaseMainDataPageMsg::setComputedHeartRate(uint8_t heartRate) {
    _buffer[ANTPLUS_HEARTRATE_DATAPAGEBASE_COMPUTEDHEARTRATE_BYTE] = heartRate;
}
