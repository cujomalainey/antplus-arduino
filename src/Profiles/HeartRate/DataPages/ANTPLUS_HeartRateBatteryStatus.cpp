#include <Profiles/HeartRate/DataPages/ANTPLUS_HeartRateBatteryStatus.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

#define BATTERYLEVEL_BYTE 1
#define FRACTIONALBATTERYVOLTAGE_BYTE 2
#define COARSEBATTERYVOLTAGE_BYTE 3
#define BATTERYSTATUS_BYTE 3
#define COARSEBATTERYVOLTAGE_MASK 0x0F
#define BATTERYSTATUS_MASK 0x70
#define BATTERYSTATUS_SHIFT 4

template<class T>
HeartRateBaseBatteryStatus<T>::HeartRateBaseBatteryStatus() :
    CoreDataPage<T>() {}

template<class T>
uint8_t HeartRateBaseBatteryStatus<T>::getBatteryLevel() {
    return this->get8BitValue(BATTERYLEVEL_BYTE);
}

template<class T>
uint8_t HeartRateBaseBatteryStatus<T>::getFractionalBatteryVoltage() {
    return this->get8BitValue(FRACTIONALBATTERYVOLTAGE_BYTE);
}

template<class T>
uint8_t HeartRateBaseBatteryStatus<T>::getCoarseBatteryVoltage() {
    return this->get8BitValue(
            COARSEBATTERYVOLTAGE_BYTE, COARSEBATTERYVOLTAGE_MASK);
}

template<class T>
uint8_t HeartRateBaseBatteryStatus<T>::getBatteryStatus() {
    return this->get8BitValue(
            BATTERYSTATUS_BYTE, BATTERYSTATUS_MASK, BATTERYSTATUS_SHIFT);
}

template class HeartRateBaseBatteryStatus<BroadcastData>;
template class HeartRateBaseBatteryStatus<BroadcastDataMsg>;

HeartRateBatteryStatus::HeartRateBatteryStatus(AntRxDataResponse& dp) :
    HeartRateBaseMainDataPage(dp),
    HeartRateBaseBatteryStatus() {}

HeartRateBatteryStatusMsg::HeartRateBatteryStatusMsg() :
    HeartRateBaseMainDataPageMsg(BATTERYSTATUS_NUMBER),
    HeartRateBaseBatteryStatus<BroadcastDataMsg>() {
}

void HeartRateBatteryStatusMsg::setBatteryLevel(uint8_t level) {
    set8BitValue(level, BATTERYLEVEL_BYTE);
}

void HeartRateBatteryStatusMsg::setFractionalBatteryVoltage(uint8_t voltage) {
    set8BitValue(voltage, FRACTIONALBATTERYVOLTAGE_BYTE);
}

void HeartRateBatteryStatusMsg::setCoarseBatteryVolage(uint8_t voltage) {
    set8BitValue(voltage, COARSEBATTERYVOLTAGE_BYTE, COARSEBATTERYVOLTAGE_MASK);
}

void HeartRateBatteryStatusMsg::setBatteryStatus(uint8_t status) {
    set8BitValue(status,
            BATTERYSTATUS_BYTE, BATTERYSTATUS_MASK, BATTERYSTATUS_SHIFT);
}
