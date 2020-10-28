#include <Profiles/BicyclePower/DataPages/TX/ANTPLUS_BicyclePowerStandardPowerOnlyMsg.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerPrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

BicyclePowerStandardPowerOnlyMsg::BicyclePowerStandardPowerOnlyMsg() : BaseDataPageMsg<BroadcastDataMsg>() {
    setDataBuffer(_buffer);
    _buffer[ANTPLUS_DEFAULT_DATAPAGE_BYTE] = ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_NUMBER;
    _buffer[ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_PEDALPOWER_BYTE] = 0xFF;
    _buffer[ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_INSTANTANEOUSCADENCE_BYTE] = 0xFF;
}

void BicyclePowerStandardPowerOnlyMsg::setUpdateEventCount(uint8_t eventCount) {
    _buffer[ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_UPDATEEVENTCOUNT_BYTE] = eventCount;
}

void BicyclePowerStandardPowerOnlyMsg::setCumulativePowerCount(uint16_t accPower) {
    _buffer[ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_ACCUMULATEDPOWERMSB_BYTE] = accPower >> 8;
    _buffer[ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_ACCUMULATEDPOWERLSB_BYTE] = accPower & ANTPLUS_DEFAULT_BYTE_MASK;
}

void BicyclePowerStandardPowerOnlyMsg::setInstataneousPowerCount(uint16_t power) {
    _buffer[ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_INSTANTANEOUSPOWERMSB_BYTE] = power >> 8;
    _buffer[ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_INSTANTANEOUSPOWERLSB_BYTE] = power & ANTPLUS_DEFAULT_BYTE_MASK;
}
