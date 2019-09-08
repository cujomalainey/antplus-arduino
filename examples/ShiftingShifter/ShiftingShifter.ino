/**********************************************
 * AntPlus shifting shifter example
 *
 * Deliver data of a shifting sensor
 * to a display via serial port
 *
 * Author Bernd Woköck
 *        based on the work of Curtis Malainey
 **********************************************/
#include <Arduino.h>
#include "ANT.h"
#include "ANTPLUS.h"

#define BAUD_RATE 9600
#define CHANNEL_0 0

const uint8_t NETWORK_KEY[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77}; // get this from thisisant.com

AntWithCallbacks ant = AntWithCallbacks();
AntPlusRouter router = AntPlusRouter();
ProfileShiftingShifter shift = ProfileShiftingShifter(7370);

void shiftSystemStatusMsgHandler(ShiftingShiftSystemStatusMsg& msg, uintptr_t data);
void multiComponentSystemManufacturersInformationMsgHandler(MultiComponentSystemManufacturersInformationMsg& msg, uintptr_t data);
void multiComponentSystemProductInformationMsgHandler(MultiComponentSystemProductInformationMsg& msg, uintptr_t data);
void batteryStatusMsgHandler(BatteryStatusMsg& msg, uintptr_t data);

void setup() {
    Serial1.begin(BAUD_RATE);
    ant.setSerial(Serial1);
    delay(3000);

    router.setDriver(&ant); // never touch ant again
    router.setAntPlusNetworkKey(NETWORK_KEY);
    router.setProfile(CHANNEL_0, &shift);

    Serial.begin(BAUD_RATE);
    Serial.println("Running");

    // setup shifting monitor
    shift.createShiftingShiftSystemStatusMsg(shiftSystemStatusMsgHandler);
    shift.createMultiComponentSystemManufacturersInformationMsg(multiComponentSystemManufacturersInformationMsgHandler);
    shift.createMultiComponentSystemProductInformationMsg(multiComponentSystemProductInformationMsgHandler);
    shift.createBatteryStatusMsg(batteryStatusMsgHandler);
    shift.begin();
    delay(100); // wait for module initialization
}

void loop() {
    router.loop();
}

void printDpMsg(int dp, const char* s) {
    Serial.print("Sending DataPage: ");
    Serial.print(dp);
    Serial.print(" - ");
    Serial.println(s);
}

void shiftSystemStatusMsgHandler(ShiftingShiftSystemStatusMsg& msg, uintptr_t data) {
    static int _gear = 0;
    static int _eventCount = 0;
    printDpMsg(1, "Shift System Status");
    msg.setTotalNumbersGearFront(1);
    msg.setTotalNumbersGearRear(10);

    msg.setCurrentGearFront(1);
    msg.setCurrentGearRear(_gear++ % 10);
    msg.setEventCount(_eventCount++);
}

void multiComponentSystemManufacturersInformationMsgHandler(MultiComponentSystemManufacturersInformationMsg& msg, uintptr_t data) {
    printDpMsg(78, "Multi Component System Manufacturers Information");
    msg.setNumberOfComponents(3);
    msg.setComponentIdentifier(1);
    msg.setHWRevision(0x01);
    msg.setManufacturerId(0x1234);
    msg.setModelNumber(0x0002);
}

void multiComponentSystemProductInformationMsgHandler(MultiComponentSystemProductInformationMsg& msg, uintptr_t data) {
    printDpMsg(79, "Multi Component System Product Information");
    msg.setNumberOfComponents(3);
    msg.setComponentIdentifier(1);
    msg.setSerialNumber(0x12345678);
    msg.setSWRevisionMain(0x01);
    msg.setSWRevisionSupplemental(0x00);
}

void batteryStatusMsgHandler(BatteryStatusMsg& msg, uintptr_t data) {
    printDpMsg(82, "Battery Status");
    msg.setNumberOfBatteries(3);
    msg.setBatteryIdentifier(1);
    msg.setCumulativeOperatingTime(123);
    msg.setFractionalBatteryVoltage(12);
    msg.setCoarseBatteryVoltage(12);
    msg.setBatteryStatus(0); // TODO defines?
    msg.setCumulativeOperatingTimeResolution(12);
}
