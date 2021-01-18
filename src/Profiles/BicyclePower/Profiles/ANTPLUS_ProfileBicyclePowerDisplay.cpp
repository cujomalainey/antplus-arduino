#include <Profiles/BicyclePower/Profiles/ANTPLUS_ProfileBicyclePowerDisplay.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerPrivateDefines.h>
#include <CommonDataPages/ANTPLUS_CommonDataPages.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>

#define DISPLAY_CHANNELTYPE			CHANNEL_TYPE_BIDIRECTIONAL_RECEIVE

ProfileBicyclePowerDisplay::ProfileBicyclePowerDisplay() : BaseSlaveProfile() {
    setChannelConfig();
}

ProfileBicyclePowerDisplay::ProfileBicyclePowerDisplay(uint16_t deviceNumber) : BaseSlaveProfile(deviceNumber) {
    setChannelConfig();
}

ProfileBicyclePowerDisplay::ProfileBicyclePowerDisplay(uint16_t deviceNumber, uint8_t transmissionType) : BaseSlaveProfile(deviceNumber, transmissionType) {
    setChannelConfig();
}

void ProfileBicyclePowerDisplay::onBroadcastData(BroadcastData& msg) {
    BicyclePowerBaseMainDataPage dp = BicyclePowerBaseMainDataPage(msg);
    BaseProfile::onBroadcastData(msg);
    if (!handleDataPage(dp)) {
        callOnOtherDataPage(msg);
    }
}

bool ProfileBicyclePowerDisplay::handleDataPage(BicyclePowerBaseMainDataPage& dp) {
    uint8_t dataPage = dp.getDataPageNumber();
    bool called = false;

    switch (dataPage) {
    case COMMON_MANUFACTURERSINFORMATION_NUMBER:
        called = handleManufacturersInformation(dp);
        break;
    case COMMON_PRODUCTINFORMATION_NUMBER:
        called = handleProductInformation(dp);
        break;
    case COMMON_BATTERYSTATUS_NUMBER:
        called = handleBatteryStatus(dp);
        break;
    case BICYCLEPOWER_STANDARDPOWERONLY_NUMBER:
        called = handleStandardPowerOnly(dp);
        break;
    case BICYCLEPOWER_STANDARDCRANKTORQUE_NUMBER:
        called = handleStandardCrankTorque(dp);
        break;
    case BICYCLEPOWER_STANDARDWHEELTORQUE_NUMBER:
        called = handleStandardWheelTorque(dp);
        break;
    case BICYCLEPOWER_TORQUEEFFECTIVENESSANDPEDALSMOOTHNESS_NUMBER:
        called = handleTorqueEffectivenessAndPedalSmoothness(dp);
        break;
    }

    return called;
}

void ProfileBicyclePowerDisplay::onAcknowledgedData(AcknowledgedData& msg) {
    BicyclePowerBaseMainDataPage dp = BicyclePowerBaseMainDataPage(msg);
    BaseProfile::onAcknowledgedData(msg);
    if (!handleDataPage(dp)) {
        callOnOtherDataPage(msg);
    }
}


void ProfileBicyclePowerDisplay::setChannelConfig() {
    setChannelType(DISPLAY_CHANNELTYPE);
    setDeviceType(ANTPLUS_BICYCLEPOWER_DEVICETYPE);
    setChannelPeriod(CHANNELPERIOD);
    setSearchTimeout(SEARCHTIMEOUT);
}

bool ProfileBicyclePowerDisplay::handleBatteryStatus(BicyclePowerBaseMainDataPage& dataPage) {
    BatteryStatus dp(dataPage);
    return _onBatteryStatus.call(dp);
}

bool ProfileBicyclePowerDisplay::handleManufacturersInformation(BicyclePowerBaseMainDataPage& dataPage) {
    ManufacturersInformation dp(dataPage);
    return _onManufacturersInformation.call(dp);
}

bool ProfileBicyclePowerDisplay::handleProductInformation(BicyclePowerBaseMainDataPage& dataPage) {
    ProductInformation dp(dataPage);
    return _onProductInformation.call(dp);
}

bool ProfileBicyclePowerDisplay::handleStandardPowerOnly(BicyclePowerBaseMainDataPage& dataPage) {
    BicyclePowerStandardPowerOnly dp(dataPage);
    return _onBicyclePowerStandardPowerOnly.call(dp);
}

bool ProfileBicyclePowerDisplay::handleStandardCrankTorque(BicyclePowerBaseMainDataPage& dataPage) {
    BicyclePowerStandardCrankTorque dp(dataPage);
    return _onBicyclePowerStandardCrankTorque.call(dp);
}

bool ProfileBicyclePowerDisplay::handleStandardWheelTorque(BicyclePowerBaseMainDataPage& dataPage) {
    BicyclePowerStandardWheelTorque dp(dataPage);
    return _onBicyclePowerStandardWheelTorque.call(dp);
}

bool ProfileBicyclePowerDisplay::handleTorqueEffectivenessAndPedalSmoothness(BicyclePowerBaseMainDataPage& dataPage) {
    BicyclePowerTorqueEffectivenessAndPedalSmoothness dp(dataPage);
    return _onBicyclePowerTorqueEffectivenessAndPedalSmoothness.call(dp);
}
