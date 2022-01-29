#include <Profiles/Fec/Profiles/ANTPLUS_FecProfileDisplay.h>
#include <Profiles/Fec/ANTPLUS_FecPrivateDefines.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>

#define DISPLAY_CHANNELTYPE CHANNEL_TYPE_BIDIRECTIONAL_RECEIVE

ProfileFecDisplay::ProfileFecDisplay(uint16_t deviceNumber, uint8_t transmissionType) : BaseSlaveProfile(deviceNumber, transmissionType) {
    setChannelConfig();
}

void ProfileFecDisplay::onBroadcastData(BroadcastData& msg) {
    BaseDataPage<BroadcastData> dp = BaseDataPage<BroadcastData>(msg);
    BaseSlaveProfile::onBroadcastData(msg);
    if (!handleDataPage(dp)) {
        callOnOtherDataPage(msg);
    }
}

bool ProfileFecDisplay::handleDataPage(BaseDataPage<BroadcastData>& dp) {
    uint8_t dataPage = dp.getDataPageNumber();
    bool called = false;

    switch (dataPage) {
    case SPECIFIC_TRAINER_DATA_NUMBER:
        called = handleTrainerData(dp);
        break;

    case COMMON_MANUFACTURERSINFORMATION_NUMBER:
        called = handleManufacturerInformation(dp);
        break;

    case COMMON_PRODUCTINFORMATION_NUMBER:
        called = handleProductInformation(dp);
        break;

    case GENERAL_FE_DATA_NUMBER:
        called = handleGeneralFeData(dp);
        break;

    case GENERAL_SETTINGS_PAGE_NUMBER:
        called = handleGeneralSettingsPage(dp);
        break;

    case TARGET_POWER_NUMBER:
        called = handleTargetPowerDataPage(dp);
        break;

    case FE_CAPABILITIES_NUMBER:
        called = handleFeCapabilities(dp);
        break;
    }

    return called;
}

void ProfileFecDisplay::onAcknowledgedData(AcknowledgedData& msg) {
    BaseDataPage<BroadcastData> dp = BaseDataPage<BroadcastData>(msg);
    BaseSlaveProfile::onAcknowledgedData(msg);
    if (!handleDataPage(dp)) {
        callOnOtherDataPage(msg);
    }
}

void ProfileFecDisplay::setChannelConfig() {
    setChannelType(DISPLAY_CHANNELTYPE);
    setDeviceType(ANTPLUS_FEC_REALTIMECHANNEL_DEVICETYPE);
    setChannelPeriod(ANTPLUS_FEC_CHANNELPERIOD);
    setSearchTimeout(ANTPLUS_FEC_SEARCHTIMEOUT);
}

bool ProfileFecDisplay::handleManufacturerInformation(BaseDataPage<BroadcastData>& dataPage) {
    ManufacturersInformation dp(dataPage);
    return _onManufacturersInformation.call(dp);
}

bool ProfileFecDisplay::handleProductInformation(BaseDataPage<BroadcastData>& dataPage) {
    ProductInformation dp(dataPage);
    return _onProductInformation.call(dp);
}

bool ProfileFecDisplay::handleGeneralFeData(BaseDataPage<BroadcastData>& dataPage) {
    FecGeneralFeData dp(dataPage);
    return _onFecGeneralFeData.call(dp);
}

bool ProfileFecDisplay::handleGeneralSettingsPage(BaseDataPage<BroadcastData>& dataPage) {
    FecGeneralSettingsPage dp(dataPage);
    return _onFecGeneralSettingsPage.call(dp);
}
bool ProfileFecDisplay::handleTargetPowerDataPage(BaseDataPage<BroadcastData>& dataPage) {
    FecTargetPowerDataPage dp(dataPage);
    return _onFecTargetPowerDataPage.call(dp);
}

bool ProfileFecDisplay::handleFeCapabilities(BaseDataPage<BroadcastData>& dataPage) {
    FecFeCapabilities dp(dataPage);
    return _onFecFeCapabilities.call(dp);
}

bool ProfileFecDisplay::transmitFecTargetPowerMsg(uint16_t TargetPower) {
    FecTargetPowerDataMsg msg;
    msg.setTargetPower(TargetPower);
    send(msg);
    return false;
}

bool ProfileFecDisplay::transmitFecTrackResistanceMsg(uint16_t TargetGrade) {
    FecTrackResistanceDataMsg msg;
    msg.setTargetGrade(TargetGrade);
    send(msg);
    return false;
}

bool ProfileFecDisplay::transmitFecBasicResistanceMsg(uint8_t total_resistance) {
    FecBasicResistanceMsg msg;
    msg.setTotalResistance(total_resistance);
    send(msg);
    return false;
}

bool ProfileFecDisplay::transmitFecUserConfigurationMsg(uint16_t UserWeight, uint16_t BikeWeight) {
    FecUserConfigurationMsg msg;
    msg.setUserWeight(UserWeight);
    msg.setBikeWeight(BikeWeight);
    send(msg);
    return true;
}

bool ProfileFecDisplay::handleTrainerData(BaseDataPage<BroadcastData>& dataPage) {
    FecSpecificTrainerData dp(dataPage);
    return _onFecSpecificTrainerData.call(dp);
}
