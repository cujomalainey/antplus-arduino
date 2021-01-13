/***********************************
 * AntPlus Bicycle Power Display example
 *
 * Finds a nearby Bike Power Sensor, pairs
 * to it and then reads the information
 * out via the serial port.
 *
 * Example built for ESP32
 * Note: HardwareSerial required for this controller
 *
 * Author Andrew Hillier
*         based on the work of Curtis Malainey
 ************************************/
#include <Arduino.h>
#include "ANT.h"
#include "ANTPLUS.h"
#include <HardwareSerial.h>

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
ProfileBicyclePowerDisplay bikePower;

void bicyclePowerBaseDataPageHandler(AntRxDataResponse& msg, uintptr_t data);
void batteryStatusDataPageHandler(BatteryStatus& msg, uintptr_t data);
void manufacturerIDDataPageHandler(ManufacturersInformation& msg, uintptr_t data);
void productIDDataPageHandler(BicyclePowerProductID& msg, uintptr_t data);
void powerOnlyDataPageHandler(BicyclePowerStandardPowerOnly& msg, uintptr_t data);
void crankTorqueDataPageHandler(BicyclePowerStandardCrankTorque& msg, uintptr_t data);
void wheelTorqueDataPageHandler(BicyclePowerStandardWheelTorque& msg, uintptr_t data);
void pedalSmoothnessDataPageHandler(BicyclePowerTorqueEffectivenessAndPedalSmoothness& msg, uintptr_t data);

void bicyclePowerBatteryStatus(uint8_t flags);
void printStatus(uint8_t status);

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
    delay(15000);

    router.setDriver(&ant); // never touch ant again
    router.setAntPlusNetworkKey(NETWORK_KEY);
    router.setProfile(CHANNEL_0, &bikePower);
    // Delay after initial setup to wait for user to connect on serial

    Serial.begin(BAUD_RATE);
    Serial.println("Running");
    bikePower.onDataPage(bicyclePowerBaseDataPageHandler);
    bikePower.onBatteryStatus(batteryStatusDataPageHandler);
    bikePower.onManufacturersInformation(manufacturerIDDataPageHandler);
    bikePower.onBicyclePowerProductID(productIDDataPageHandler);
    bikePower.onBicyclePowerStandardPowerOnly(powerOnlyDataPageHandler);
    bikePower.onBicyclePowerStandardCrankTorque(crankTorqueDataPageHandler);
    bikePower.onBicyclePowerStandardWheelTorque(wheelTorqueDataPageHandler);
    bikePower.onBicyclePowerTorqueEffectivenessAndPedalSmoothness(pedalSmoothnessDataPageHandler);
    bikePower.begin();
    // wait for pair to complete
    uint8_t status = bikePower.waitForPair();
    // print channel status
    Serial.println("===========================");
    printStatus(status);
    Serial.print("Device Number: ");
    Serial.println(bikePower.getDeviceNumber());
    Serial.print("Transmisison Type: ");
    Serial.println(bikePower.getTransmissionType());
}

void loop() {
    router.loop();
}

void batteryStatusDataPageHandler(BatteryStatus& msg, uintptr_t data) {
    Serial.print("Fractional Battery Voltage: ");
    Serial.println(msg.getFractionalBatteryVoltage());
    Serial.print("Battery Status: ");
    bicyclePowerBatteryStatus(msg.getBatteryStatus());
}

void manufacturerIDDataPageHandler(ManufacturersInformation& msg, uintptr_t data) {
    Serial.print("Hardware ID: ");
    Serial.println(msg.getHWRevision());
    Serial.print("Manufacturer ID: ");
    Serial.println(msg.getManufacturerID());
    Serial.print("Model Number: ");
    Serial.println(msg.getModelNumber());
}

void productIDDataPageHandler(BicyclePowerProductID& msg, uintptr_t data) {
    Serial.print("Software Version Supplemental: ");
    Serial.println(msg.getSoftwareVersionSupplemental());
    Serial.print("Software Version: ");
    Serial.println(msg.getSoftwareVersion());
    Serial.print("Serial Number: ");
    Serial.println(msg.getSerialNumber());
}

