#include <Profiles/Lev/DataPages/RX/ANTPLUS_LevBatteryInfo.h>
#include <Profiles/Lev/ANTPLUS_LevPrivateDefines.h>

LevBatteryInformation::LevBatteryInformation(AntRxDataResponse& dp) : LevBaseMainDataPage(dp) {
    return;
}

uint16_t LevBatteryInformation::getChargingCycleCount() {
    return (uint16_t)getData(2) + (((uint16_t)getData(3) & 0x0F) << 8); // TODO test
}

uint16_t LevBatteryInformation::getFuelConsumption() {
    return ((getData(3) & 0xF0) << 4) + getData(4);  // TODO test
}

uint8_t LevBatteryInformation::getBatteryVoltage() {
    return getData(5);
}

uint16_t LevBatteryInformation::getDistanceOnCurrentCharge() {
    return getData(6) + (getData(7) << 8); // TODO test
}
