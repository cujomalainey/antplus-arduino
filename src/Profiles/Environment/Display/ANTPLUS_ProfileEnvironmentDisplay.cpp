#include <Profiles/Environment/Display/ANTPLUS_ProfileEnvironmentDisplay.h>
#include <Profiles/Environment/ANTPLUS_EnvironmentPrivateDefines.h>
#include <CommonDataPages/ANTPLUS_CommonDataPageDefines.h>

ProfileEnvironmentDisplay::ProfileEnvironmentDisplay() : BaseSlaveProfile() {
    setChannelConfig();
}

ProfileEnvironmentDisplay::ProfileEnvironmentDisplay(uint16_t deviceNumber) : BaseSlaveProfile(deviceNumber) {
    setChannelConfig();
}

ProfileEnvironmentDisplay::ProfileEnvironmentDisplay(uint16_t deviceNumber, uint8_t transmissionType) : BaseSlaveProfile(deviceNumber, transmissionType) {
    setChannelConfig();
}

void ProfileEnvironmentDisplay::onBroadcastData(BroadcastData& msg) {
    EnvironmentBaseMainDataPage dp = EnvironmentBaseMainDataPage(msg);
    uint8_t dataPage = dp.getDataPageNumber();
    bool called = false;

    BaseProfile::onBroadcastData(msg);

    switch (dataPage) {
    }

    if (!called) {
        callOnOtherDataPage(msg);
    }
}

void ProfileEnvironmentDisplay::onAcknowledgedData(AcknowledgedData& msg) {
    // TODO
}

void ProfileHeartRateMonitor::setChannelConfig() {
    setChannelType(ANTPLUS_ENVIRONMENT_CHANNELTYPE);
    setDeviceType(ANTPLUS_ENVIRONMENT_DEVICETYPE);
    setChannelPeriod(ANTPLUS_ENVIRONMENT_CHANNELPERIOD);
    setSearchTimeout(ANTPLUS_ENVIRONMENT_SEARCHTIMEOUT);
}
