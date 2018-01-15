#include <Profiles/Environment/Display/ANTPLUS_ProfileEnvironmentDisplay.h>
#include <Profiles/Environment/ANTPLUS_EnvironmentPrivateDefines.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>

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
    EnvironmentBaseDataPage dp = EnvironmentBaseDataPage(msg);
    uint8_t dataPage = dp.getDataPageNumber();
    bool called = false;

    BaseProfile::onBroadcastData(msg);

    switch (dataPage) {
        case ANTPLUS_ENVIRONMENT_DATAPAGE_GENERALINFORMATION_NUMBER:
            called = handleGeneralInformation(dp);
            break;
        case ANTPLUS_ENVIRONMENT_DATAPAGE_TEMPERATURE_NUMBER:
            called = handleTemperature(dp);
            break;
        case ANTPLUS_COMMON_DATAPAGE_MANUFACTURERSIDENTIFICATION_NUMBER:
            // TODO
            break;
        case ANTPLUS_COMMON_DATAPAGE_PRODUCTINFORMATION_NUMBER:
            // TODO
            break;
    }

    if (!called) {
        callOnOtherDataPage(msg);
    }
}

void ProfileEnvironmentDisplay::onAcknowledgedData(AcknowledgedData& msg) {
    // TODO
}

void ProfileEnvironmentDisplay::setChannelConfig() {
    setChannelType(ANTPLUS_ENVIRONMENT_CHANNELTYPE);
    setDeviceType(ANTPLUS_ENVIRONMENT_DEVICETYPE);
    setChannelPeriod(ANTPLUS_ENVIRONMENT_CHANNELPERIOD);
    setSearchTimeout(ANTPLUS_ENVIRONMENT_SEARCHTIMEOUT);
}

bool ProfileEnvironmentDisplay::handleGeneralInformation(EnvironmentBaseDataPage& dataPage) {
    EnvironmentGeneralInformation dp = EnvironmentGeneralInformation(dataPage);
    return _onEnvironmentGeneralInformation.call(dp);
}

bool ProfileEnvironmentDisplay::handleTemperature(EnvironmentBaseDataPage& dataPage) {
    EnvironmentTemperature dp = EnvironmentTemperature(dataPage);
    return _onEnvironmentTemperature.call(dp);
}
