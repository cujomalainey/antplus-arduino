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

template<class T>
LevBaseSpeedSystemInformation1<T>::LevBaseSpeedSystemInformation1() :
    CoreDataPage<T>() {}

template<class T>
uint8_t LevBaseSpeedSystemInformation1<T>::getBatteryTemperatureState() {
    return this->get8BitValue(TEMPERATURESTATE_BYTE,
            TEMPERATURESTATE_BATTERYTEMPERATURE_MASK);
}

template<class T>
uint8_t LevBaseSpeedSystemInformation1<T>::getBatteryTemperatureAlert() {
    return this->get8BitValue(TEMPERATURESTATE_BYTE,
            TEMPERATURESTATE_BATTERYTEMPERATUREALERT_MASK,
            TEMPERATURESTATE_BATTERYTEMPERATUREALERT_SHIFT);
}

template<class T>
uint8_t LevBaseSpeedSystemInformation1<T>::getMotorTemperatureState() {
    return this->get8BitValue(TEMPERATURESTATE_BYTE,
            TEMPERATURESTATE_MOTORTEMPERATURE_MASK,
            TEMPERATURESTATE_MOTORTEMPERATURE_SHIFT);
}

template<class T>
uint8_t LevBaseSpeedSystemInformation1<T>::getMotorTemperatureAlert() {
    return this->get8BitValue(TEMPERATURESTATE_BYTE,
            TEMPERATURESTATE_MOTORTEMPERATUREALERT_MASK,
            TEMPERATURESTATE_MOTORTEMPERATUREALERT_SHIFT);
}

template<class T>
uint8_t LevBaseSpeedSystemInformation1<T>::getErrorMessage() {
    return this->get8BitValue(ERRORMESSAGE_BYTE);
}

template class LevBaseSpeedSystemInformation1<BroadcastData>;
template class LevBaseSpeedSystemInformation1<BroadcastDataMsg>;

LevSpeedSystemInformation1::LevSpeedSystemInformation1(AntRxDataResponse& dp) :
    LevBaseSpeedSystemInformation(dp),
    LevBaseSpeedSystemInformation1<BroadcastData>() {
}

LevSpeedSystemInformation1Msg::LevSpeedSystemInformation1Msg() :
    LevBaseSpeedSystemInformationMsg(SPEEDSYSTEMINFORMATION1_NUMBER),
    LevBaseSpeedSystemInformation1<BroadcastDataMsg>() {}

void LevSpeedSystemInformation1Msg::setBatteryTemperatureState(uint8_t state) {
    set8BitValue(state, TEMPERATURESTATE_BYTE,
            TEMPERATURESTATE_BATTERYTEMPERATURE_MASK);
}

void LevSpeedSystemInformation1Msg::setBatteryTemperatureAlert(uint8_t alert) {
    set8BitValue(alert, TEMPERATURESTATE_BYTE,
            TEMPERATURESTATE_BATTERYTEMPERATUREALERT_MASK,
            TEMPERATURESTATE_BATTERYTEMPERATUREALERT_SHIFT);
}

void LevSpeedSystemInformation1Msg::setMotorTemperatureState(uint8_t state) {
    set8BitValue(state, TEMPERATURESTATE_BYTE,
            TEMPERATURESTATE_MOTORTEMPERATURE_MASK,
            TEMPERATURESTATE_MOTORTEMPERATURE_SHIFT);
}

void LevSpeedSystemInformation1Msg::setMotorTemperatureAlert(uint8_t alert) {
    set8BitValue(alert, TEMPERATURESTATE_BYTE,
            TEMPERATURESTATE_MOTORTEMPERATUREALERT_MASK,
            TEMPERATURESTATE_MOTORTEMPERATUREALERT_SHIFT);
}

void LevSpeedSystemInformation1Msg::setErrorMessage(uint8_t err) {
    set8BitValue(err, ERRORMESSAGE_BYTE);
}

