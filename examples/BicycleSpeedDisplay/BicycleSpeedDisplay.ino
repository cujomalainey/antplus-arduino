/***********************************
 * AntPlus Bicycle Speed Display example
 *
 * Finds a nearby Bike Speed Sensor, pairs
 * to it and then reads the information
 * out via the serial port.
 *
 * Author Curtis Malainey
 ************************************/
#include <Arduino.h>
#include "ANT.h"
#include "ANTPLUS.h"

#define BAUD_RATE 9600
#define CHANNEL_0 0

const uint8_t NETWORK_KEY[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77}; // get this from thisisant.com

AntWithCallbacks ant = AntWithCallbacks();
AntPlusRouter router = AntPlusRouter();
ProfileBicycleSpeedDisplay bikeSpeed = ProfileBicycleSpeedDisplay();

void bicycleSpeedBaseDataPageHandler(AntRxDataResponse& msg, uintptr_t data);
void batteryStatusDataPageHandler(BicycleSpeedBatteryStatus& msg, uintptr_t data);
void motionAndSpeedDataPageHandler(BicycleSpeedMotionAndSpeed& msg, uintptr_t data);
void cumulativeOperatingTimeDataPageHandler(BicycleSpeedCumulativeOperatingTime& msg, uintptr_t data);
void defaultDataPageHandler(BicycleSpeedDefault& msg, uintptr_t data);
void manufacturerIDDataPageHandler(BicycleSpeedManufacturerID& msg, uintptr_t data);
void productIDDataPageHandler(BicycleSpeedProductID& msg, uintptr_t data);

void bicycleSpeedFlags(uint8_t flags);
void bicycleSpeedBatteryStatus(uint8_t flags);
void printStatus(uint8_t status);

void setup() {
    Serial1.begin(BAUD_RATE);
    ant.setSerial(Serial1);
    delay(15000);

    router.setDriver(&ant); // never touch ant again
    router.setAntPlusNetworkKey(NETWORK_KEY);
    router.setProfile(CHANNEL_0, &bikeSpeed);
    // Delay after initial setup to wait for user to connect on serial

    Serial.begin(BAUD_RATE);
    Serial.println("Running");
    bikeSpeed.onDataPage(bicycleSpeedBaseDataPageHandler);
    bikeSpeed.onBicycleSpeedBatteryStatus(batteryStatusDataPageHandler);
    bikeSpeed.onBicycleSpeedMotionAndSpeed(motionAndSpeedDataPageHandler);
    bikeSpeed.onBicycleSpeedCumulativeOperatingTime(cumulativeOperatingTimeDataPageHandler);
    bikeSpeed.onBicycleSpeedDefault(defaultDataPageHandler);
    bikeSpeed.onBicycleSpeedManufacturerID(manufacturerIDDataPageHandler);
    bikeSpeed.onBicycleSpeedProductID(productIDDataPageHandler);
    bikeSpeed.begin();
    // wait for pair to complete
    uint8_t status = bikeSpeed.waitForPair();
    // print channel status
    Serial.println("===========================");
    printStatus(status);
    Serial.print("Device Number: ");
    Serial.println(bikeSpeed.getDeviceNumber());
    Serial.print("Transmisison Type: ");
    Serial.println(bikeSpeed.getTransmissionType());
}

void loop() {
    router.loop();
}

void batteryStatusDataPageHandler(BicycleSpeedBatteryStatus& msg, uintptr_t data) {
    Serial.print("Fractional Battery Voltage: ");
    Serial.println(msg.getFractionalBatteryVoltage());
    Serial.print("Coarse Battery Voltage: ");
    Serial.println(msg.getCoarseBatteryVoltage());
    Serial.print("Battery Status: ");
    bicycleSpeedBatteryStatus(msg.getBatteryStatus());
}

void motionAndSpeedDataPageHandler(BicycleSpeedMotionAndSpeed& msg, uintptr_t data) {
    Serial.print("Flags: ");
    bicycleSpeedFlags(msg.getFlags());
}

void cumulativeOperatingTimeDataPageHandler(BicycleSpeedCumulativeOperatingTime& msg, uintptr_t data) {
    Serial.print("Cumulative Operating Time: ");
    Serial.println(msg.getCumulativeOperatingTime());
}

void defaultDataPageHandler(BicycleSpeedDefault& msg, uintptr_t data) {
    // All fields are reserved
}

void manufacturerIDDataPageHandler(BicycleSpeedManufacturerID& msg, uintptr_t data) {
    Serial.print("Manufacturer ID LSB: ");
    Serial.println(msg.getManufacturerId());
    Serial.print("Serial Number: ");
    Serial.println(msg.getSerialNumber());
}

void productIDDataPageHandler(BicycleSpeedProductID& msg, uintptr_t data) {
    Serial.print("Hardware Version: ");
    Serial.println(msg.getHardwareVersion());
    Serial.print("Software Version: ");
    Serial.println(msg.getSoftwareVersion());
    Serial.print("Model Number: ");
    Serial.println(msg.getModelNumber());
}

void bicycleSpeedBaseDataPageHandler(AntRxDataResponse& msg, uintptr_t data) {
    BicycleSpeedBaseMainDataPage dp = BicycleSpeedBaseMainDataPage(msg);
    Serial.println("===========================");
    Serial.print("DataPage: ");
    Serial.println(dp.getDataPageNumber());
    Serial.print("Bike Speed Event Time: ");
    Serial.println(dp.getBikeSpeedEventTime());
    Serial.print("Cumulative Speed Revolution Count: ");
    Serial.println(dp.getCumulativeSpeedRevolutionCount());
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

void bicycleSpeedFlags(uint8_t flags) {
    if (flags & ANTPLUS_BICYCLESPEED_DATAPAGE_MOTIONANDSPEED_FLAGS_STOPINDICATOR) {
        Serial.print("Motion Stopped");
    }
    Serial.println();
}

void bicycleSpeedBatteryStatus(uint8_t flags) {
    switch (flags) {
    case ANTPLUS_BICYCLESPEED_DATAPAGE_BATTERSTATUS_BATTERYSTATUS_NEW:
        Serial.println("New");
        break;
    case ANTPLUS_BICYCLESPEED_DATAPAGE_BATTERSTATUS_BATTERYSTATUS_GOOD:
        Serial.println("Good");
        break;
    case ANTPLUS_BICYCLESPEED_DATAPAGE_BATTERSTATUS_BATTERYSTATUS_OK:
        Serial.println("Ok");
        break;
    case ANTPLUS_BICYCLESPEED_DATAPAGE_BATTERSTATUS_BATTERYSTATUS_LOW:
        Serial.println("Low");
        break;
    case ANTPLUS_BICYCLESPEED_DATAPAGE_BATTERSTATUS_BATTERYSTATUS_CRITICAL:
        Serial.println("Critical");
        break;
    case ANTPLUS_BICYCLESPEED_DATAPAGE_BATTERSTATUS_BATTERYSTATUS_INVALID:
        Serial.println("Invalid");
        break;
    default:
        Serial.println("Reserved/Unknown");
        break;
    }
}
