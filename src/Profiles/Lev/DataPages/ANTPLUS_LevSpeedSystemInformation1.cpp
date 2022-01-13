#include <Profiles/Lev/DataPages/ANTPLUS_LevSpeedSystemInformation1.h>
#include <Profiles/Lev/ANTPLUS_LevPrivateDefines.h>

#define TEMPERATURESTATE_BYTE                          1
#define TEMPERATURESTATE_BATTERYTEMPERATURE_MASK       0x7
#define TEMPERATURESTATE_BATTERYTEMPERATUREALERT_SHIFT 3
#define TEMPERATURESTATE_BATTERYTEMPERATUREALERT_MASK  0x8
#define TEMPERATURESTATE_MOTORTEMPERATURE_SHIFT        4
#define TEMPERATURESTATE_MOTORTEMPERATURE_MASK         0x70
#define TEMPERATURESTATE_MOTORTEMPERATUREALERT_SHIFT   7
#define TEMPERATURESTATE_MOTORTEMPERATUREALERT_MASK    0x80
#define ERRORMESSAGE_BYTE                              5

LevSpeedSystemInformation1::LevSpeedSystemInformation1(AntRxDataResponse& dp) :
    LevBaseSpeedSystemInformation(dp) {}

uint8_t LevSpeedSystemInformation1::getBatteryTemperatureState() {
    return this->get8BitValue(TEMPERATURESTATE_BYTE,
            TEMPERATURESTATE_BATTERYTEMPERATURE_MASK);
}

uint8_t LevSpeedSystemInformation1::getBatteryTemperatureAlert() {
    return this->get8BitValue(TEMPERATURESTATE_BYTE,
            TEMPERATURESTATE_BATTERYTEMPERATUREALERT_MASK,
            TEMPERATURESTATE_BATTERYTEMPERATUREALERT_SHIFT);
}

uint8_t LevSpeedSystemInformation1::getMotorTemperatureState() {
    return this->get8BitValue(TEMPERATURESTATE_BYTE,
            TEMPERATURESTATE_MOTORTEMPERATURE_MASK,
            TEMPERATURESTATE_MOTORTEMPERATURE_SHIFT);
}

uint8_t LevSpeedSystemInformation1::getMotorTemperatureAlert() {
    return this->get8BitValue(TEMPERATURESTATE_BYTE,
            TEMPERATURESTATE_MOTORTEMPERATUREALERT_MASK,
            TEMPERATURESTATE_MOTORTEMPERATUREALERT_SHIFT);
}


uint8_t LevSpeedSystemInformation1::getErrorMessage() {
    return this->get8BitValue(ERRORMESSAGE_BYTE);
}

