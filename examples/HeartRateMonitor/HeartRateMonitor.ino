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
    router.loop();
}

void batteryStatusDataPageHandler(HeartRateBatteryStatusMsg& msg, uintptr_t data) {
    Serial.print("Battery Level: ");
    Serial.println(msg.getBatteryLevel());
    Serial.print("Fractional Battery Voltage: ");
    Serial.println(msg.getFractionalBatteryVoltage());
    Serial.print("Coarse Battery Voltage: ");
    Serial.println(msg.getCoarseBatteryVoltage());
    Serial.print("Battery Status: ");
    Serial.println(msg.getBatteryStatus());
}

void capabilitiesDataPageHandler(HeartRateCapabilitiesMsg& msg, uintptr_t data) {
    Serial.print("Features Supported: ");
    heartRateFeatures(msg.getFeaturesSupported());
    Serial.print("Features Enabled: ");
    heartRateFeatures(msg.getFeaturesEnabled());
}

void cumulativeOperatingTimeDataPageHandler(HeartRateCumulativeOperatingTimeMsg& msg, uintptr_t data) {
    Serial.print("Cumulative Operating Time: ");
    Serial.println(msg.getCumulativeOperatingTime());
}

void defaultDataPageHandler(HeartRateDefaultMsg& msg, uintptr_t data) {
    // All fields are reserved
}

void manufacturerInformationDataPageHandler(HeartRateManufacturerInformationMsg& msg, uintptr_t data) {
    Serial.print("Manufacturer ID LSB: ");
    Serial.println(msg.getManufacturerIdLsb());
    Serial.print("Serial Number: ");
    Serial.println(msg.getSerialNumber());
}

void previousHeartBeatDataPageHandler(HeartRatePreviousHeartBeatMsg& dp, uintptr_t data) {
    Serial.print("Manufacturer Specific Byte: ");
    Serial.println(dp.getManufacturerSpecific());
    Serial.print("Previous Heart Beat Event Time: ");
    Serial.println(dp.getPreviousHeartBeatEventTime());
}

void productInformationDataPageHandler(HeartRateProductInformationMsg& msg, uintptr_t data) {
    Serial.print("Hardware Version: ");
    Serial.println(msg.getHardwareVersion());
    Serial.print("Software Version: ");
    Serial.println(msg.getSoftwareVersion());
    Serial.print("Model Number: ");
    Serial.println(msg.getModelNumber());
}

void swimIntervalSummary(HeartRateSwimIntervalSummaryMsg& msg, uintptr_t data) {
    Serial.print("Interval Average Heart Rate: ");
    Serial.println(msg.getIntervalAverageHeartRate());
    Serial.print("Interval Maximum Heart Rate: ");
    Serial.println(msg.getIntervalMaximumHeartRate());
    Serial.print("Session Average Heart Rate: ");
    Serial.println(msg.getSessionAverageHeartRate());
}

void heartRateFeatures(uint8_t bitfield) {
    if (bitfield & ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_FEATURES_EXTENDEDRUNNING) {
        Serial.print("Extended Running ");
    }
    if (bitfield & ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_FEATURES_EXTENDEDCYCLING) {
        Serial.print("Extended Cycling ");
    }
    if (bitfield & ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_FEATURES_EXTENDEDSWIMMING) {
        Serial.print("Extended Swimming ");
    }
    if (bitfield & ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_FEATURES_MANUFACTURER1) {
        Serial.print("Manufacturer Bit 1 ");
    }
    if (bitfield & ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_FEATURES_MANUFACTURER2) {
        Serial.print("Manufacturer Bit 2 ");
    }
    Serial.println();
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
