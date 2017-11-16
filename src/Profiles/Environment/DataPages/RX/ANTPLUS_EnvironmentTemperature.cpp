#include <Profiles/Environment/DataPages/RX/ANTPLUS_EnvironmentTemperature.h>

EnvironmentTemperature::EnvironmentTemperature(AntRxDataResponse& dp) : EnvironmentBaseDataPage(dp) {
}

uint8_t EnvironmentTemperature::getEventCount() {
    // TODO
}

uint16_t EnvironmentTemperature::get24HourLow() {
    // TODO
}

uint16_t EnvironmentTemperature::get24HourHigh() {
    // TODO
}

uint16_t EnvironmentTemperature::getCurrentTemp() {
    // TODO
}
