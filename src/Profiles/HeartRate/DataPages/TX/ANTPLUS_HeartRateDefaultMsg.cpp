#include <Profiles/HeartRate/DataPages/TX/ANTPLUS_HeartRateDefaultMsg.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

HeartRateDefaultMsg::HeartRateDefaultMsg() : HeartRateBaseMainDataPageMsg(ANTPLUS_HEARTRATE_DATAPAGE_DEFAULT_NUMBER) {
    // TODO magic numbers
    _buffer[1] = 0xFF;
    _buffer[2] = 0xFF;
    _buffer[3] = 0xFF;
}
