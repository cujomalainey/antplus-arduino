#include <Profiles/Lev/DataPages/RX/ANTPLUS_LevBatteryInfo.h>
#include <Profiles/Lev/ANTPLUS_LevPrivateDefines.h>

LevBatteryInfo::LevBatteryInfo(AntRxDataResponse& dp) : LevBaseMainDataPage(dp) {
    return;
}

uint16_t LevBatteryInfo::getChargingCycleCount()
{
    return (uint16_t)getData(2) + (((uint16_t)getData(3) & 0x0F) << 8);
}

uint16_t LevBatteryInfo::getFuelConsumption()
{
    uint16_t c = (uint16_t)getData(3) + (((uint16_t)getData(4) & 0x0F) << 8);
    return c >> 4;
}

uint8_t LevBatteryInfo::getBatteryVoltage()
{
    return getData(5);
}

uint16_t LevBatteryInfo::getDistanceOnCurrentCharge()
{
    return (uint16_t)getData(6) + (((uint16_t)getData(7) & 0x0F) << 8);
}
