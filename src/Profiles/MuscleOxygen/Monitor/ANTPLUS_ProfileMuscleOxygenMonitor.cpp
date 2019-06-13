#include <Profiles/MuscleOxygen/Monitor/ANTPLUS_ProfileMuscleOxygenMonitor.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>


ProfileMuscleOxygenMonitor::ProfileMuscleOxygenMonitor(	uint16_t deviceNumber, uint8_t transmissionType) :
    BaseMasterProfile(deviceNumber, transmissionType),
    _patternStep(0),
    _toggle(0),
    _eventCount(0)

{
    setChannelConfig();
}

void ProfileMuscleOxygenMonitor::setChannelConfig() {
    setChannelType(ANTPLUS_MUSCLEOXYGEN_MASTER_CHANNELTYPE);
    setDeviceType(ANTPLUS_MUSCLEOXYGEN_DEVICETYPE);
    setChannelPeriod(ANTPLUS_MUSCLEOXYGEN_CHANNELPERIOD);
    setSearchTimeout(ANTPLUS_MUSCLEOXYGEN_SEARCHTIMEOUT);
}

void ProfileMuscleOxygenMonitor::transmitNextDataPage() {
    // some static aux messages
    const uint8_t manufacturer[]  = { 0x50, 0xFF, 0xFF, 0x01, 0x0F, 0x00, 0x85, 0x83 };
    const uint8_t product[]       = { 0x51, 0xFF, 0xFF, 0x01, 0x01, 0x00, 0x00, 0x00 };

    if (_patternStep++ < 64) {
        transmitMuscleOxygenMainPageMsg();
    }
    else {
        MuscleOxygenBaseGenericMsg msg;
        if (_toggle++ % 1 == 0)
            msg.copyData((uint8_t*)manufacturer, MESSAGE_SIZE);
        else
            msg.copyData((uint8_t*)product, MESSAGE_SIZE);
        send(msg);
        _patternStep = 0;

        // debug
        /*
        for (int i = 0; i < msg.getDataLength(); i++) {
            Serial.print(msg.getData(i), HEX); Serial.print(" ");
        }
        Serial.println("");*/
    }
}

void ProfileMuscleOxygenMonitor::transmitMuscleOxygenMainPageMsg() {
    MuscleOxygenBaseMainDataPageMsg msg;
    msg.setEventCount( _eventCount );
    if( _patternStep % 4 == 0 )
      _eventCount++;
    _createMuscleOxygenDataMsg.call(msg);
    send(msg);
}

