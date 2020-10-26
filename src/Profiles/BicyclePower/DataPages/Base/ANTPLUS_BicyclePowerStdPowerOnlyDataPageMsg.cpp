#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerStdPowerOnlyDataPageMsg.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerPrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

BicyclePowerStdPowerOnlyDataPageMsg::BicyclePowerStdPowerOnlyDataPageMsg() : BaseDataPageMsg<BroadcastDataMsg>() {
    setDataBuffer(_buffer);
    _buffer[ANTPLUS_DEFAULT_DATAPAGE_BYTE] = ANTPLUS_BICYCLEPOWER_DATAPAGE_STD_POWERONLY_MAIN_DATAPAGE_NUMBER;
    _buffer[ANTPLUS_BICYCLEPOWER_DATAPAGE_STD_POWERONLY_MAIN_PEDAL_POWER_BYTE] = 0xFF;
    _buffer[ANTPLUS_BICYCLEPOWER_DATAPAGE_STD_POWERONLY_MAIN_INSTANTANEOUS_CADENCE_BYTE] = 0xFF;
}

void BicyclePowerStdPowerOnlyDataPageMsg::setUpdateEventCount(uint8_t eventCount) {
    _buffer[ANTPLUS_BICYCLEPOWER_DATAPAGE_STD_POWERONLY_MAIN_UPDATE_EVENT_COUNT_BYTE] = eventCount;
}

void BicyclePowerStdPowerOnlyDataPageMsg::setCumulativePowerCount(uint16_t accPower) {
    _buffer[ANTPLUS_BICYCLEPOWER_DATAPAGE_STD_POWERONLY_MAIN_CUMULATIVEPOWERMSB_BYTE] = accPower >> 8;
    _buffer[ANTPLUS_BICYCLEPOWER_DATAPAGE_STD_POWERONLY_MAIN_CUMULATIVEPOWERLSB_BYTE] = accPower & ANTPLUS_DEFAULT_BYTE_MASK;
}

void BicyclePowerStdPowerOnlyDataPageMsg::setInstataneousPowerCount(uint16_t power) {
    _buffer[ANTPLUS_BICYCLEPOWER_DATAPAGE_STD_POWERONLY_MAIN_INSTANTANEOUSPOWERMSB_BYTE] = power >> 8;
    _buffer[ANTPLUS_BICYCLEPOWER_DATAPAGE_STD_POWERONLY_MAIN_INSTANTANEOUSPOWERLSB_BYTE] = power & ANTPLUS_DEFAULT_BYTE_MASK;
}
