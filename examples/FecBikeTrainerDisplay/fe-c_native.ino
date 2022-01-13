/***********************************
 * AntPlus Native Drive Fe-c Display
 *
 * Finds a nearby Indoor bike trainer
 * And display content sent by it
 *
 * Author Charles-Antoine FOURNEL
 ************************************/
#include <Arduino.h>
#include "ANT.h"
#include "ANTPLUS.h"
#include "bluefruit.h"
#define BAUD_RATE 115200
#define CHANNEL_0 0
#define TOTAL_CHANNELS 1
#define ENCRYPTED_CHANNELS 0

const uint8_t NETWORK_KEY[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08}; // get this from thisisant.com

ArduinoNativeAntWithCallbacks ant;
AntPlusRouter router = AntPlusRouter();
ProfileFecDisplay ht = ProfileFecDisplay();

void fecBaseDataPageHandler(AntRxDataResponse& msg, uintptr_t data);
void batteryStatusDataPageHandler(HeartRateBatteryStatus& msg, uintptr_t data);
void capabilitiesDataPageHandler(HeartRateCapabilities& msg, uintptr_t data);
void cumulativeOperatingTimeDataPageHandler(HeartRateCumulativeOperatingTime& msg, uintptr_t data);
void defaultDataPageHandler(HeartRateDefault& msg, uintptr_t data);
void manufacturerInformationDataPageHandler(FecManufacturerInformation& msg, uintptr_t data);
void productInformationDataPageHandler(FecProductInformation& msg, uintptr_t data);
void GeneralDataPageHandler(FecGeneralMainDataPage& msg, uintptr_t data);
void GeneralSettingsDataPageHandler(FecGeneralSettingsDataPage& msg, uintptr_t data);
void SpecificTrainerDataPageHandler(FecSpecificTrainerData& msg, uintptr_t data);
void CapabitiliesDataPageHandler(FecCapabilitiesInformationDatapage& msg, uintptr_t data);

void TargetPowerDataPagehandler(FecTargetPowerDataPage& msg, uintptr_t data);
void TrackREsistanceDataPageHandler(FecTrackResistanceDataPage& msg, uintptr_t data);

long previousMillis = 0; 
long interval = 4000;  
int  TargetPower = 50;
void fecRateFeatures(uint8_t bitfield);
void printStatus(uint8_t status);

void setup() {
    delay(2000);
    Bluefruit.begin() ;
    Serial1.begin(BAUD_RATE);
    ant.begin(TOTAL_CHANNELS, ENCRYPTED_CHANNELS);
    delay(5000);

    router.setDriver(&ant); // never touch ant again
    router.setAntPlusNetworkKey(NETWORK_KEY);
    router.setProfile(CHANNEL_0, &ht);
    // Delay after initial setup to wait for user to connect on serial

    Serial.begin(BAUD_RATE);
    Serial.println("Running");
    ht.onDataPage(fecBaseDataPageHandler);
    //ht.onFecManufacturerInformation(manufacturerInformationDataPageHandler);
    //ht.onFecProductInformation(ProductInformationDataPageHandler);
    ht.onFecGeneralDataPage(GeneralDataPageHandler);
    //ht.onFecGeneralSettingsDataPage(GeneralSettingsDataPageHandler);
    ht.onFecTargetPowerDataPage(TargetPowerDataPagehandler);
    ht.onFecTrackResistanceDataPage(TrackResistanceDataPageHandler);
    ht.onFecTrainerData(SpecificTrainerDataPageHandler);
    ht.onFecCapabilitiesInformationDataPage(CapabitiliesDataPageHandler);

    ht.begin();
    // wait for pair to complete
    uint8_t status = ht.waitForPair();
    // print channel status
    Serial.println("===========================");
    printStatus(status);
    Serial.print("Device Number: ");
    Serial.println(ht.getDeviceNumber());
    Serial.print("Transmisison Type: ");
    Serial.println(ht.getTransmissionType());
    Serial.print("settings user information");
    ht.transmitFecUserInformationMsg(9000, 3000);
    // get fec capabilities
    ht.transmitFecCapabitiliesRequestMsg();
    Serial.print("Ask for capacity"); // this datapage not always sent by indoor bike trainer

}

void loop() {
    router.loop();
    ant.readPacket();
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
      // save the last time you blinked the LED 
      previousMillis = currentMillis;   
      //Serial.println("Envoi de la puissance vise");
      if ( TargetPower == 100 )
      {
        TargetPower = 50;
      }else{
        TargetPower = 100;
      }
      ht.transmitFecTargetPowerMsg(TargetPower);
      Serial.println(TargetPower);
    }
}


void manufacturerInformationDataPageHandler(FecManufacturerInformation& msg, uintptr_t data) {
    Serial.print("Manufacturer ID: ");
    Serial.println(msg.getManufacturerId());
    Serial.print("Model Number: ");
    Serial.println(msg.getModelNumber());
    Serial.print("hardware Revision: ");
    Serial.println(msg.getHardwareRevision());
}

void ProductInformationDataPageHandler(FecProductInformation& msg, uintptr_t data) {
    Serial.print("Software Revision: ");
    Serial.println(msg.getSoftwareRevision());
}

void GeneralDataPageHandler(FecGeneralMainDataPage& msg, uintptr_t data) {
    Serial.print("Equipment type: ");
    Serial.println(msg.getEquipmentTypeBits());
    Serial.print("Current speed:" );
    Serial.println(msg.getSpeed(true));
    Serial.print("FE State:");
    Serial.println(msg.getFEStateBits());
    Serial.print("FEC CAPABILITIES:");
    Serial.println(msg.getCapabilitiesBits());
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
      ht.transmitFecUserInformationMsg(9000, 3000);
      Serial.println("Envoi des informations utilisateurs :");
    }
    Serial.print("Trainer flag bit: ");
    Serial.println(msg.getFlagsBits());
}

void CapabitiliesDataPageHandler(FecCapabilitiesInformationDatapage& msg, uintptr_t data)
{
    Serial.print("Max resistance: ");
    Serial.println(msg.getMaximumResistance());
    Serial.print("Fec Capabilities: ");
    Serial.println(msg.getCapabilities());  
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
