/***********************************
 * AntPlus Native Drive Fe-c Display
 *
 * Finds a nearby Indoor bike trainer
 * And display content sent by it
 *
 * Author Charles-Antoine FOURNEL
 * Updated by Curtis Malainey
 ************************************/
#include <Arduino.h>
#include "ANT.h"
#include "ANTPLUS.h"
#define BAUD_RATE 9600
#define CHANNEL_0 0

const uint8_t NETWORK_KEY[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08}; // get this from thisisant.com

ArduinoSerialAntWithCallbacks ant;
AntPlusRouter router;
ProfileFecDisplay fec;

void fecBaseDataPageHandler(AntRxDataResponse& msg, uintptr_t data);
void manufacturerInformationDataPageHandler(ManufacturersInformation& msg, uintptr_t data);
void productInformationDataPageHandler(ProductInformation& msg, uintptr_t data);
void GeneralDataPageHandler(FecGeneralFeData& msg, uintptr_t data);
void GeneralSettingsDataPageHandler(FecGeneralSettingsPage& msg, uintptr_t data);
void SpecificTrainerDataPageHandler(FecSpecificTrainerData& msg, uintptr_t data);
void FeCapabitiliesDataPageHandler(FecFeCapabilities& msg, uintptr_t data);

void TargetPowerDataPagehandler(FecTargetPowerDataPage& msg, uintptr_t data);
void TrackREsistanceDataPageHandler(FecTrackResistanceDataPage& msg, uintptr_t data);

unsigned long previousMillis = 0;
const unsigned long interval = 4000;
int  TargetPower = 50;
void fecRateFeatures(uint8_t bitfield);
void printStatus(uint8_t status);

void setup() {
    delay(2000);
    Serial1.begin(BAUD_RATE);
    ant.begin(Serial1);
    delay(5000);

    router.setDriver(&ant); // never touch ant again
    router.setAntPlusNetworkKey(NETWORK_KEY);
    router.setProfile(CHANNEL_0, &fec);
    // Delay after initial setup to wait for user to connect on serial

    Serial.begin(BAUD_RATE);
    Serial.println("Running");
    fec.onDataPage(fecBaseDataPageHandler);
    fec.onManufacturersInformation(manufacturerInformationDataPageHandler);
    fec.onProductInformation(productInformationDataPageHandler);
    fec.onFecGeneralFeData(GeneralDataPageHandler);
    //fec.onFecGeneralSettingsDataPage(GeneralSettingsDataPageHandler);
    fec.onFecTargetPowerDataPage(TargetPowerDataPagehandler);
    fec.onFecTrackResistanceDataPage(TrackResistanceDataPageHandler);
    fec.onFecTrainerData(SpecificTrainerDataPageHandler);
    fec.onFecFeCapabilities(FeCapabitiliesDataPageHandler);

    fec.begin();
    // wait for pair to complete
    uint8_t status = fec.waitForPair();
    // print channel status
    Serial.println("===========================");
    printStatus(status);
    Serial.print("Device Number: ");
    Serial.println(fec.getDeviceNumber());
    Serial.print("Transmisison Type: ");
    Serial.println(fec.getTransmissionType());
    Serial.print("settings user information");
    fec.transmitFecUserConfigurationMsg(9000, 3000);
    // get fec capabilities
    // TODO transmit request datapage asking for capabilities
    Serial.print("Ask for capacity"); // this datapage not always sent by indoor bike trainer

}

void loop() {
    router.loop();
    if (ant.getResponse().isError())
    {
        Serial.print("ANT MSG ERROR: ");
        Serial.println(ant.getResponse().getErrorCode());
    }
    unsigned long currentMillis = millis();

    /**
     *
     * Just a quick test to switch target power
     * every **interval**
     *
     */
    if(currentMillis - previousMillis > interval)
    {
      previousMillis = currentMillis;
      if (TargetPower == 100)
      {
        TargetPower = 50;
      }else{
        TargetPower = 100;
      }
      fec.transmitFecTargetPowerMsg(TargetPower);
      Serial.println(TargetPower);
    }
}

void manufacturerInformationDataPageHandler(ManufacturersInformation& msg, uintptr_t data) {
    Serial.print("Manufacturer ID: ");
    Serial.println(msg.getManufacturerID());
    Serial.print("Model Number: ");
    Serial.println(msg.getModelNumber());
    Serial.print("hardware Revision: ");
    Serial.println(msg.getHWRevision());
}

