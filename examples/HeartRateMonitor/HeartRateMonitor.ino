/***********************************
 * AntPlus HRMonitor example
 *
 * Implements a HR Monitor sensor with
 * mocked data to it and then reports
 * all events through the serial port
 *
 * Author Curtis Malainey
 ************************************/
#include <Arduino.h>
#include "ANT.h"
#include "ANTPLUS.h"

#define BAUD_RATE 9600
#define CHANNEL_0 0

const uint8_t NETWORK_KEY[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77}; // get this from thisisant.com

AntWithCallbacks ant;
AntPlusRouter router;
ProfileHeartRateMonitor hr(123, 0);

void batteryStatusDataPageHandler(HeartRateBatteryStatusMsg& msg, uintptr_t data);
void capabilitiesDataPageHandler(HeartRateCapabilitiesMsg& msg, uintptr_t data);
void cumulativeOperatingTimeDataPageHandler(HeartRateCumulativeOperatingTimeMsg& msg, uintptr_t data);
void defaultDataPageHandler(HeartRateDefaultMsg& msg, uintptr_t data);
void manufacturerInformationDataPageHandler(HeartRateManufacturerInformationMsg& msg, uintptr_t data);
void previousHeartBeatDataPageHandler(HeartRatePreviousHeartBeatMsg& msg, uintptr_t data);
void productInformationDataPageHandler(HeartRateProductInformationMsg& msg, uintptr_t data);
void swimIntervalSummary(HeartRateSwimIntervalSummaryMsg& msg, uintptr_t data);

void heartRateFeatures(uint8_t bitfield);
void printStatus(uint8_t status);

void setup() {
    Serial1.begin(BAUD_RATE);
    ant.setSerial(Serial1);
    delay(15000);

    router.setDriver(&ant); // never touch ant again
    router.setAntPlusNetworkKey(NETWORK_KEY);
    router.setProfile(CHANNEL_0, &hr);
    // Delay after initial setup to wait for user to connect on serial

    Serial.begin(BAUD_RATE);
    Serial.println("Running");
    hr.createHeartRateBatteryStatusMsg(batteryStatusDataPageHandler);
    hr.createHeartRateCapabilitiesMsg(capabilitiesDataPageHandler);
    hr.createHeartRateCumulativeOperatingTimeMsg(cumulativeOperatingTimeDataPageHandler);
    hr.createHeartRateDefaultMsg(defaultDataPageHandler);
    hr.createHeartRateManufacturerInformationMsg(manufacturerInformationDataPageHandler);
    hr.createHeartRatePreviousHeartBeatMsg(previousHeartBeatDataPageHandler);
    hr.createHeartRateProductInformationMsg(productInformationDataPageHandler);
    hr.createHeartRateSwimIntervalSummaryMsg(swimIntervalSummary);
    hr.begin();
    // print channel status
    Serial.println("===========================");
    /* printStatus(status); */
}

void loop() {
    // Call this very frequently
    router.loop();
}

void printDpMsg(int dp, const char* s) {
    Serial.print("Sending DataPage: ");
    Serial.print(dp);
    Serial.print(" - ");
    Serial.println(s);
}

void batteryStatusDataPageHandler(HeartRateBatteryStatusMsg& msg, uintptr_t data) {
    printDpMsg(7, "Battery Status");
}

void capabilitiesDataPageHandler(HeartRateCapabilitiesMsg& msg, uintptr_t data) {
    printDpMsg(6, "Capabilities");
}

void cumulativeOperatingTimeDataPageHandler(HeartRateCumulativeOperatingTimeMsg& msg, uintptr_t data) {
    printDpMsg(1, "Cumulative Operating Time");
}

void defaultDataPageHandler(HeartRateDefaultMsg& msg, uintptr_t data) {
    // All fields are reserved
    printDpMsg(0, "Default");
}

void manufacturerInformationDataPageHandler(HeartRateManufacturerInformationMsg& msg, uintptr_t data) {
    printDpMsg(2, "Manufacturer Information");
}

void previousHeartBeatDataPageHandler(HeartRatePreviousHeartBeatMsg& dp, uintptr_t data) {
    printDpMsg(4, "Previous Heart Beat");
}

void productInformationDataPageHandler(HeartRateProductInformationMsg& msg, uintptr_t data) {
    printDpMsg(3, "Product Information");
}

void swimIntervalSummary(HeartRateSwimIntervalSummaryMsg& msg, uintptr_t data) {
    printDpMsg(5, "Swim Interval");
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
