/***********************************
 * AntPlus Bicycle Power Sensor example
 *
 * Creates a Bike Power Sensor, in
 * Crank Torque mode and transmits
 * openly with mocked data
 *
 * Example built for external radio
 *
 * Author Curtis Malainey
 ************************************/
#include <Arduino.h>
#include "ANT.h"
#include "ANTPLUS.h"

#define BAUD_RATE 9600
#define CHANNEL_0 0
#define antSerial Serial2

const uint8_t NETWORK_KEY[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77}; // get this from thisisant.com

// *************************************
// Specific to test ANT+ chip and ESP32 setup
const int RTS_PIN = 23;
const int SUSPEND_PIN = 22;
const int SLEEP_PIN = 19;
const int RESET_PIN = 2;

// *************************************

ArduinoSerialAntWithCallbacks ant;
AntPlusRouter router;
ProfileBicyclePowerSensor bikePower(123, 0, ANTPLUS_BICYCLEPOWER_FLAGS_SENSORTYPE_TORQUECRANK);

void batteryStatusDataPageHandler(BatteryStatusMsg& msg, uintptr_t data);
void manufacturerIDDataPageHandler(ManufacturersInformationMsg& msg, uintptr_t data);
void productIDDataPageHandler(ProductInformationMsg& msg, uintptr_t data);
void powerOnlyDataPageHandler(BicyclePowerStandardPowerOnlyMsg& msg, uintptr_t data);
void crankTorqueDataPageHandler(BicyclePowerStandardCrankTorqueMsg& msg, uintptr_t data);
void wheelTorqueDataPageHandler(BicyclePowerStandardWheelTorqueMsg& msg, uintptr_t data);
void pedalSmoothnessDataPageHandler(BicyclePowerTorqueEffectivenessAndPedalSmoothnessMsg& msg, uintptr_t data);

void setup() {

    // Powering on the ANT+ chip
    // *************************************

    pinMode(SUSPEND_PIN, OUTPUT);
    pinMode(SLEEP_PIN, OUTPUT);
    pinMode(RESET_PIN, OUTPUT);
    pinMode(RTS_PIN, INPUT);

    digitalWrite(RESET_PIN, HIGH);
    digitalWrite(SUSPEND_PIN, HIGH);
    digitalWrite(SLEEP_PIN, LOW);


    // *************************************

    antSerial.begin(BAUD_RATE);
    ant.setSerial(antSerial);
    delay(5000);

    router.setDriver(&ant); // never touch ant again
    router.setAntPlusNetworkKey(NETWORK_KEY);
    router.setProfile(CHANNEL_0, &bikePower);
    // Delay after initial setup to wait for user to connect on serial

    Serial.begin(BAUD_RATE);
    Serial.println("Running");
    /// bikePower.createBatteryStatusMsg(batteryStatusDataPageHandler);
    bikePower.createManufacturersInformationMsg(manufacturerIDDataPageHandler);
    bikePower.createProductInformationMsg(productIDDataPageHandler);
    bikePower.createBicyclePowerStandardPowerOnlyMsg(powerOnlyDataPageHandler);
    bikePower.createBicyclePowerStandardCrankTorqueMsg(crankTorqueDataPageHandler);
    // bikePower.createBicyclePowerTorqueEffectivenessAndPedalSmoothnessMsg(pedalSmoothnessDataPageHandler);
    Serial.println("===========================");
    bikePower.begin();
}

void loop() {
    // call this frequently
    router.loop();
}

void printDpMsg(int dp, const char* s) {
    Serial.print("Sending DataPage: ");
    Serial.print(dp);
    Serial.print(" - ");
    Serial.println(s);
}

/* Optional */
// void batteryStatusDataPageHandler(BatteryStatusMsg& msg, uintptr_t data) {
//    printDpMsg(82, "Battery Status");
// }

void manufacturerIDDataPageHandler(ManufacturersInformationMsg& msg, uintptr_t data) {
    printDpMsg(80, "Manufacturers Information");
    msg.setHWRevision(1);
    msg.setManufacturerId(456);
    msg.setModelNumber(789);
}

void productIDDataPageHandler(ProductInformationMsg& msg, uintptr_t data) {
    printDpMsg(81, "Product Information");
    msg.setSWRevisionSupplemental(12);
    msg.setSWRevisionMain(34);
    msg.setSerialNumber(0xDEADBEEF);
}

void powerOnlyDataPageHandler(BicyclePowerStandardPowerOnlyMsg& msg, uintptr_t data) {
    static uint8_t eventCount = 0;

    printDpMsg(16, "Power Only");
    msg.setUpdateEventCount(eventCount++);
    msg.setAccumulatedPower(eventCount * 3);
    msg.setInstantaneousPower(eventCount * 2);
    msg.setPedalPower(eventCount % 101);
    msg.setPedalDifferentiation(eventCount / 3);
    msg.setInstantaneousCadence(eventCount);
}

void crankTorqueDataPageHandler(BicyclePowerStandardCrankTorqueMsg& msg, uintptr_t data) {
    static uint8_t ticks = 0;

    printDpMsg(18, "Crank Torque");
    msg.setCrankTicks(ticks++);
    msg.setInstantaneousCadence(ticks / 2);
    msg.setCrankPeriod(ticks * 2);
    msg.setAccumulatedTorque(ticks * 3);
}

/* Optional */
// void pedalSmoothnessDataPageHandler(BicyclePowerTorqueEffectivenessAndPedalSmoothnessMsg& msg, uintptr_t data) {
//    printDpMsg(19, "Torque Effectiveness and Pedal Smoothness");
// }
