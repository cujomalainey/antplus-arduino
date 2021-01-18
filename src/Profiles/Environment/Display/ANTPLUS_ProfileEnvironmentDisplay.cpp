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
    BaseProfile::onBroadcastData(msg);
    if(!handleDataPage(dp)) {
        callOnOtherDataPage(msg);
    }
}

bool ProfileEnvironmentDisplay::handleDataPage(EnvironmentBaseDataPage& dp) {
    uint8_t dataPage = dp.getDataPageNumber();
    bool called = false;

    switch (dataPage) {
        case ANTPLUS_ENVIRONMENT_DATAPAGE_GENERALINFORMATION_NUMBER:
            called = handleGeneralInformation(dp);
            break;
        case ANTPLUS_ENVIRONMENT_DATAPAGE_TEMPERATURE_NUMBER:
            called = handleTemperature(dp);
            break;
        case MANUFACTURERSINFORMATION_NUMBER:
            // Called Manufacturers Identification in Environment Profile PDF
            called = handleManufacturersInformation(dp);
            break;
        case PRODUCTINFORMATION_NUMBER:
            called = handleProductInformation(dp);
            break;
    }
    return called;
}

void ProfileEnvironmentDisplay::onAcknowledgedData(AcknowledgedData& msg) {
    EnvironmentBaseDataPage dp = EnvironmentBaseDataPage(msg);
    BaseProfile::onAcknowledgedData(msg);
    if(!handleDataPage(dp)) {
        callOnOtherDataPage(msg);
    }
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

bool ProfileEnvironmentDisplay::handleManufacturersInformation(EnvironmentBaseDataPage& dataPage) {
    ManufacturersInformation dp = ManufacturersInformation(dataPage);
    return _onManufacturersInformation.call(dp);
}

bool ProfileEnvironmentDisplay::handleProductInformation(EnvironmentBaseDataPage& dataPage) {
    ProductInformation dp = ProductInformation(dataPage);
    return _onProductInformation.call(dp);
}
