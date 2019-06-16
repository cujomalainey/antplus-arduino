#include <Profiles/MuscleOxygen/Monitor/ANTPLUS_ProfileMuscleOxygenMonitor.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>


ProfileMuscleOxygenMonitor::ProfileMuscleOxygenMonitor(	uint16_t deviceNumber, uint8_t transmissionType) :
    BaseMasterProfile(deviceNumber, transmissionType),
    _patternStep(0),
    _toggle(0)
{
    setChannelConfig();
}

void ProfileMuscleOxygenMonitor::setChannelConfig() {
    setChannelType(ANTPLUS_MUSCLEOXYGEN_MONITOR_CHANNELTYPE);
    setDeviceType(ANTPLUS_MUSCLEOXYGEN_DEVICETYPE);
    setChannelPeriod(ANTPLUS_MUSCLEOXYGEN_CHANNELPERIOD);
    setSearchTimeout(ANTPLUS_MUSCLEOXYGEN_SEARCHTIMEOUT);
}

bool ProfileMuscleOxygenMonitor::isDataPageValid(uint8_t dataPage) {
    switch (dataPage) {
    case ANTPLUS_MUSCLEOXYGEN_DATAPAGE_MUSCLEOXYGENDATA_NUMBER:
        return true;
    // TODO other datapages
    }
    return false;
}

void ProfileMuscleOxygenMonitor::transmitNextDataPage() {
    // some static aux messages
    const uint8_t manufacturer[]  = { 0x50, 0xFF, 0xFF, 0x01, 0x0F, 0x00, 0x85, 0x83 };
    const uint8_t product[]       = { 0x51, 0xFF, 0xFF, 0x01, 0x01, 0x00, 0x00, 0x00 };

    if (_patternStep++ < 64) {
        transmitMuscleOxygenMainPageMsg();
    }
    else {
        MuscleOxygenBaseMainDataPageMsg msg;
        if (_toggle++ % 2 == 0)
			memcpy(msg.getDataBuffer(), manufacturer, MESSAGE_SIZE);
        else
			memcpy(msg.getDataBuffer(), product, MESSAGE_SIZE);
        send(msg);
        _patternStep = 0;
    }
}

void ProfileMuscleOxygenMonitor::transmitMuscleOxygenMainPageMsg() {
    MuscleOxygenBaseMainDataPageMsg msg;
    _createMuscleOxygenDataMsg.call(msg);
    send(msg);
}

