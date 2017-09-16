/***********************************
 * AntPlus HRMonitor example
 *
 * Finds a nearby HR sensor, pairs
 * to it and then reads the information
 * out via the serial port.
 *
 * TODO this example is incomplete
 *
 * Author Curtis Malainey
 ************************************/
#include <Arduino.h>
#include "ANT.h"
#include "ANTPLUS.h"

#define BAUD_RATE 9600
#define WILDCARD_DEVICE 0
#define CHANNEL_0 0

const uint8_t NETWORK_KEY[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77}; // get this from thisisant.com

AntWithCallbacks ant = AntWithCallbacks();
AntPlusRouter router = AntRouter();
ProfileHRMonitor hr = ProfileHRMonitor(WILDCARD_DEVICE);

void setup() {
    Serial1.begin(BAUD_RATE);
    ant.setSerial(Serial1);
    router.setDriver(ant);
    router.setAntPlusNetworkKey(NETWORK_KEY);
    router.setProfile(CHANNEL_0, hr);
    // Delay after initial setup to wait for user to connect on serial
    delay(10000);
    Serial.begin(BAUD_RATE);
    Serial.println("Running");
    hr.pair();
    // wait for pair to complete
    while(hr.getStatus() == CHANNEL_STATUS_SEARCHING) {router.loop()};
    // print channel status
    // get sensor serial number
}

void loop() {
    router.loop();
}

// add profile callbacks here