void productInformationDataPageHandler(ProductInformation& msg, uintptr_t data) {
    Serial.print("Software Revision Main: ");
    Serial.println(msg.getSWRevisionMain());
    Serial.print("Software Revision Supplemental: ");
    Serial.println(msg.getSWRevisionSupplemental());
    Serial.print("Serial Number: ");
    Serial.println(msg.getSerialNumber());
}

void GeneralDataPageHandler(FecGeneralFeData& msg, uintptr_t data) {
    uint8_t fe_type = msg.getFeType();
    Serial.print("Equipment type: ");
    switch (fe_type) {
    case ANTPLUS_FEC_DATAPAGE_GENERALFEDATA_FETYPE_GENERAL:
        Serial.println("General");
        break;
    case ANTPLUS_FEC_DATAPAGE_GENERALFEDATA_FETYPE_TREADMILL:
        Serial.println("Treadmill");
        break;
    case ANTPLUS_FEC_DATAPAGE_GENERALFEDATA_FETYPE_ELLIPTICAL:
        Serial.println("Elliptical");
        break;
    case ANTPLUS_FEC_DATAPAGE_GENERALFEDATA_FETYPE_STATIONARYBIKE:
        Serial.println("Stationary Bike");
        break;
    case ANTPLUS_FEC_DATAPAGE_GENERALFEDATA_FETYPE_ROWER:
        Serial.println("Rower");
        break;
    case ANTPLUS_FEC_DATAPAGE_GENERALFEDATA_FETYPE_CLIMBER:
        Serial.println("Climber");
        break;
    case ANTPLUS_FEC_DATAPAGE_GENERALFEDATA_FETYPE_NORDICSKIER:
        Serial.println("Nordic Skier");
        break;
    case ANTPLUS_FEC_DATAPAGE_GENERALFEDATA_FETYPE_TRAINER:
        Serial.println("Trainer");
        break;
    default:
        Serial.println("Unknown");
        break;
    }
    Serial.print("Elapsed time: ");
    Serial.println(msg.getElapsedTime());
    Serial.print("Distance traveled: ");
    Serial.println(msg.getDistanceTraveled());
    Serial.print("Current speed: ");
    uint16_t speed = msg.getSpeed();
    if (speed == ANTPLUS_FEC_DATAPAGE_GENERALFEDATA_SPEED_INVALID) {
        Serial.println("Invalid");
    } else {
        Serial.println(speed);
    }
    Serial.print("Heart Rate: ");
    uint8_t hr = msg.getHeartRate();
    if (hr == ANTPLUS_FEC_DATAPAGE_GENERALFEDATA_HEARTRATE_INVALID) {
        Serial.println("Invalid");
    } else {
        Serial.println(hr);
    }

    printFeState(msg.getFeState());
    printLapToggleBit(msg.getLapToggleBit());
}

void GeneralSettingsDataPageHandler(FecGeneralSettingsPage& msg, uintptr_t data) {
    uint8_t cycle_length = msg.getCycleLength();
    Serial.print("Cycle length: ");
    if (cycle_length == ANTPLUS_FEC_DATAPAGE_GENERALSETTINGSPAGE_CYCLELENGTH_INVALID) {
        Serial.println("Invalid");
    } else {
        Serial.println(cycle_length);
    }
    uint16_t incline = msg.getIncline();
    Serial.print("Incline value: ");
    if (incline == ANTPLUS_FEC_DATAPAGE_GENERALSETTINGSPAGE_INCLINE_INVALID) {
        Serial.println("Invalid");
    } else {
        Serial.println(incline);
    }
    uint8_t resistance = msg.getResistanceLevel();
    Serial.print("Resistance level: ");
    if (resistance == ANTPLUS_FEC_DATAPAGE_GENERALSETTINGSPAGE_RESISTANCELEVEL_INVALID) {
        Serial.println("Invalid");
    } else {
        Serial.println(resistance);
    }
    printFeState(msg.getFeState());
    printLapToggleBit(msg.getLapToggleBit());
}

void printFeState(uint8_t fe_state) {
    Serial.print("FE State:");
    switch (fe_state) {
    case ANTPLUS_FEC_DATAPAGE_FESTATE_RESERVED:
        Serial.println("Reserved");
        break;
    case ANTPLUS_FEC_DATAPAGE_FESTATE_ASLEEP:
        Serial.println("Asleep / Off");
        break;
    case ANTPLUS_FEC_DATAPAGE_FESTATE_READY:
        Serial.println("Ready");
        break;
    case ANTPLUS_FEC_DATAPAGE_FESTATE_INUSE:
        Serial.println("In Use");
        break;
    case ANTPLUS_FEC_DATAPAGE_FESTATE_FINISHED:
        Serial.println("Finished / Paused");
        break;
    default:
        Serial.println("Unknown/Reserved");
        break;
    }
}

