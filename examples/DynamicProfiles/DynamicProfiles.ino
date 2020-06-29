/***********************************
 * AntPlus DynamicProfiles example
 *
 * Finds a nearby HR Monitor, pairs
 * to it and then reads the information
 * out via the serial port. Then switches
 * after 30s to a bike speed sensor. After
 * 30s returns to HR and loops.
 *
 * Author Curtis Malainey
 ************************************/
#include <Arduino.h>
#include "ANT.h"
#include "ANTPLUS.h"

#define BAUD_RATE 9600
#define CHANNEL_0 0
#define CHANNEL_RUNTIME 30*1000

const uint8_t NETWORK_KEY[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77}; // get this from thisisant.com
uint32_t timeLastSwitch = 0;
bool isHrProfileRunning = true;

ArduinoSerialAntWithCallbacks ant;
AntPlusRouter router;
ProfileHeartRateDisplay hr;
ProfileBicycleSpeedDisplay bikeSpeed;

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
void flipProfile();

void setup() {
    Serial.begin(BAUD_RATE);
    Serial.println("Running");
    Serial1.begin(BAUD_RATE);
    ant.setSerial(Serial1);
    // Delay after initial setup to wait for user to connect on serial

    router.setDriver(&ant); // never touch ant again
    router.setAntPlusNetworkKey(NETWORK_KEY);

    bikeSpeed.onDataPage(bicycleSpeedBaseDataPageHandler);
    bikeSpeed.onBicycleSpeedBatteryStatus(batteryStatusDataPageHandler);
    bikeSpeed.onBicycleSpeedMotionAndSpeed(motionAndSpeedDataPageHandler);
    bikeSpeed.onBicycleSpeedCumulativeOperatingTime(cumulativeOperatingTimeDataPageHandler);
    bikeSpeed.onBicycleSpeedDefault(defaultDataPageHandler);
    bikeSpeed.onBicycleSpeedManufacturerID(manufacturerIDDataPageHandler);
    bikeSpeed.onBicycleSpeedProductID(productIDDataPageHandler);
    hr.onDataPage(heartRateBaseDataPageHandler);
    hr.onHeartRateBatteryStatus(batteryStatusDataPageHandler);
    hr.onHeartRateCapabilities(capabilitiesDataPageHandler);
    hr.onHeartRateCumulativeOperatingTime(cumulativeOperatingTimeDataPageHandler);
    hr.onHeartRateDefault(defaultDataPageHandler);
    hr.onHeartRateManufacturerInformation(manufacturerInformationDataPageHandler);
    hr.onHeartRatePreviousHeartBeat(previousHeartBeatDataPageHandler);
    hr.onHeartRateProductInformation(productInformationDataPageHandler);
    hr.onHeartRateSwimIntervalSummary(swimIntervalSummary);
    flipProfile();
}

void loop() {
    router.loop();
    if (millis() - timeLastSwitch > CHANNEL_RUNTIME) {
        timeLastSwitch = millis();
        flipProfile();
    }
}

void flipProfile() {
    uint8_t status;
    Serial.println("===========================");
    if (isHrProfileRunning) {
        // stop will be called by remove profile as well if you forget
        hr.stop();
        // remove by profile pointer
        router.removeProfile(&hr);
        router.setProfile(CHANNEL_0, &bikeSpeed);
        Serial.print("Profile added to channel: ");
        Serial.println(CHANNEL_0);
        bikeSpeed.begin();
        status = bikeSpeed.waitForPair();
    } else {
        bikeSpeed.stop();
        // remove by channel index
        router.removeProfileByChannel(CHANNEL_0);
        uint8_t channel = router.addProfileToNextChannel(&hr);
        Serial.print("Profile added to channel: ");
        Serial.println(channel);
        hr.begin();
        status = hr.waitForPair();
    }
    printStatus(status);
    isHrProfileRunning = !isHrProfileRunning;
}

void printDeviceId(BaseProfile *profile) {
    // print channel status
    Serial.println("===========================");
    Serial.print("Device Number: ");
    Serial.println(profile->getDeviceNumber());
    Serial.print("Transmisison Type: ");
    Serial.println(profile->getTransmissionType());
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
    Serial.println(dp.getManufacturerSpecific());
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
    Serial.println(msg.getIntervalAverageHeartRate());
    Serial.print("Interval Maximum Heart Rate: ");
    Serial.println(msg.getIntervalMaximumHeartRate());
    Serial.print("Session Average Heart Rate: ");
    Serial.println(msg.getSessionAverageHeartRate());
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
