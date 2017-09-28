#include <Profiles/HeartRate/DataPages/TX/ANTPLUS_HeartRateBatteryStatusMsg.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

HeartRateBatteryStatusMsg::HeartRateBatteryStatusMsg() : HeartRateBaseMainDataPageMsg(ANTPLUS_HEARTRATE_DATAPAGE_BATTERYSTATUS_NUMBER) {

}

uint8_t HeartRateBatteryStatusMsg::getBatteryLevel() {
    // TODO
}

uint8_t HeartRateBatteryStatusMsg::getFractionalBatteryVoltage() {
    // TODO
}

uint8_t HeartRateBatteryStatusMsg::getCoarseBatteryVolage() {
    // TODO
}

uint8_t HeartRateBatteryStatusMsg::getBatteryStatus() {
    // TODO
}

void HeartRateBatteryStatusMsg::setBatteryLevel(uint8_t level) {
    // TODO
}

void HeartRateBatteryStatusMsg::setFractionalBatteryVoltage(uint8_t voltage) {
    // TODO
}

void HeartRateBatteryStatusMsg::setCoarseBatteryVolage(uint8_t voltage) {
    // TODO
}

void HeartRateBatteryStatusMsg::setBatteryStatus(uint8_t status) {
    // TODO
}