void printLapToggleBit(uint8_t bit) {
    Serial.print("Lap Toggle Bit: ");
    Serial.println(bit);
}

void fecBaseDataPageHandler(AntRxDataResponse& msg, uintptr_t data) {
    FecBaseMainDataPage dp = FecBaseMainDataPage(msg);
    Serial.println("===========================");
    Serial.print("DataPage: ");
    Serial.println(dp.getDataPageNumber());
}

void TargetPowerDataPagehandler(FecTargetPowerDataPage& msg, uintptr_t data){
    Serial.print("Target Power: ");
    Serial.println(msg.getTargetPower());
}

void TrackResistanceDataPageHandler(FecTrackResistanceDataPage& msg, uintptr_t data){
    Serial.print("Track Resistance: ");
    Serial.println(msg.getGrade());
}

void SpecificTrainerDataPageHandler(FecSpecificTrainerData& msg, uintptr_t data){
    Serial.print("Update Event Count: ");
    Serial.println(msg.getUpdateEventCount());
    Serial.print("Instantaneous Cadence: ");
    uint8_t cadence = msg.getInstantaneousCadence();
    if (cadence == ANTPLUS_FEC_DATAPAGE_SPECIFICTRAINERDATA_INSTANTANEOUSCADENCE_INVALID) {
        Serial.println("Invalid");
    } else {
        Serial.println(cadence);
    }
    uint16_t power = msg.getInstantaneousPower();
    if (power == ANTPLUS_FEC_DATAPAGE_SPECIFICTRAINERDATA_INSTANTANEOUSPOWER_INVALID) {
        Serial.println("Accumulated Power: Invalid");
        Serial.println("Instantaneous Power: Invalid");
    } else {
        Serial.println("Accumulated Power: ");
        Serial.print(msg.getAccumulatedPower());
        Serial.println("Instantaneous Power: ");
        Serial.print(power);
    }
    Serial.print("Bicycle Power Calibration: ");
    if (msg.getBicyclePowerCalibration())
    {
        Serial.println("Required");
    } else {
        Serial.println("Complete/Not Required");
    }
    Serial.print("Resistance Calibration: ");
    if (msg.getResistanceCalibration())
    {
        Serial.println("Required");
    } else {
        Serial.println("Complete/Not Required");
    }
    Serial.print("User Configuration: ");
    if (msg.getUserConfiguration())
    {
        Serial.println("Required");
        fec.transmitFecUserConfigurationMsg(9000, 3000);
    } else {
        Serial.println("Complete/Not Required");
    }
    Serial.print("Target Power Limits: ");
    uint8_t limit = msg.getTargetPowerLimits();
    switch(limit) {
    case ANTPLUS_FEC_DATAPAGE_SPECIFICTRAINERDATA_TARGETPOWERLIMITS_ATTARGET:
        Serial.println("Trainer at target power");
        break;
    case ANTPLUS_FEC_DATAPAGE_SPECIFICTRAINERDATA_TARGETPOWERLIMITS_SPEEDTOOLOW:
        Serial.println("User cycling speed is too low");
        break;
    case ANTPLUS_FEC_DATAPAGE_SPECIFICTRAINERDATA_TARGETPOWERLIMITS_SPEEDTOOHIGH:
        Serial.println("User cycling speed is too high");
        break;
    case ANTPLUS_FEC_DATAPAGE_SPECIFICTRAINERDATA_TARGETPOWERLIMITS_UNDERTERMINED:
        Serial.println("Undetermined");
        break;
    }
    printFeState(msg.getFeState());
    printLapToggleBit(msg.getLapToggleBit());
}

void FeCapabitiliesDataPageHandler(FecFeCapabilities& msg, uintptr_t data) {
    Serial.print("Max resistance: ");
    Serial.println(msg.getMaximumResistance());
    Serial.print("Fec Capabilities: ");
    Serial.print("  Supports Basic Resistance Mode: ");
    Serial.println(msg.getBasicResistanceModeSupport() ? "Y" : "N");
    Serial.print("  Supports Target Power Mode: ");
    Serial.println(msg.getTargetPowerModeSupport() ? "Y" : "N");
    Serial.print("  Supports Sumulation Mode: ");
    Serial.println(msg.getSimulationModeSupport() ? "Y" : "N");
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
