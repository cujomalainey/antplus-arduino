#include <Profiles/Lev/Profiles/ANTPLUS_ProfileLevDisplay.h>
#include <Profiles/Lev/ANTPLUS_LevPrivateDefines.h>
#include <Profiles/Lev/ANTPLUS_LevDefines.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>

#define DISPLAY_CHANNELTYPE CHANNEL_TYPE_BIDIRECTIONAL_RECEIVE

ProfileLevDisplay::ProfileLevDisplay() : BaseSlaveProfile() {
    setChannelConfig();
}

ProfileLevDisplay::ProfileLevDisplay(uint16_t deviceNumber) : BaseSlaveProfile(deviceNumber) {
    setChannelConfig();
}

ProfileLevDisplay::ProfileLevDisplay(uint16_t deviceNumber, uint8_t transmissionType) : BaseSlaveProfile(deviceNumber, transmissionType) {
    setChannelConfig();
}

void ProfileLevDisplay::setChannelConfig() {
    setChannelType(DISPLAY_CHANNELTYPE);
    setDeviceType(ANTPLUS_LEV_DEVICETYPE);
    setChannelPeriod(LEV_CHANNELPERIOD);
    setSearchTimeout(LEV_SEARCHTIMEOUT);
}

void ProfileLevDisplay::onBroadcastData(BroadcastData& msg) {
    BaseProfile::onBroadcastData(msg);
    LevBaseMainDataPage dp = LevBaseMainDataPage(msg);
    if (!handleDataPage(dp)) {
        callOnOtherDataPage(msg);
    }
}

void ProfileLevDisplay::onAcknowledgedData(AcknowledgedData& msg) {
    BaseProfile::onAcknowledgedData(msg);
    LevBaseMainDataPage dp = LevBaseMainDataPage(msg);
    if (!handleDataPage(dp)) {
        callOnOtherDataPage(msg);
    }
}

bool ProfileLevDisplay::handleDataPage(LevBaseMainDataPage& dp) {
    uint8_t dataPage = dp.getDataPageNumber();
    bool called = false;

    switch (dataPage) {

    case SPEEDSYSTEMINFORMATION1_NUMBER:
        called = handleSpeedSystemInformation1(dp);
        break;
    case SPEEDDISTANCEINFORMATION_NUMBER:
        called = handleSpeedDistanceInformation(dp);
        break;
    case ALTSPEEDDISTANCEINFORMATION_NUMBER:
        called = handleAltSpeedDistanceInformation(dp);
        break;
    case SPEEDSYSTEMINFORMATION2_NUMBER:
        called = handleSpeedSystemInformation2(dp);
        break;
    case BATTERYINFORMATION_NUMBER:
        called = handleBatteryInformation(dp);
        break;
    case LEVCAPABILITIES_NUMBER:
        called = handleCapabilities(dp);
        break;
    case COMMON_MANUFACTURERSINFORMATION_NUMBER:
        called = handleManufacturersInformation(dp);
        break;
    case COMMON_PRODUCTINFORMATION_NUMBER:
        called = handleProductInformation(dp);
        break;
    }
    return called;
}

bool ProfileLevDisplay::handleSpeedSystemInformation1(LevBaseMainDataPage& dataPage) {
    LevSpeedSystemInformation1 dp = LevSpeedSystemInformation1(dataPage);
    return _onLevSpeedSystemInformation1.call(dp);
}

bool ProfileLevDisplay::handleSpeedDistanceInformation(LevBaseMainDataPage& dataPage) {
    LevSpeedDistanceInformation dp = LevSpeedDistanceInformation(dataPage);
    return _onLevSpeedDistanceInformation.call(dp);
}

bool ProfileLevDisplay::handleAltSpeedDistanceInformation(LevBaseMainDataPage& dataPage) {
    LevAltSpeedDistanceInformation dp = LevAltSpeedDistanceInformation(dataPage);
    return _onLevAltSpeedDistanceInformation.call(dp);
}

bool ProfileLevDisplay::handleSpeedSystemInformation2(LevBaseMainDataPage& dataPage) {
    LevSpeedSystemInformation2 dp = LevSpeedSystemInformation2(dataPage);
    return _onLevSpeedSystemInformation2.call(dp);
}

bool ProfileLevDisplay::handleBatteryInformation(LevBaseMainDataPage& dataPage) {
    LevBatteryInformation dp = LevBatteryInformation(dataPage);
    return _onLevBatteryInformation.call(dp);
}

bool ProfileLevDisplay::handleCapabilities(LevBaseMainDataPage& dataPage) {
    LevCapabilities dp = LevCapabilities(dataPage);
    return _onLevCapabilities.call(dp);
}

bool ProfileLevDisplay::handleManufacturersInformation(LevBaseMainDataPage& dataPage) {
    ManufacturersInformation dp = ManufacturersInformation(dataPage);
    return _onManufacturersInformation.call(dp);
}

bool ProfileLevDisplay::handleProductInformation(LevBaseMainDataPage& dataPage) {
    ProductInformation dp = ProductInformation(dataPage);
    return _onProductInformation.call(dp);
}
