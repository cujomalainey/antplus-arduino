/***********************************
 * AntPlus HRMonitor example
 *
 * Implements a HR Monitor sensor with
 * mocked data to it and then reports
 * all events through the serial port
 *
 * This is a minimum viable example
 * all additional datapages are optional
 * and are enabled through flags passed
 * into the profile
 *
 * It is highly recommended you read the documenation at
 * https://github.com/cujomalainey/antplus-arduino/wiki/HeartRate-Monitor-Profile
 *
 * Author Curtis Malainey
 ************************************/
#include <Arduino.h>
#include "ANT.h"
#include "ANTPLUS.h"

#define BAUD_RATE 9600
#define CHANNEL_0 0

const uint8_t NETWORK_KEY[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77}; // get this from thisisant.com

uint32_t flags = 0;
AntWithCallbacks ant;
AntPlusRouter router;
ProfileHeartRateMonitor hr(123, 0, flags);

// void batteryStatusDataPageHandler(HeartRateBatteryStatusMsg& msg, uintptr_t data);
// void capabilitiesDataPageHandler(HeartRateCapabilitiesMsg& msg, uintptr_t data);
// void cumulativeOperatingTimeDataPageHandler(HeartRateCumulativeOperatingTimeMsg& msg, uintptr_t data);
void defaultDataPageHandler(HeartRateDefaultMsg& msg, uintptr_t data);
void manufacturerInformationDataPageHandler(HeartRateManufacturerInformationMsg& msg, uintptr_t data);
// void previousHeartBeatDataPageHandler(HeartRatePreviousHeartBeatMsg& msg, uintptr_t data);
void productInformationDataPageHandler(HeartRateProductInformationMsg& msg, uintptr_t data);
// void swimIntervalSummary(HeartRateSwimIntervalSummaryMsg& msg, uintptr_t data);

void populateBaseHeartRate(HeartRateBaseMainDataPageMsg& msg);

void setup() {
    Serial1.begin(BAUD_RATE);
    ant.setSerial(Serial1);
    delay(15000);
    Serial.begin(BAUD_RATE);
    Serial.println("Running");

    router.setDriver(&ant); // never touch ant again
    router.setAntPlusNetworkKey(NETWORK_KEY);
    router.setProfile(CHANNEL_0, &hr);
    // Delay after initial setup to wait for user to connect on serial

    // hr.createHeartRateBatteryStatusMsg(batteryStatusDataPageHandler);
    // hr.createHeartRateCapabilitiesMsg(capabilitiesDataPageHandler);
    // hr.createHeartRateCumulativeOperatingTimeMsg(cumulativeOperatingTimeDataPageHandler);
    hr.createHeartRateDefaultMsg(defaultDataPageHandler);
    hr.createHeartRateManufacturerInformationMsg(manufacturerInformationDataPageHandler);
    // hr.createHeartRatePreviousHeartBeatMsg(previousHeartBeatDataPageHandler);
    hr.createHeartRateProductInformationMsg(productInformationDataPageHandler);
    // hr.createHeartRateSwimIntervalSummaryMsg(swimIntervalSummary);
    Serial.println("===========================");
    hr.begin();
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

/* Optional */
// void batteryStatusDataPageHandler(HeartRateBatteryStatusMsg& msg, uintptr_t data) {
//     printDpMsg(7, "Battery Status");
//     populateBaseHeartRate(msg);
// }

/* Optional */
// void capabilitiesDataPageHandler(HeartRateCapabilitiesMsg& msg, uintptr_t data) {
//     printDpMsg(6, "Capabilities");
//     populateBaseHeartRate(msg);
// }

/* Optional */
// void cumulativeOperatingTimeDataPageHandler(HeartRateCumulativeOperatingTimeMsg& msg, uintptr_t data) {
//     printDpMsg(1, "Cumulative Operating Time");
//     populateBaseHeartRate(msg);
// }

void defaultDataPageHandler(HeartRateDefaultMsg& msg, uintptr_t data) {
    // All fields are reserved
    printDpMsg(0, "Default");
    populateBaseHeartRate(msg);
}

void manufacturerInformationDataPageHandler(HeartRateManufacturerInformationMsg& msg, uintptr_t data) {
    printDpMsg(2, "Manufacturer Information");
    populateBaseHeartRate(msg);
    msg.setManufacturerIdLsb(78);
    msg.setSerialNumber(0xabcd);
}

/* Optional */
// void previousHeartBeatDataPageHandler(HeartRatePreviousHeartBeatMsg& msg, uintptr_t data) {
//     printDpMsg(4, "Previous Heart Beat");
//     populateBaseHeartRate(msg);
// }

void productInformationDataPageHandler(HeartRateProductInformationMsg& msg, uintptr_t data) {
    printDpMsg(3, "Product Information");
    populateBaseHeartRate(msg);
    msg.setHardwareVersion(1);
    msg.setSoftwareVersion(2);
    msg.setModelNumber(3);
}

/* Optional */
// void swimIntervalSummary(HeartRateSwimIntervalSummaryMsg& msg, uintptr_t data) {
//     printDpMsg(5, "Swim Interval");
//     populateBaseHeartRate(msg);
// }

void populateBaseHeartRate(HeartRateBaseMainDataPageMsg& msg) {
    static uint8_t toggle = 0;
    static uint8_t hr = 0;
    static uint16_t eventTime = 0;
    static uint8_t count = 0;
    msg.setPageChangeToggle(toggle++ < 4);
    msg.setComputedHeartRate(20*sin(hr++) + 120);
    msg.setHeartBeatEventTime(eventTime);
    msg.setHeartBeatCount(count++);

    if (toggle >= 8) {
        toggle = 0;
    }
    eventTime += 120;
}
