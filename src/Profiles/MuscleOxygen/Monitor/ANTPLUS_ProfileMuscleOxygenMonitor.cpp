#include <Profiles/MuscleOxygen/Monitor/ANTPLUS_ProfileMuscleOxygenMonitor.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

#define MONITOR_CHANNELTYPE CHANNEL_TYPE_BIDIRECTIONAL_TRANSMIT
#define MONITOR_TRANSMISSIONTYPE (TRANSMISSION_TYPE_INDEPENDENT | TRANSMISSION_TYPE_GLOBALDATAPGESUSED)

ProfileMuscleOxygenMonitor::ProfileMuscleOxygenMonitor(	uint16_t deviceNumber, uint8_t transmissionType, uint32_t flags) :
    BaseMasterProfile(deviceNumber,
            ANTPLUS_TRANSMISSION_SET_LSN(
                transmissionType, MONITOR_TRANSMISSIONTYPE))
{
    setChannelConfig();
    // change the background cycle loop size
    _backgroundStepSize = 2 + (flags & ANTPLUS_MUSCLEOXYGEN_FLAGS_BATTERYSTATUS_SUPPORTED ? 1 : 0);
}

void ProfileMuscleOxygenMonitor::setChannelConfig() {
    setChannelType(MONITOR_CHANNELTYPE);
    setDeviceType(ANTPLUS_MUSCLEOXYGEN_DEVICETYPE);
    setChannelPeriod(MUSCLEOXYGEN_CHANNELPERIOD);
    setSearchTimeout(MUSCLEOXYGEN_SEARCHTIMEOUT);
}

bool ProfileMuscleOxygenMonitor::isDataPageValid(uint8_t dataPage) {
    switch (dataPage) {
    case MUSCLEOXYGEN_MUSCLEOXYGENDATA_NUMBER:
    case COMMON_PRODUCTINFORMATION_NUMBER:
    case COMMON_MANUFACTURERSINFORMATION_NUMBER:
        return true;
    case COMMON_BATTERYSTATUS_NUMBER:
        return _flags & ANTPLUS_MUSCLEOXYGEN_FLAGS_BATTERYSTATUS_SUPPORTED;
    }
    return false;
}

void ProfileMuscleOxygenMonitor::transmitNextDataPage() {
    if (_patternStep++ < 64) {
        transmitMuscleOxygenMuscleOxygenDataMsg();
    }
    else {
        if ((_backgroundStep++ % _backgroundStepSize) == 0) {
            transmitManufacturerInformationMsg();
            _backgroundStep = 0;
        } else if ((_backgroundStep % _backgroundStepSize) == 1) {
            transmitProductInformationMsg();
        } else if (_flags & ANTPLUS_MUSCLEOXYGEN_FLAGS_BATTERYSTATUS_SUPPORTED) {
            transmitBatteryStatusMsg();
        }
        _patternStep = 0;
    }
}

void ProfileMuscleOxygenMonitor::transmitManufacturerInformationMsg() {
    ManufacturersInformationMsg msg;
    _createManufacturersInformationMsg.call(msg);
    send(msg);
}

void ProfileMuscleOxygenMonitor::transmitProductInformationMsg() {
    ProductInformationMsg msg;
    _createProductInformationMsg.call(msg);
    send(msg);
}

void ProfileMuscleOxygenMonitor::transmitMuscleOxygenMuscleOxygenDataMsg() {
    MuscleOxygenMuscleOxygenDataMsg msg;
    _createMuscleOxygenMuscleOxygenDataMsg.call(msg);
    send(msg);
}

void ProfileMuscleOxygenMonitor::transmitBatteryStatusMsg() {
    BatteryStatusMsg msg;
    _createBatteryStatusMsg.call(msg);
    send(msg);
}
