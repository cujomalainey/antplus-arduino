#include <Profiles/HeartRate/DataPages/ANTPLUS_HeartRateDefault.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

#define RESERVED_LSB_BYTE 1
#define RESERVED_MSB_BYTE 3
#define RESERVED_VALUE 0xFFFFFF

HeartRateDefault::HeartRateDefault(AntRxDataResponse& dp) :
    HeartRateBaseMainDataPage(dp) {}

HeartRateDefaultMsg::HeartRateDefaultMsg() :
    HeartRateBaseMainDataPageMsg(HEARTRATE_DEFAULT_NUMBER) {
    set24BitValue(RESERVED_VALUE, RESERVED_LSB_BYTE, RESERVED_MSB_BYTE);
}
