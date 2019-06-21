/**********************************************
 * AntPlus Bike Sensor Converter
 *  LEV Display example
 *  MuscleOxygen monitor
 *  Shifting monitor
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

// get ANT network key
#include "arduino_secrets.h"

#define BAUD_RATE 9600

#define ANT_DEVICE_NUMBER_MOXY  7369
#define ANT_DEVICE_NUMBER_SHIFT 7370
#define CHANNEL_0 0
#define CHANNEL_1 1
#define CHANNEL_2 2

const uint8_t NETWORK_KEY[] = SECRET_ANTNETWORK_KEY;

AntWithCallbacks           ant = AntWithCallbacks();
AntPlusRouter              router = AntPlusRouter();
ProfileLevDisplay          lev = ProfileLevDisplay();
ProfileMuscleOxygenMonitor moxy = ProfileMuscleOxygenMonitor(ANT_DEVICE_NUMBER_MOXY);
ProfileShiftingShifter     shift = ProfileShiftingShifter(ANT_DEVICE_NUMBER_SHIFT);

void levBaseDataPageHandler(AntRxDataResponse& msg, uintptr_t data);
void levSpeedSystemInformation1Handler(LevSpeedSystemInformation1& msg, uintptr_t data);
void levSpeedDistanceInformationHandler(LevSpeedDistanceInformation& msg, uintptr_t data);
void levAltSpeedDistanceInformationHandler(LevAltSpeedDistanceInformation& msg, uintptr_t data);
void levSpeedSystemInformation2Handler(LevSpeedSystemInformation2& msg, uintptr_t data);
void levBatteryInfo(LevBatteryInfo& msg, uintptr_t data);
void levAntChannelEvent(ChannelEventResponse& msg, uintptr_t data);

void moxyCreateMsgHandler(MuscleOxygenBaseMainDataPageMsg& msg, uintptr_t data);
void moxyCreateManufacturerInformationMsg(ManufacturersInformationMsg& msg, uintptr_t data);
void moxyCreateProductInformationMsg(ProductInformationMsg& msg, uintptr_t data);

void shiftCreateMsgHandler(ShiftingBaseMainDataPageMsg& msg, uintptr_t data);
void shiftCreateManufacturerInformationMsg(ManufacturersInformationMsg& msg, uintptr_t data);
void shiftCreateProductInformationMsg(ProductInformationMsg& msg, uintptr_t data);

void manufacturersInformationDataPageHandler(ManufacturersInformation& msg, uintptr_t data);
void productInformationDataPageHandler(ProductInformation& msg, uintptr_t data);

void printStatus(uint8_t status);

// mask for changed values
enum {
    SPEED           = 1,
    ODOMETER        = 2,
    BATTERYSOC      = 4,
    SUPPORTLEVEL    = 8,
    SUPPORTLEVELCNT = 16,
    PERCENTASSIST   = 32,
    WHEELCIRC       = 64,
};

// LEV data
struct levDataST {
    uint32_t changedValueMask; // bit field for changed values
    uint16_t speed;        // in 0.1km/h
    uint32_t odometer;     // in 0.01km
    uint8_t  batterySOC;   // in percent
    uint8_t  supportLevel;  // 0..3
    uint8_t  supportLevelCount;  // 4
    uint8_t  percentAssist; // in percent
    uint16_t wheelCircumference; // in mm
}
_levData = { 0, 0, 0, 0, 0, 0, 0, 0 };

void setup() {
    Serial2.begin(BAUD_RATE);
    ant.setSerial(Serial2);
    delay(1000);

    router.setDriver(&ant); // never touch ant again
    router.setAntPlusNetworkKey(NETWORK_KEY);
    router.setProfile(CHANNEL_0, &lev);
    router.setProfile(CHANNEL_1, &moxy);
    router.setProfile(CHANNEL_2, &shift);
    // Delay after initial setup to wait for user to connect on serial

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
    delay(500); // wait for module initialization

    // setup muscle oxygen monitor
    moxy.createMuscleOxygenDataMsg(moxyCreateMsgHandler);
    moxy.createMuscleOxygenManufacturerInformationMsg(moxyCreateManufacturerInformationMsg);
    moxy.createMuscleOxygenProductInformationMsg(moxyCreateProductInformationMsg);
    moxy.begin();
    delay(500);

    // setup shifting  oxygen monitor
    shift.createShiftingSystemStatusMsg(shiftCreateMsgHandler);
    shift.createShiftingManufacturerInformationMsg(shiftCreateManufacturerInformationMsg);
    shift.createShiftingProductInformationMsg(shiftCreateProductInformationMsg);
    shift.begin();
    delay(500);

    // uint8_t status = lev.waitForPair(); // todo no busy wait here
}

void loop() {
    router.loop();
}

void levAntChannelEvent(ChannelEventResponse& msg, uintptr_t data) {
    if (msg.getCode() == STATUS_EVENT_CHANNEL_CLOSED)
    {
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
    _levData.speed = msg.getSpeed();
    _levData.supportLevel = decodeSupportLevel(msg.getTravelModeState());
    _levData.changedValueMask |= SPEED | SUPPORTLEVEL;

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
    Serial.print(msg.getSpeed() / 10);
    Serial.print(".");
    Serial.println(msg.getSpeed() % 10);
}

void levSpeedDistanceInformationHandler(LevSpeedDistanceInformation& msg, uintptr_t data) {
    _levData.odometer = msg.getOdometer();
    _levData.speed = msg.getSpeed();
    _levData.changedValueMask |= SPEED | ODOMETER;

    Serial.print("Odometer: ");
    Serial.println((float)msg.getOdometer() / 100);
    Serial.print("Remaining range: ");
    Serial.println(msg.getRemainingRange());        // TODO 0 = unknown
    Serial.print("Speed: ");
    Serial.print(msg.getSpeed() / 10);
    Serial.print(".");
    Serial.println(msg.getSpeed() % 10);
}

void levAltSpeedDistanceInformationHandler(LevAltSpeedDistanceInformation& msg, uintptr_t data) {
    _levData.odometer = msg.getOdometer();
    _levData.speed = msg.getSpeed();
    _levData.changedValueMask |= SPEED | ODOMETER;

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
    _levData.batterySOC = msg.getBatterySOC();
    _levData.supportLevel = decodeSupportLevel(msg.getTravelModeState());
    _levData.percentAssist = msg.getPercentAssist();
    _levData.speed = msg.getSpeed();
    _levData.changedValueMask |= BATTERYSOC | SUPPORTLEVEL| PERCENTASSIST| SPEED;

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
    Serial.println(msg.getFuelConsumption());
    Serial.print("Battery voltage: ");
    Serial.println(msg.getBatteryVoltage());
    Serial.print("Distance on current charge: ");
    Serial.println(msg.getDistanceOnCurrentCharge());
}

void levCapabilities(LevCapabilities& msg, uintptr_t data) {
    _levData.wheelCircumference = msg.getWheelCircumference(); // in mm
    _levData.supportLevelCount = 4; // (msg.getTravelModesSupported() >> 3) & 0x07; // 4
    _levData.changedValueMask |= WHEELCIRC | SUPPORTLEVELCNT;

    Serial.print("Travel modes supported: ");
    Serial.println(msg.getTravelModesSupported());
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

void moxyCreateMsgHandler(MuscleOxygenBaseMainDataPageMsg& msg, uintptr_t data)
{
    static uint8_t _eventCnt = 0;
    /*  value mapping
        batterySOC --> CurrentSaturatedHemoglobinPercentage
        supportlevel.percentAssist --> TotalHemoglobinConcentration
    */

    if (_levData.changedValueMask & (BATTERYSOC | SUPPORTLEVEL | PERCENTASSIST)) {
        _levData.changedValueMask &= ~(BATTERYSOC | SUPPORTLEVEL | PERCENTASSIST);
        _eventCnt++;
    }
    msg.setCurrentSaturatedHemoglobinPercentage(_levData.batterySOC * 10 + _eventCnt % 2);                              // in 0.1 % (0 - 100)-- > 0 - 1000
    msg.setTotalHemoglobinConcentration(_levData.supportLevel * 100 + min(99, _levData.percentAssist)); // in 0.01g/dl (0-40) --> 0-4000
    msg.setEventCount(_eventCnt);
    Serial.println("new moxy values--------------");
}

