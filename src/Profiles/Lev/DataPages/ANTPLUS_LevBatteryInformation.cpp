#include <Profiles/Lev/DataPages/ANTPLUS_LevBatteryInformation.h>
#include <Profiles/Lev/ANTPLUS_LevDefines.h>

#define RESERVED_BYTE                      1
#define RESERVED_VALUE                     0xFF
#define CHARGINGCYCLECOUNT_LSB_BYTE        2
#define CHARGINGCYCLECOUNT_MSB_BYTE        3
#define CHARGINGCYCLECOUNT_MASK            0x0FFF
#define FUELCONSUMPTION_LSB_BYTE           4
#define FUELCONSUMPTION_MSN_BYTE           3
#define FUELCONSUMPTION_MSN_MASK           0xF0
#define FUELCONSUMPTION_MSN_SHIFT          4
#define BATTERYVOLTAGE_BYTE                5
#define DISTANCEONCURRENTCHARGE_LSB_BYTE   6
#define DISTANCEONCURRENTCHARGE_MSB_BYTE   7

template<class T>
LevBaseBatteryInformation<T>::LevBaseBatteryInformation() : CoreDataPage<T>() {}

template<class T>
uint16_t LevBaseBatteryInformation<T>::getChargingCycleCount() {
    return this->get16BitValue(CHARGINGCYCLECOUNT_LSB_BYTE,
            CHARGINGCYCLECOUNT_MSB_BYTE, CHARGINGCYCLECOUNT_MASK);
}

// NOTE this a bit inverted field which results in the non-sense below
template<class T>
uint16_t LevBaseBatteryInformation<T>::getFuelConsumption() {
    return this->get8BitValue(FUELCONSUMPTION_LSB_BYTE) |
        (((uint16_t)this->get8BitValue(FUELCONSUMPTION_MSN_BYTE,
                            FUELCONSUMPTION_MSN_MASK,
                            FUELCONSUMPTION_MSN_SHIFT)) << BITS_IN_BYTE);
}

template<class T>
uint8_t LevBaseBatteryInformation<T>::getBatteryVoltage() {
    return this->get8BitValue(BATTERYVOLTAGE_BYTE);
}

template<class T>
uint16_t LevBaseBatteryInformation<T>::getDistanceOnCurrentCharge() {
    return this->get16BitValue(DISTANCEONCURRENTCHARGE_LSB_BYTE,
            DISTANCEONCURRENTCHARGE_MSB_BYTE);
}

template class LevBaseBatteryInformation<BroadcastData>;
template class LevBaseBatteryInformation<BroadcastDataMsg>;

LevBatteryInformation::LevBatteryInformation(AntRxDataResponse& dp) :
    LevBaseMainDataPage(dp),
    LevBaseBatteryInformation<BroadcastData>() {}

LevBatteryInformationMsg::LevBatteryInformationMsg() :
    LevBaseMainDataPageMsg<BroadcastDataMsg>(ANTPLUS_LEV_DATAPAGE_BATTERYINFORMATION_NUMBER),
    LevBaseBatteryInformation<BroadcastDataMsg>() {
    set8BitValue(RESERVED_VALUE, RESERVED_BYTE);
}

void LevBatteryInformationMsg::setChargingCycleCount(uint16_t cycleCount) {
    set16BitValue(cycleCount, CHARGINGCYCLECOUNT_LSB_BYTE,
            CHARGINGCYCLECOUNT_MSB_BYTE,
            CHARGINGCYCLECOUNT_MASK);
}

// NOTE this a bit inverted field which results in the non-sense below
void LevBatteryInformationMsg::setFuelConsumption(uint16_t consumption) {
    set8BitValue(consumption & 0xFF, FUELCONSUMPTION_LSB_BYTE);
    set8BitValue(consumption >> BITS_IN_BYTE, FUELCONSUMPTION_MSN_BYTE,
            FUELCONSUMPTION_MSN_MASK,
            FUELCONSUMPTION_MSN_SHIFT);
}

void LevBatteryInformationMsg::setBatteryVoltage(uint8_t voltage) {
    set8BitValue(voltage, BATTERYVOLTAGE_BYTE);
}

void LevBatteryInformationMsg::setDistanceOnCurrentCharge(uint16_t distance) {
    set16BitValue(distance, DISTANCEONCURRENTCHARGE_LSB_BYTE,
            DISTANCEONCURRENTCHARGE_MSB_BYTE);
}
