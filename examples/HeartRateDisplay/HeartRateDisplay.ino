/***********************************
 * AntPlus HRDisplay example
 *
 * Finds a nearby HR Monitor, pairs
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

ArduinoSerialAntWithCallbacks ant;
AntPlusRouter router;
ProfileHeartRateDisplay hr;

void heartRateBaseDataPageHandler(AntRxDataResponse& msg, uintptr_t data);
void batteryStatusDataPageHandler(HeartRateBatteryStatus& msg, uintptr_t data);
void capabilitiesDataPageHandler(HeartRateCapabilities& msg, uintptr_t data);
void cumulativeOperatingTimeDataPageHandler(HeartRateCumulativeOperatingTime& msg, uintptr_t data);
void defaultDataPageHandler(HeartRateDefault& msg, uintptr_t data);
void manufacturerInformationDataPageHandler(HeartRateManufacturerInformation& msg, uintptr_t data);
void previousHeartBeatDataPageHandler(HeartRatePreviousHeartBeat& msg, uintptr_t data);
void productInformationDataPageHandler(HeartRateProductInformation& msg, uintptr_t data);
void swimIntervalSummary(HeartRateSwimIntervalSummary& msg, uintptr_t data);

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
    hr.onDataPage(heartRateBaseDataPageHandler);
    hr.onHeartRateBatteryStatus(batteryStatusDataPageHandler);
    hr.onHeartRateCapabilities(capabilitiesDataPageHandler);
    hr.onHeartRateCumulativeOperatingTime(cumulativeOperatingTimeDataPageHandler);
    hr.onHeartRateDefault(defaultDataPageHandler);
    hr.onHeartRateManufacturerInformation(manufacturerInformationDataPageHandler);
    hr.onHeartRatePreviousHeartBeat(previousHeartBeatDataPageHandler);
    hr.onHeartRateProductInformation(productInformationDataPageHandler);
    hr.onHeartRateSwimIntervalSummary(swimIntervalSummary);
    hr.begin();
    // wait for pair to complete
    uint8_t status = hr.waitForPair();
    // print channel status
    Serial.println("===========================");
    printStatus(status);
    Serial.print("Device Number: ");
    Serial.println(hr.getDeviceNumber());
    Serial.print("Transmisison Type: ");
    Serial.println(hr.getTransmissionType());
}

void loop() {
    router.loop();
}

void batteryStatusDataPageHandler(HeartRateBatteryStatus& msg, uintptr_t data) {
    Serial.print("Battery Level: ");
    Serial.println(msg.getBatteryLevel());
    Serial.print("Fractional Battery Voltage: ");
    Serial.println(msg.getFractionalBatteryVoltage());
    Serial.print("Coarse Battery Voltage: ");
    Serial.println(msg.getCoarseBatteryVoltage());
    Serial.print("Battery Status: ");
    Serial.println(msg.getBatteryStatus());
}

void capabilitiesDataPageHandler(HeartRateCapabilities& msg, uintptr_t data) {
    Serial.print("Features Supported: ");
    heartRateFeatures(msg.getFeaturesSupported());
    Serial.print("Features Enabled: ");
    heartRateFeatures(msg.getFeaturesEnabled());
}

void cumulativeOperatingTimeDataPageHandler(HeartRateCumulativeOperatingTime& msg, uintptr_t data) {
    Serial.print("Cumulative Operating Time: ");
    Serial.println(msg.getCumulativeOperatingTime());
}

void defaultDataPageHandler(HeartRateDefault& msg, uintptr_t data) {
    // All fields are reserved
}

void manufacturerInformationDataPageHandler(HeartRateManufacturerInformation& msg, uintptr_t data) {
    Serial.print("Manufacturer ID LSB: ");
    Serial.println(msg.getManufacturerIdLsb());
    Serial.print("Serial Number: ");
    Serial.println(msg.getSerialNumber());
}

void previousHeartBeatDataPageHandler(HeartRatePreviousHeartBeat& dp, uintptr_t data) {
    Serial.print("Manufacturer Specific Byte: ");
    if (dp.getManufacturerSpecific() == ANTPLUS_HEARTRATE_DATAPAGE_PREVIOUSHEARTBEAT_MANUFACTURERSPECIFIC_INVALID) {
        Serial.println("Invalid");
    } else {
        Serial.println(dp.getManufacturerSpecific());
    }
    Serial.print("Previous Heart Beat Event Time: ");
    Serial.println(dp.getPreviousHeartBeatEventTime());
}

void productInformationDataPageHandler(HeartRateProductInformation& msg, uintptr_t data) {
    Serial.print("Hardware Version: ");
    Serial.println(msg.getHardwareVersion());
    Serial.print("Software Version: ");
    Serial.println(msg.getSoftwareVersion());
    Serial.print("Model Number: ");
    Serial.println(msg.getModelNumber());
}

void swimIntervalSummary(HeartRateSwimIntervalSummary& msg, uintptr_t data) {
    Serial.print("Interval Average Heart Rate: ");
    if (msg.getIntervalAverageHeartRate() == ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_INTERVALAVERAGEHEARTRATE_INVALID) {
        Serial.println("Invalid");
    } else {
        Serial.println(msg.getIntervalAverageHeartRate());
    }

    Serial.print("Interval Maximum Heart Rate: ");
    if (msg.getIntervalMaximumHeartRate() == ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_INTERVALMAXIMUMHEARTRATE_INVALID) {
        Serial.println("Invalid");
    } else {
        Serial.println(msg.getIntervalMaximumHeartRate());
    }

    Serial.print("Session Average Heart Rate: ");
    if (msg.getSessionAverageHeartRate() == ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_SESSIONAVERAGEHEARTRATE_INVALID) {
        Serial.println("Invalid");
    } else {
        Serial.println(msg.getSessionAverageHeartRate());
    }
}

void heartRateBaseDataPageHandler(AntRxDataResponse& msg, uintptr_t data) {
    HeartRateBaseMainDataPage dp = HeartRateBaseMainDataPage(msg);
    Serial.println("===========================");
    Serial.print("DataPage: ");
    Serial.println(dp.getDataPageNumber());
    Serial.print("Heart Beat Event Time: ");
    Serial.println(dp.getHeartBeatEventTime());
    Serial.print("Heart Beat Count: ");
    Serial.println(dp.getHeartBeatCount());
    Serial.print("Computed Heart Rate: ");
    Serial.println(dp.getComputedHeartRate());
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