void moxyCreateManufacturerInformationMsg(ManufacturersInformationMsg& msg, uintptr_t data) {
    msg.setHWRevision(0x01);
    msg.setManufacturerId(0x1234);
    msg.setModelNumber(0x0001);
}

void moxyCreateProductInformationMsg(ProductInformationMsg& msg, uintptr_t data) {
    msg.setSerialNumber(0x12345678);
    msg.setSWRevisionMain(0x01);
    msg.setSWRevisionSupplemental(0x00);
}

void shiftCreateMsgHandler(ShiftingBaseMainDataPageMsg& msg, uintptr_t data)
{
    static uint8_t _eventCnt = 0;

    /*  value mapping
        supportLevelCount (3)  --> TotalNumbersGearFront
        10 --> TotalNumbersGearRear
        supportLevel (1-3) --> CurrentGearFront
        percentAssist/10 --> CurrentGearRear
    */

    if (_levData.changedValueMask & (SUPPORTLEVELCNT | SUPPORTLEVEL | PERCENTASSIST)) {
        _levData.changedValueMask &= ~(SUPPORTLEVELCNT | SUPPORTLEVEL | PERCENTASSIST);
        _eventCnt++;
    }
    msg.setTotalNumbersGearFront(3);
    msg.setTotalNumbersGearRear(10);
    msg.setCurrentGearFront(_levData.supportLevel-1);
    msg.setCurrentGearRear(10 - (_levData.percentAssist / 10));
    msg.setEventCount(_eventCnt);
    Serial.println("new shifting values---------------");
}

void shiftCreateManufacturerInformationMsg(ManufacturersInformationMsg& msg, uintptr_t data) {
    msg.setHWRevision(0x01);
    msg.setManufacturerId(0x1234);
    msg.setModelNumber(0x0002);
}

void shiftCreateProductInformationMsg(ProductInformationMsg& msg, uintptr_t data) {
    msg.setSerialNumber(0x12345678);
    msg.setSWRevisionMain(0x01);
    msg.setSWRevisionSupplemental(0x00);
}

uint8_t decodeSupportLevel(uint8_t inValue) {
    const uint8_t slConv[] = {0,1,1,2,2,3,3,4,4}; // specialized: 0,1,3,5
    uint8_t sl = slConv[((inValue >> 3) & 0x07)];
    return sl;
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
