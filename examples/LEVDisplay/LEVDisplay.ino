/**********************************************
 * AntPlus LEV Display example
 *
 * Finds a nearby LEV Sensor, pairs
 * to it and then reads the information
 * out via the serial port.
 *
 * Author Bernd Woköck
 *        based on the work of Curtis Malainey
 **********************************************/
#include <Arduino.h>
#include "ANT.h"
#include "ANTPLUS.h"

#define BAUD_RATE 9600
#define CHANNEL_0 0
#define CHANNEL_1 1

const uint8_t NETWORK_KEY[] = { 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77 };

AntWithCallbacks ant = AntWithCallbacks();
AntPlusRouter router = AntPlusRouter();
ProfileLevDisplay lev = ProfileLevDisplay();

void levBaseDataPageHandler(AntRxDataResponse& msg, uintptr_t data);
void levSpeedSystemInformation1Handler(LevSpeedSystemInformation1& msg, uintptr_t data);
void levSpeedDistanceInformationHandler(LevSpeedDistanceInformation& msg, uintptr_t data);
void levAltSpeedDistanceInformationHandler(LevAltSpeedDistanceInformation& msg, uintptr_t data);
void levSpeedSystemInformation2Handler(LevSpeedSystemInformation2& msg, uintptr_t data);
void levBatteryInfo(LevBatteryInfo& msg, uintptr_t data);
void levAntChannelEvent(ChannelEventResponse& msg, uintptr_t data);

void manufacturersInformationDataPageHandler(ManufacturersInformation& msg, uintptr_t data);
void productInformationDataPageHandler(ProductInformation& msg, uintptr_t data);

void printStatus(uint8_t status);

void setup() {
    Serial2.begin(BAUD_RATE);
    ant.setSerial(Serial2);
    delay(1000);

    router.setDriver(&ant); // never touch ant again
    router.setAntPlusNetworkKey(NETWORK_KEY);
    router.setProfile(CHANNEL_0, &lev);

    Serial.begin(BAUD_RATE);
    Serial.println("Running");

    // setup lev display
    lev.onDataPage(levBaseDataPageHandler);
    lev.onLevSpeedSystemInformation1(levSpeedSystemInformation1Handler);
    lev.onLevSpeedDistanceInformation(levSpeedDistanceInformationHandler);
    lev.onLevAltSpeedDistanceInformation(levAltSpeedDistanceInformationHandler);
    lev.onLevSpeedSystemInformation2(levSpeedSystemInformation2Handler);
    lev.onLevBatteryInfo(levBatteryInfo);
    lev.onLevCapabilities(levCapabilities);
    lev.onManufacturersInformation(manufacturersInformationDataPageHandler);
    lev.onProductInformation(productInformationDataPageHandler);
    lev.onChannelEvent(levAntChannelEvent);
    lev.begin();
    delay(100); // wait for module initialization

    // wait for pair to complete
    uint8_t status = lev.waitForPair();

    // print channel status
    Serial.println("===========================");
    printStatus(status);
    Serial.print("Device Number: ");
    Serial.println(lev.getDeviceNumber());
    Serial.print("Transmisison Type: ");
    Serial.println(lev.getTransmissionType());
}

void loop() {
    router.loop();
}

void levAntChannelEvent(ChannelEventResponse& msg, uintptr_t data) {
    if (msg.getCode() == STATUS_EVENT_CHANNEL_CLOSED) {
        Serial.println("channel closed - reconnect");
        lev.begin();
    }
}

void levBaseDataPageHandler(AntRxDataResponse& msg, uintptr_t data) {
    LevBaseMainDataPage dp = LevBaseMainDataPage(msg);
    Serial.println("===========================");
    Serial.print("DataPage: ");
    Serial.println(dp.getDataPageNumber());
}

