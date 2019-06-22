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
    if (_patternStep++ < 64) {
        transmitMuscleOxygenMainPageMsg();
    }
    else {
        if (_toggle++ % 2 == 0) {
            transmitMuscleOxygenManufacturerInformationMsg();
        }
        else {
            transmitMuscleOxygenProductInformationMsg();
        }
        _patternStep = 0;
    }
}

void ProfileMuscleOxygenMonitor::transmitMuscleOxygenManufacturerInformationMsg() {
    ManufacturersInformationMsg msg;
    _createMuscleOxygenManufacturerInformationMsg.call(msg);
    send(msg);
}

void ProfileMuscleOxygenMonitor::transmitMuscleOxygenProductInformationMsg() {
    ProductInformationMsg msg;
    _createMuscleOxygenProductInformationMsg.call(msg);
    send(msg);
}

void ProfileMuscleOxygenMonitor::transmitMuscleOxygenMainPageMsg() {
    MuscleOxygenBaseMainDataPageMsg msg;
    _createMuscleOxygenDataMsg.call(msg);
    send(msg);
}
