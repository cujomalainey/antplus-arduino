/**********************************************
 * AntPlus muscle oxygen monitor example
 *
 * Deliver data of a muscle oxygen sensor
 * to a display via serial port
 *
 * Author Bernd Woköck
 *        based on the work of Curtis Malainey
 **********************************************/
#include <Arduino.h>
#include "ANT.h"
#include "ANTPLUS.h"

#define BAUD_RATE 9600
#define CHANNEL_1 0

const uint8_t NETWORK_KEY[] = { 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77 };

AntWithCallbacks ant = AntWithCallbacks();
AntPlusRouter router = AntPlusRouter();
ProfileMuscleOxygenMonitor moxy = ProfileMuscleOxygenMonitor( 7369 );

void moxyCreateMsgHandler(MuscleOxygenBaseMainDataPageMsg& msg, uintptr_t data);

void setup() {
    Serial2.begin(BAUD_RATE);
    ant.setSerial(Serial2);
    delay(1000);

    router.setDriver(&ant); // never touch ant again
    router.setAntPlusNetworkKey(NETWORK_KEY);
    router.setProfile(CHANNEL_1, &moxy);
    // Delay after initial setup to wait for user to connect on serial

    Serial.begin(BAUD_RATE);
    Serial.println("Running");

    // setup muscle oxygen monitor
    moxy.createMuscleOxygenDataMsg(moxyCreateMsgHandler);
    moxy.begin();
}

void loop() {
    router.loop();
}

void moxyCreateMsgHandler(MuscleOxygenBaseMainDataPageMsg& msg, uintptr_t data)
{
    const int lo = 500, hi = 2500;
    static uint16_t c = lo;

    // fake data 
    msg.setTotalHemoglobinConcentration(c);
    msg.setCurrentSaturatedHemoglobinPercentage(c++/4);

    if (c > hi)
        c = lo;
}