void levSpeedSystemInformation1Handler(LevSpeedSystemInformation1& msg, uintptr_t data) {
    Serial.print("Temperature state: ");
    Serial.println(msg.getTemperatureState());      // TODO enums for temperature state
    Serial.print("Travel mode state: ");
    Serial.println(msg.getTravelModeState());       // TODO decode travel mode state
    Serial.print("System state: ");
    Serial.println(msg.getSystemState());           // TODO enums for system state
    Serial.print("Gear state: ");
    Serial.println(msg.getGearState());             // TODO decode gear state
    Serial.print("Gear error: ");
    Serial.println(msg.getErrorMessage());          // TODO enums for error message
    Serial.print("Speed: ");
    Serial.print(msg.getSpeed()/10);
    Serial.print(".");
    Serial.println(msg.getSpeed() % 10);
}

void levSpeedDistanceInformationHandler(LevSpeedDistanceInformation& msg, uintptr_t data) {
    Serial.print("Total dist: ");
    Serial.println((float)msg.getOdometer() / 100);
    Serial.print("Remaining range: ");
    Serial.println(msg.getRemainingRange());        // TODO 0 = unknown
    Serial.print("Speed: ");
    Serial.print(msg.getSpeed() / 10);
    Serial.print(".");
    Serial.println(msg.getSpeed() % 10);
}

void levAltSpeedDistanceInformationHandler(LevAltSpeedDistanceInformation& msg, uintptr_t data) {
    Serial.print("Total dist: ");
    Serial.println((float)msg.getOdometer() / 100);
    Serial.print("Fuel consumption: ");
    Serial.println(msg.getFuelConsumption());       // TODO 0 = unknown
    Serial.print("Speed: ");
    Serial.print(msg.getSpeed() / 10);
    Serial.print(".");
    Serial.println(msg.getSpeed() % 10);
}

void levSpeedSystemInformation2Handler(LevSpeedSystemInformation2& msg, uintptr_t data) {
    Serial.print("Battery SOC: ");
    Serial.println(msg.getBatterySOC());
    Serial.print("Travel mode state: ");
    Serial.println(msg.getTravelModeState());        // TODO decode travel mode state
    Serial.print("System state: ");
    Serial.println(msg.getSystemState());            // TODO enums for system state
    Serial.print("Gear state: ");
    Serial.println(msg.getGearState());              // TODO decode gear state
    Serial.print("Percent Assist: ");
    Serial.println(msg.getPercentAssist());
    Serial.print("Speed: ");
    Serial.print(msg.getSpeed() / 10);
    Serial.print(".");
    Serial.println(msg.getSpeed() % 10);
}

void levBatteryInfo(LevBatteryInfo& msg, uintptr_t data) {
    Serial.print("Charging Cycle Count: ");
    Serial.println(msg.getChargingCycleCount());
    Serial.print("Fuel consumption: ");
    Serial.println(msg.getFuelConsumption());            // TODO 0 = unknown
    Serial.print("Battery voltage: ");
    Serial.println(msg.getBatteryVoltage());             // TODO 0 = unknown
    Serial.print("Distance on current charge: ");
    Serial.println(msg.getDistanceOnCurrentCharge());    // TODO 0 = unknown
}

void levCapabilities(LevCapabilities& msg, uintptr_t data) {
    Serial.print("Travel modes supported: ");
    Serial.println(msg.getTravelModesSupported());       // TODO decode travel modes supported
    Serial.print("Wheel circumference: ");
    Serial.println(msg.getWheelCircumference());
}

void manufacturersInformationDataPageHandler(ManufacturersInformation& msg, uintptr_t data) {
    Serial.print("DataPage: ");
    Serial.println(msg.getDataPageNumber());
    Serial.print("HW Revision: ");
    Serial.println(msg.getHWRevision());
    Serial.print("ManufacturerID: ");
    Serial.println(msg.getManufacturerID());
    Serial.print("Model Number: ");
    Serial.println(msg.getModelNumber());
}

void productInformationDataPageHandler(ProductInformation& msg, uintptr_t data) {
    Serial.print("DataPage: ");
    Serial.println(msg.getDataPageNumber());
    Serial.print("SW Revision Supplemental: ");
    Serial.println(msg.getSWRevisionSupplemental());
    Serial.print("SW Revision Main: ");
    Serial.println(msg.getSWRevisionMain());
    Serial.print("Serial Number: ");
    Serial.println(msg.getSerialNumber());
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

