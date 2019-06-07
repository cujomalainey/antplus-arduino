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
void levSpeedSysinfo1Handler(LevSpeedSysinfo1& msg, uintptr_t data);
void levSpeedDist1Handler(LevSpeedDist1& msg, uintptr_t data);
void levSpeedDist2Handler(LevSpeedDist2& msg, uintptr_t data);
void levSpeedSysinfo2Handler(LevSpeedSysinfo2& msg, uintptr_t data);
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
	lev.onLevSpeedSysinfo1(levSpeedSysinfo1Handler);
	lev.onLevSpeedDist1(levSpeedDist1Handler);
	lev.onLevSpeedDist2(levSpeedDist2Handler);
	lev.onLevSpeedSysinfo2(levSpeedSysinfo2Handler);
	lev.onLevBatteryInfo(levBatteryInfo);
	lev.onLevCaps(levCaps);
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

	// debug
	int l = msg.getDataLength();
	uint8_t * buf = msg.getData();
	for (int i = 0; i < l; i++)
	{
		Serial.print(buf[i], HEX); Serial.print(" ");
	}
	Serial.println("");
}

void levSpeedSysinfo1Handler(LevSpeedSysinfo1& msg, uintptr_t data) {
	Serial.print("Temp state: ");
	Serial.println(msg.getTempState());
	Serial.print("Travel mode state: ");
	Serial.println(msg.getTravelModeState());
	Serial.print("System state: ");
	Serial.println(msg.getSystemState());
	Serial.print("Gear state: ");
	Serial.println(msg.getGearState());
	Serial.print("Gear error: ");
	Serial.println(msg.getError());
	Serial.print("Speed: ");
	Serial.print(msg.getSpeed()/10);
	Serial.print(".");
	Serial.println(msg.getSpeed() % 10);
}

void levSpeedDist1Handler(LevSpeedDist1& msg, uintptr_t data) {
	Serial.print("Total dist: ");
	Serial.println((float)msg.getTotalDist() / 100);
	Serial.print("Remaining range: ");
	Serial.println(msg.getRemainingRange());
	Serial.print("Speed: ");
	Serial.print(msg.getSpeed() / 10);
	Serial.print(".");
	Serial.println(msg.getSpeed() % 10);
}

void levSpeedDist2Handler(LevSpeedDist2& msg, uintptr_t data) {
	Serial.print("Total dist: ");
	Serial.println((float)msg.getTotalDist() / 100);
	Serial.print("Fuel consumption: ");
	Serial.println(msg.getFuelConsumption());
	Serial.print("Speed: ");
	Serial.print(msg.getSpeed() / 10);
	Serial.print(".");
	Serial.println(msg.getSpeed() % 10);
}

void levSpeedSysinfo2Handler(LevSpeedSysinfo2& msg, uintptr_t data) {
	Serial.print("Battery SOC: ");
	Serial.println(msg.getBatterySOC());
	Serial.print("Travel mode state: ");
	Serial.println(msg.getTravelModeState());
	Serial.print("System state: ");
	Serial.println(msg.getSystemState());
	Serial.print("Gear state: ");
	Serial.println(msg.getGearState());
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

void levCaps(LevCaps& msg, uintptr_t data) {
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

