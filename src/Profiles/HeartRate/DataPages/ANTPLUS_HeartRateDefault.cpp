#include <Profiles/HeartRate/DataPages/ANTPLUS_HeartRateDefault.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

HeartRateDefault::HeartRateDefault(AntRxDataResponse& dp) :
    HeartRateBaseMainDataPage(dp) {}

HeartRateDefaultMsg::HeartRateDefaultMsg() :
    HeartRateBaseMainDataPageMsg(HEARTRATE_DEFAULT_NUMBER) {
    // TODO magic numbers
    _buffer[1] = 0xFF;
    _buffer[2] = 0xFF;
    _buffer[3] = 0xFF;
}
