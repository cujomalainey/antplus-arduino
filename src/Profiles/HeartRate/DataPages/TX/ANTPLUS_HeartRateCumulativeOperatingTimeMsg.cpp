#include <Profiles/HeartRate/DataPages/TX/ANTPLUS_HeartRateCumulativeOperatingTimeMsg.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

HeartRateCumulativeOperatingTimeMsg::HeartRateCumulativeOperatingTimeMsg() : HeartRateBaseMainDataPageMsg(ANTPLUS_HEARTRATE_DATAPAGE_CUMULATIVEOPERATINGTIME_NUMBER) {

}

uint32_t HeartRateCumulativeOperatingTimeMsg::getCumulativeOperatingTime() {
    // TODO
}

void HeartRateCumulativeOperatingTimeMsg::setCumulativeOperatingTime(uint32_t time) {
    // TODO
}
