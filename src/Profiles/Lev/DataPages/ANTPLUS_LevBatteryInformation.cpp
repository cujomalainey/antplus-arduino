#include <Profiles/Lev/DataPages/ANTPLUS_LevBatteryInformation.h>
#include <Profiles/Lev/ANTPLUS_LevPrivateDefines.h>

#define CHARGINGCYCLECOUNT_LSB_BYTE        2
#define CHARGINGCYCLECOUNT_MSB_BYTE        3
#define CHARGINGCYCLECOUNT_MASK            0x0FFF
#define FUELCONSUMPTION_LSB_BYTE           4
#define FUELCONSUMPTION_MSB_BYTE           3
#define FUELCONSUMPTION_MASK               0xF0
#define FUELCONSUMPTION_SHIFT              4
#define BATTERYVOLTAGE_BYTE                5
#define DISTANCEONCURRENTCHARGE_LSB_BYTE   6
#define DISTANCEONCURRENTCHARGE_MSB_BYTE   7

LevBatteryInformation::LevBatteryInformation(AntRxDataResponse& dp) :
    LevBaseMainDataPage(dp) {}

uint16_t LevBatteryInformation::getChargingCycleCount() {
    return this->get16BitValue(CHARGINGCYCLECOUNT_LSB_BYTE,
            CHARGINGCYCLECOUNT_MSB_BYTE, CHARGINGCYCLECOUNT_MASK);
}

// TODO check this in testing
uint16_t LevBatteryInformation::getFuelConsumption() {
    return this->get16BitValue(FUELCONSUMPTION_LSB_BYTE,
            FUELCONSUMPTION_MSB_BYTE, FUELCONSUMPTION_MASK,
            FUELCONSUMPTION_SHIFT);
}

uint8_t LevBatteryInformation::getBatteryVoltage() {
    return this->get8BitValue(BATTERYVOLTAGE_BYTE);
}

uint16_t LevBatteryInformation::getDistanceOnCurrentCharge() {
    return this->get16BitValue(DISTANCEONCURRENTCHARGE_LSB_BYTE,
            DISTANCEONCURRENTCHARGE_MSB_BYTE);
}
