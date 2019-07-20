/**********************************************
 * AntPlus LEV Display example
 *
 * Finds a nearby LEV Device, pairs
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
void printTemperatureState(uint8_t temperatureState);
void printTemperatureAlert(uint8_t alertState);
void printTravelModeLevel(uint8_t level);
void printSystemState(uint8_t state);
void printGearState(uint8_t state);
void printCommonSpeedSystemInformation(LevBaseSpeedSystemInformation& msg);
void printCommonSpeedDistanceInformation(LevBaseSpeedDistanceInformation& msg);

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
    uint8_t errorCode;
    Serial.print("Battery Temperature State: ");
    printTemperatureState(msg.getBatteryTemperatureState());
    Serial.print("Battery Temperature Alert: ");
    printTemperatureAlert(msg.getBatteryTemperatureAlert());
    Serial.print("Motor Temperature State: ");
    printTemperatureState(msg.getMotorTemperatureState());
    Serial.print("Motor Temperature Alert: ");
    printTemperatureAlert(msg.getMotorTemperatureAlert());
    Serial.print("Gear error: ");
    errorCode = msg.getErrorMessage();
    switch (errorCode) {
    case ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION1_ERRORMESSAGE_NOERROR:
        Serial.println("No Error");
        break;
    case ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION1_ERRORMESSAGE_BATTERYERROR:
        Serial.println("Battery Error");
        break;
    case ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION1_ERRORMESSAGE_DRIVETRAINERROR:
        Serial.println("Drive Train Error");
        break;
    case ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION1_ERRORMESSAGE_BATTERYENDOFLIFE:
        Serial.println("Battery End of Life");
        break;
    case ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION1_ERRORMESSAGE_OVERHEATING:
        Serial.println("Overheating");
        break;
    case ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION1_ERRORMESSAGE_MANUFACTURERSPECIFIC ... UINT8_MAX:
        Serial.print("Manufacture Specfic: ");
        Serial.print(errorCode);
        break;
    }
    printCommonSpeedSystemInformation(msg);
}

void levSpeedDistanceInformationHandler(LevSpeedDistanceInformation& msg, uintptr_t data) {
    uint16_t remaining = msg.getRemainingRange();
    Serial.print("Remaining range: ");
    if (remaining ==  ANTPLUS_LEV_DATAPAGE_SPEEDDISTANCEINFORMATION_REMAININGRANGE_UNKNOWN) {
        Serial.println("Unknown");
    } else {
        Serial.println(remaining);
    }

    printCommonSpeedDistanceInformation(msg);
}

void levAltSpeedDistanceInformationHandler(LevAltSpeedDistanceInformation& msg, uintptr_t data) {
    uint16_t consumption = msg.getFuelConsumption();
    Serial.print("Fuel consumption: ");
    if (consumption == ANTPLUS_LEV_DATAPAGE_ALTSPEEDDISTANCEINFORMATION_FUELCONSUMPTION_UNKNOWN) {
        Serial.println("Unknown");
    } else {
        Serial.println(consumption);
    }
    printCommonSpeedDistanceInformation(msg);
}

void levSpeedSystemInformation2Handler(LevSpeedSystemInformation2& msg, uintptr_t data) {
    Serial.print("Battery SOC: ");
    Serial.println(msg.getBatterySOC());
    Serial.print("Battery Empty Warning: ");
    Serial.println(msg.getBatteryEmptyWarning());
    Serial.print("Percent Assist: ");
    if (msg.getPercentAssist() == ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION2_PERCENTASSIST_UNKNOWN) {
        Serial.println("Unknown");
    } else {
        Serial.println(msg.getBatteryEmptyWarning());
    }
    printCommonSpeedSystemInformation(msg);
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
    uint16_t circumference;
    uint8_t getNumberOfRegenerativeModesSupported();
    Serial.print("Number Of Assist Modes Supported: ");
    Serial.println(msg.getNumberOfAssistModesSupported());
    Serial.print("Number Of Regenerative Modes Supported: ");
    Serial.println(msg.getNumberOfAssistModesSupported());
    Serial.print("Wheel circumference: ");
    circumference = msg.getWheelCircumference();
    if (circumference == ANTPLUS_LEV_DATAPAGE_LEVCAPABILITIES_WHEELCIRCUMFERENCE_UNKOWN) {
        Serial.println("Unknown");
    } else {
        Serial.println(circumference);
    }
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

void printTemperatureState(uint8_t temperatureState) {
    switch (temperatureState) {
    case ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION1_TEMPERATURESTATE_STATE_UNKNOWN:
        Serial.println("Unknown");
        break;
    case ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION1_TEMPERATURESTATE_STATE_COLD:
        Serial.println("Cold");
        break;
    case ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION1_TEMPERATURESTATE_STATE_COLDWARM:
        Serial.println("Cold/Warm");
        break;
    case ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION1_TEMPERATURESTATE_STATE_WARM:
        Serial.println("Warm");
        break;
    case ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION1_TEMPERATURESTATE_STATE_WARMHOT:
        Serial.println("Warm/Hot");
        break;
    case ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION1_TEMPERATURESTATE_STATE_HOT:
        Serial.println("Hot");
        break;
    }
}

void printTemperatureAlert(uint8_t alertState) {
    if (alertState == ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION1_TEMPERATURESTATE_ALERT_NOALERT) {
        Serial.println("No Alert");
    } else if (alertState == ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION1_TEMPERATURESTATE_ALERT_OVERHEATALERT) {
        Serial.println("Overheat Alert!");
    }
}

void printCommonSpeedSystemInformation(LevBaseSpeedSystemInformation& msg) {
    Serial.print("Current Regenerative Level: ");
    printTravelModeLevel(msg.getCurrentRegenerativeLevel());
    Serial.print("Current Assist Level: ");
    printTravelModeLevel(msg.getCurrentAssistLevel());
    Serial.print("System state: ");
    printSystemState(msg.getSystemState());
    Serial.print("Current Front Gear: ");
    printGearState(msg.getCurrentFrontGear());
    Serial.print("Current Rear Gear: ");
    printGearState(msg.getCurrentRearGear());
    Serial.print("Manual/Auto: ");
    if (msg.getManualAutoState() == ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION1_GEARSTATE_MANUALAUTOSTATE_AUTOMATIC) {
        Serial.println("Automatic/Gear not available");
    } else {
        Serial.println("Manual");
    }
    Serial.print("Gear Exist: ");
    if (msg.getGearExist() == ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION1_GEARSTATE_GEAREXIST_AVAILABLE) {
        Serial.println("Gear is available");
    } else {
        Serial.println("Gear is not available");
    }
    Serial.print("Speed: ");
    Serial.print(msg.getSpeed()/10);
    Serial.print(".");
    Serial.println(msg.getSpeed() % 10);
}

void printCommonSpeedDistanceInformation(LevBaseSpeedDistanceInformation& msg) {
    Serial.print("Odometer: ");
    Serial.println((float)msg.getOdometer() / 100);
    Serial.print("Lev speed: ");
    Serial.print(msg.getLevSpeed() / 10);
    Serial.print(".");
    Serial.println(msg.getLevSpeed() % 10);
}

void printTravelModeLevel(uint8_t level) {
    if(level == ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION1_TRAVELMODESTATE_OFF) {
        Serial.println("Off");
    } else {
        Serial.println(level);
    }
}

void printSystemState(uint8_t state) {
    Serial.print("Right Turn Signal: ");
    if (state & ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION1_SYSTEMSTATE_TURNSIGNALRIGHT) {
        Serial.println("Blinking");
    } else {
        Serial.println("Off/Unsupported");
    }
    Serial.print("Left Turn Signal: ");
    if (state & ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION1_SYSTEMSTATE_TURNSIGNALLEFT) {
        Serial.println("Blinking");
    } else {
        Serial.println("Off/Unsupported");
    }
    Serial.print("Light Beam: ");
    if (state & ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION1_SYSTEMSTATE_LIGHTBEAM) {
        Serial.println("High Beam");
    } else {
        Serial.println("Low Beam/Unsupported");
    }
    Serial.print("Light On/Off: ");
    if (state & ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION1_SYSTEMSTATE_LIGHTONOFF) {
        Serial.println("On");
    } else {
        Serial.println("Off/Unsupported");
    }
    Serial.print("  Manual Throttle: ");
    if (state & ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION1_SYSTEMSTATE_MANUALTHROTTLE) {
        Serial.println("On");
    } else {
        Serial.println("Off/Unsupported");
    }
}

void printGearState(uint8_t state) {
    if (state == ANTPLUS_LEV_DATAPAGE_SPEEDSYSTEMINFORMATION1_GEARSTATE_CURRENTGEAR_NOGEAR) {
        Serial.println("No gear available");
    } else {
        Serial.println(state);
    }
}
