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
void GeneralDataPageHandler(FecGeneralMainDataPage& msg, uintptr_t data);
void GeneralSettingsDataPageHandler(FecGeneralSettingsDataPage& msg, uintptr_t data);
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
    fec.onFecGeneralDataPage(GeneralDataPageHandler);
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

void GeneralDataPageHandler(FecGeneralMainDataPage& msg, uintptr_t data) {
    uint8_t equipment_type = msg.getEquipmentTypeBits();
    Serial.print("Equipment type: ");
    switch (equipment_type) {
    case ANTPLUS_FEC_DATAPAGE_GENERALFEDATA_EQUIPMENTTYPEBITFIELD_GENERAL:
        Serial.println("General");
        break;
    case ANTPLUS_FEC_DATAPAGE_GENERALFEDATA_EQUIPMENTTYPEBITFIELD_TREADMILL:
        Serial.println("Treadmill");
        break;
    case ANTPLUS_FEC_DATAPAGE_GENERALFEDATA_EQUIPMENTTYPEBITFIELD_ELLIPTICAL:
        Serial.println("Elliptical");
        break;
    case ANTPLUS_FEC_DATAPAGE_GENERALFEDATA_EQUIPMENTTYPEBITFIELD_STATIONARYBIKE:
        Serial.println("Stationary Bike");
        break;
    case ANTPLUS_FEC_DATAPAGE_GENERALFEDATA_EQUIPMENTTYPEBITFIELD_ROWER:
        Serial.println("Rower");
        break;
    case ANTPLUS_FEC_DATAPAGE_GENERALFEDATA_EQUIPMENTTYPEBITFIELD_CLIMBER:
        Serial.println("Climber");
        break;
    case ANTPLUS_FEC_DATAPAGE_GENERALFEDATA_EQUIPMENTTYPEBITFIELD_NORDICSKIER:
        Serial.println("Nordic Skier");
        break;
    case ANTPLUS_FEC_DATAPAGE_GENERALFEDATA_EQUIPMENTTYPEBITFIELD_TRAINER:
        Serial.println("Trainer");
        break;
    default:
        Serial.println("Unknown");
        break;
    }
    Serial.print("Current speed:" );
    Serial.println(msg.getSpeed());
    Serial.print("FE State:");
    Serial.println(msg.getFEStateBits());
    Serial.println("Fec Capabilities:");
    // TODO
}

void GeneralSettingsDataPageHandler(FecGeneralSettingsDataPage& msg, uintptr_t data) {
    Serial.print("Cycle length: ");
    Serial.println(msg.getCycleLength());
    Serial.print("Incline value:" );
    Serial.println(msg.getInclineValue());
    Serial.print("Resistance level:");
    Serial.println(msg.getResistanceLevel());
}


void fecBaseDataPageHandler(AntRxDataResponse& msg, uintptr_t data) {
    FecBaseMainDataPage dp = FecBaseMainDataPage(msg);
    Serial.println("===========================");
    Serial.print("DataPage: ");
    Serial.println(dp.getDataPageNumber());
}

void TargetPowerDataPagehandler(FecTargetPowerDataPage& msg, uintptr_t data){
    Serial.print("Target POWER: ");
    Serial.println(msg.getTargetPower());
}

void TrackResistanceDataPageHandler(FecTrackResistanceDataPage& msg, uintptr_t data){
    Serial.print("Track Resistance: ");
    Serial.println(msg.getGrade());
}

void SpecificTrainerDataPageHandler(FecSpecificTrainerData& msg, uintptr_t data){
    Serial.print("Trainer status: ");
    Serial.println(msg.getTrainerStatusBits());
    if ( msg.getTrainerStatusBits() == 4 )
    {
      fec.transmitFecUserConfigurationMsg(9000, 3000);
      Serial.println("Envoi des informations utilisateurs :");
    }
    Serial.print("Trainer flag bit: ");
    Serial.println(msg.getFlagsBits());
}

void FeCapabitiliesDataPageHandler(FecFeCapabilities& msg, uintptr_t data) {
    uint8_t bits = msg.getCapabilitiesBitField();
    Serial.print("Max resistance: ");
    Serial.println(msg.getMaximumResistance());
    Serial.print("Fec Capabilities: ");
    Serial.print("  Supports Basic Resistance Mode: ");
    Serial.println(bits & ANTPLUS_FEC_DATAPAGE_FECAPABILITIES_CAPABILITIESBITFIELD_SUPPORTSBASICRESISTANCEMODE ? "Y" : "N");
    Serial.print("  Supports Target Power Mode: ");
    Serial.println(bits & ANTPLUS_FEC_DATAPAGE_FECAPABILITIES_CAPABILITIESBITFIELD_SUPPORTSTARGETPOWERMODE ? "Y" : "N");
    Serial.print("  Supports Sumulation Mode: ");
    Serial.println(bits & ANTPLUS_FEC_DATAPAGE_FECAPABILITIES_CAPABILITIESBITFIELD_SUPPORTSSIMULATIONMODE ? "Y" : "N");
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
