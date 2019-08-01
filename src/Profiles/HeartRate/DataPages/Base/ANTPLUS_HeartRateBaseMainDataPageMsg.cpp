#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPageMsg.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

HeartRateBaseMainDataPageMsg::HeartRateBaseMainDataPageMsg(uint8_t dataPageNumber) : BaseDataPageMsg<BroadcastDataMsg>(), HeartRateCoreMainDataPage<BroadcastDataMsg>() {
    setDataBuffer(_buffer);
    _buffer[ANTPLUS_DEFAULT_DATAPAGE_BYTE] = dataPageNumber;
}

void HeartRateBaseMainDataPageMsg::setPageChangeToggle(uint8_t toggle) {
    set8BitValue(toggle ? 1 : 0,
            ANTPLUS_HEARTRATE_DATAPAGEBASE_TOGGLE_BYTE,
            ANTPLUS_HEARTRATE_DATAPAGEBASE_TOGGLE_MASK,
            ANTPLUS_HEARTRATE_DATAPAGEBASE_TOGGLE_SHIFT);
}

void HeartRateBaseMainDataPageMsg::setHeartBeatEventTime(uint16_t time) {
    set16BitValue(time,
            ANTPLUS_HEARTRATE_DATAPAGEBASE_HEARTBEATEVENTTIMELSB_BYTE,
            ANTPLUS_HEARTRATE_DATAPAGEBASE_HEARTBEATEVENTTIMEMSB_BYTE);
}

void HeartRateBaseMainDataPageMsg::setHeartBeatCount(uint8_t count) {
    set8BitValue(count,
            ANTPLUS_HEARTRATE_DATAPAGEBASE_HEARTBEATCOUNT_BYTE);
}

void HeartRateBaseMainDataPageMsg::setComputedHeartRate(uint8_t heartRate) {
    set8BitValue(heartRate,
            ANTPLUS_HEARTRATE_DATAPAGEBASE_COMPUTEDHEARTRATE_BYTE);
}