void bicyclePowerBaseDataPageHandler(AntRxDataResponse& msg, uintptr_t data) {
    BicyclePowerBaseMainDataPage dp = BicyclePowerBaseMainDataPage(msg);
    Serial.println("===========================");
    Serial.print("DataPage: ");
    Serial.println(dp.getDataPageNumber());
    Serial.print("Bike Power Event Count: ");
    Serial.println(dp.getUpdateEventCount());
}

void powerOnlyDataPageHandler(BicyclePowerStandardPowerOnly& msg, uintptr_t data) {
    Serial.print("Pedal Balance: ");
    Serial.println(msg.getPedalPower());
    Serial.print("Instant Cadence: ");
    Serial.println(msg.getInstantaneousCadence());
    Serial.print("Accumulated Power: ");
    Serial.println(msg.getAccumulatedPower());
    Serial.print("Instant Power: ");
    Serial.println(msg.getInstantaneousPower());
}

void crankTorqueDataPageHandler(BicyclePowerStandardCrankTorque& msg, uintptr_t data) {
    Serial.print("Crank Ticks: ");
    Serial.println(msg.getCrankTicks());
    Serial.print("Instant Cadence: ");
    Serial.println(msg.getInstantCadence());
    Serial.print("Crank Period: ");
    Serial.println(msg.getCrankPeriod());
    Serial.print("Accumulated Torque: ");
    Serial.println(msg.getAccumulatedTorque());
}

void wheelTorqueDataPageHandler(BicyclePowerStandardWheelTorque& msg, uintptr_t data) {
    Serial.print("Wheel Ticks: ");
    Serial.println(msg.getWheelTicks());
    Serial.print("Instant Cadence: ");
    Serial.println(msg.getInstantCadence());
    Serial.print("Wheel Period: ");
    Serial.println(msg.getWheelPeriod());
    Serial.print("Accumulated Torque: ");
    Serial.println(msg.getAccumulatedTorque());
}

void pedalSmoothnessDataPageHandler(BicyclePowerTorqueEffectivenessAndPedalSmoothness& msg, uintptr_t data) {
    Serial.print("Left Torque Effectiveness: ");
    Serial.println(msg.getLeftTorqueEffectiveness());
    Serial.print("Right Torque Effectiveness: ");
    Serial.println(msg.getRightTorqueEffectiveness());
    Serial.print("Left Pedal Smoothness: ");
    Serial.println(msg.getLeftPedalSmoothness());
    Serial.print("Right Pedal Smoothness: ");
    Serial.println(msg.getRightPedalSmoothness());
}

void printStatus(uint8_t status) {
    Serial.print("Channel Status: ");
    switch (status) {
    case CHANNEL_STATUS_UNASSIGNED:
        Serial.println("Unassigned");
        break;
    case CHANNEL_STATUS_ASSIGNED:
        Serial.println("Assigned");
        break;
    case CHANNEL_STATUS_SEARCHING:
        Serial.println("Searching");
        break;
    case CHANNEL_STATUS_TRACKING:
        Serial.println("Tracking");
        break;
    }
}

void bicyclePowerBatteryStatus(uint8_t flags) {
    switch (flags) {
    case ANTPLUS_COMMON_DATAPAGE_BATTERYSTATUS_BATTERYSTATUS_NEW:
        Serial.println("New");
        break;
    case ANTPLUS_COMMON_DATAPAGE_BATTERYSTATUS_BATTERYSTATUS_GOOD:
        Serial.println("Good");
        break;
    case ANTPLUS_COMMON_DATAPAGE_BATTERYSTATUS_BATTERYSTATUS_OK:
        Serial.println("Ok");
        break;
    case ANTPLUS_COMMON_DATAPAGE_BATTERYSTATUS_BATTERYSTATUS_LOW:
        Serial.println("Low");
        break;
    case ANTPLUS_COMMON_DATAPAGE_BATTERYSTATUS_BATTERYSTATUS_CRITICAL:
        Serial.println("Critical");
        break;
    case ANTPLUS_COMMON_DATAPAGE_BATTERYSTATUS_BATTERYSTATUS_INVALID:
        Serial.println("Invalid");
        break;
    default:
        Serial.println("Reserved/Unknown");
        break;
    }
}
