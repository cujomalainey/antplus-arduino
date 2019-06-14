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

const uint8_t NETWORK_KEY[] = { 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77 };

AntWithCallbacks ant = AntWithCallbacks();
AntPlusRouter router = AntPlusRouter();
ProfileShiftingShifter shift = ProfileShiftingShifter( 7370 );

void shiftCreateMsgHandler(ShiftingBaseMainDataPageMsg& msg, uintptr_t data);

void setup() {
    Serial2.begin(BAUD_RATE);
    ant.setSerial(Serial2);
    delay(1000);

    router.setDriver(&ant); // never touch ant again
    router.setAntPlusNetworkKey(NETWORK_KEY);
    router.setProfile(CHANNEL_0, &shift);

    Serial.begin(BAUD_RATE);
    Serial.println("Running");

    // setup shifting monitor
    shift.createShiftingDataMsg(shiftCreateMsgHandler);
    shift.begin();
    delay(100); // wait for module initialization
}

void loop() {
    router.loop();
}

void shiftCreateMsgHandler(ShiftingBaseMainDataPageMsg& msg, uintptr_t data)
{
    static int _gear = 0;
    static int _eventCount = 0;
    msg.setTotalNumbersGearFront(1);
    msg.setTotalNumbersGearRear(10);

    msg.setCurrentGearFront( 1 );
    msg.setCurrentGearRear( _gear++ % 10 );
    msg.setEventCount(_eventCount);
}

