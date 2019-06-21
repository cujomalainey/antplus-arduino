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
        MuscleOxygenBaseMainDataPageMsg msg;
        if (_toggle++ % 2 == 0) {
            ProductInformationMsg msg;
            msg.setSerialNumber(0x12345678);
            msg.setSWRevisionMain(1);
            msg.setSWRevisionSupplemental(1);
        }
        else {
            ManufacturersInformationMsg msg;
            msg.setHWRevision(1);
            msg.setManufacturerId(0x1234);
            msg.setModelNumber(0x5678);
        }
        send(msg);
        _patternStep = 0;
    }
}

void ProfileMuscleOxygenMonitor::transmitMuscleOxygenMainPageMsg() {
    MuscleOxygenBaseMainDataPageMsg msg;
    _createMuscleOxygenDataMsg.call(msg);
    send(msg);
}
