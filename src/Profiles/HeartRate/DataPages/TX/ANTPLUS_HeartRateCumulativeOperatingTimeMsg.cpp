#include <Profiles/HeartRate/DataPages/TX/ANTPLUS_HeartRateCumulativeOperatingTimeMsg.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

HeartRateCumulativeOperatingTimeMsg::HeartRateCumulativeOperatingTimeMsg() : HeartRateBaseMainDataPageMsg(ANTPLUS_HEARTRATE_DATAPAGE_CUMULATIVEOPERATINGTIME_NUMBER), HeartRateBaseCumulativeOperatingTime<BroadcastDataMsg>() {
}

void HeartRateCumulativeOperatingTimeMsg::setCumulativeOperatingTime(uint32_t time) {
    set24BitValue(time,
            ANTPLUS_HEARTRATE_DATAPAGE_CUMULATIVEOPERATINGTIME_TIME_LSB_BYTE,
            ANTPLUS_HEARTRATE_DATAPAGE_CUMULATIVEOPERATINGTIME_TIME_MSB_BYTE);
}
