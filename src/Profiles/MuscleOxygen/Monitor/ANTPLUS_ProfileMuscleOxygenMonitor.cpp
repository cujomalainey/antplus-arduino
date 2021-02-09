#include <Profiles/MuscleOxygen/Monitor/ANTPLUS_ProfileMuscleOxygenMonitor.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

#define MONITOR_CHANNELTYPE CHANNEL_TYPE_BIDIRECTIONAL_TRANSMIT
#define MONITOR_TRANSMISSIONTYPE (TRANSMISSION_TYPE_INDEPENDENT | TRANSMISSION_TYPE_GLOBALDATAPGESUSED)

ProfileMuscleOxygenMonitor::ProfileMuscleOxygenMonitor(	uint16_t deviceNumber, uint8_t transmissionType) :
    BaseMasterProfile(deviceNumber,
            ANTPLUS_TRANSMISSION_SET_LSN(
                transmissionType, MONITOR_TRANSMISSIONTYPE)),
    _patternStep(0),
    _backgroundStep(0)
{
    setChannelConfig();
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
        return true;
    // TODO other datapages
    }
    return false;
}

// TODO add check for batterystatus callback
void ProfileMuscleOxygenMonitor::transmitNextDataPage() {
    if (_patternStep++ < 64) {
        transmitMuscleOxygenMuscleOxygenDataMsg();
    }
    else {
        if (_backgroundStep++ % 2 == 0) {
            transmitManufacturerInformationMsg();
        }
        else {
            transmitProductInformationMsg();
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
    // TODO
}
