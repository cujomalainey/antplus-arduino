/***********************************
 * AntPlus Environment Display example
 *
 * Finds a nearby environment monitor, pairs
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
ProfileEnvironmentDisplay env;

void generalInformationDataPageHandler(EnvironmentGeneralInformation& msg, uintptr_t data);
void temperatureDataPageHandler(EnvironmentTemperature& msg, uintptr_t data);
void manufacturersInformationDataPageHandler(ManufacturersInformation& msg, uintptr_t data);
void productInformationDataPageHandler(ProductInformation& msg, uintptr_t data);

void printStatus(uint8_t status);

void setup() {
    Serial1.begin(BAUD_RATE);
    ant.setSerial(Serial1);
    delay(15000);

    router.setDriver(&ant); // never touch ant again
    router.setAntPlusNetworkKey(NETWORK_KEY);
    router.setProfile(CHANNEL_0, &env);
    // Delay after initial setup to wait for user to connect on serial

    Serial.begin(BAUD_RATE);
    Serial.println("Running");
    env.onEnvironmentGeneralInformation(generalInformationDataPageHandler);
    env.onEnvironmentTemperature(temperatureDataPageHandler);
    env.onManufacturersInformation(manufacturersInformationDataPageHandler);
    env.onProductInformation(productInformationDataPageHandler);
    env.begin();
    // wait for pair to complete
    uint8_t status = env.waitForPair();
    // print channel status
    Serial.println("===========================");
    printStatus(status);
    Serial.print("Device Number: ");
    Serial.println(env.getDeviceNumber());
    Serial.print("Transmisison Type: ");
    Serial.println(env.getTransmissionType());
}

void loop() {
    router.loop();
}

void generalInformationDataPageHandler(EnvironmentGeneralInformation& msg, uintptr_t data) {
    Serial.println("===========================");
    Serial.print("DataPage: ");
    Serial.println(msg.getDataPageNumber());
    Serial.print("Local Time: ");
    Serial.println(msg.getTransmissionInfoLocalTime());
    Serial.print("UTC Time: ");
    Serial.println(msg.getTransmissionInfoUtcTime());
    Serial.print("Default Transmisison Rate: ");
    if (msg.getTransmissionInfoDefaultTransmissionRate() == 0) {
        Serial.println("0.5Hz");
    } else if (msg.getTransmissionInfoDefaultTransmissionRate() == 1) {
        Serial.println("4Hz");
    } else {
        Serial.println("Unknown");
    }
    Serial.println("Supported Pages: ");
    if (msg.getSupportedPages() & ANTPLUS_ENVIRONMENT_DATAPAGE_GENERALINFORMATION_SUPPORTEDPAGES_PAGE0SUPPORT) {
        Serial.println("Page 0 Supported");
    }
    if (msg.getSupportedPages() & ANTPLUS_ENVIRONMENT_DATAPAGE_GENERALINFORMATION_SUPPORTEDPAGES_PAGE1SUPPORT) {
        Serial.println("Page 1 Supported");
    }
}

void temperatureDataPageHandler(EnvironmentTemperature& msg, uintptr_t data) {
    Serial.println("===========================");
    Serial.print("DataPage: ");
    Serial.println(msg.getDataPageNumber());
    Serial.print("Event Count: ");
    Serial.println(msg.getEventCount());
    Serial.print("24h Low (C): ");
    Serial.println(msg.get24HourLow()*0.1);
    Serial.print("24h High (C): ");
    Serial.println(msg.get24HourHigh()*0.1);
    Serial.print("Current Temp (C): ");
    Serial.println(msg.getCurrentTemp()*0.01);
}

void manufacturersInformationDataPageHandler(ManufacturersInformation& msg, uintptr_t data) {
    Serial.println("===========================");
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
    Serial.println("===========================");
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
