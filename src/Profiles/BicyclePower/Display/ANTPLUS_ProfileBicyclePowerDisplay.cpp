#include <Profiles/BicyclePower/Display/ANTPLUS_ProfileBicyclePowerDisplay.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerPrivateDefines.h>
#include <CommonDataPages/RX/ANTPLUS_ModeSettings.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>

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
    case ANTPLUS_BICYCLEPOWER_DATAPAGE_MANUFACTURERID_NUMBER:
        called = handleManufacturerID(dp);
        break;
    case ANTPLUS_BICYCLEPOWER_DATAPAGE_PRODUCTID_NUMBER:
        called = handleProductID(dp);
        break;
    case ANTPLUS_BICYCLEPOWER_DATAPAGE_BATTERYSTATUS_NUMBER:
        called = handleBatteryStatus(dp);
        break;
    case ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDPOWERONLY_NUMBER:
        called = handleStandardPowerOnly(dp);
        break;
    case ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDCRANKTORQUE_NUMBER:
        called = handleStandardCrankTorque(dp);
        break;
    case ANTPLUS_BICYCLEPOWER_DATAPAGE_STANDARDWHEELTORQUE_NUMBER:
        called = handleStandardWheelTorque(dp);
        break;
    case ANTPLUS_BICYCLEPOWER_DATAPAGE_TORQUEEFFECTIVENESSANDPEDALSMOOTHNESS_NUMBER:
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
    setChannelType(ANTPLUS_BICYCLEPOWER_DISPLAY_CHANNELTYPE);
    setDeviceType(ANTPLUS_BICYCLEPOWER_DEVICETYPE);
    setChannelPeriod(ANTPLUS_BICYCLEPOWER_CHANNELPERIOD);
    setSearchTimeout(ANTPLUS_BICYCLEPOWER_SEARCHTIMEOUT);
}

bool ProfileBicyclePowerDisplay::handleBatteryStatus(BicyclePowerBaseMainDataPage& dataPage) {
    BicyclePowerBatteryStatus dp = BicyclePowerBatteryStatus(dataPage);
    return _onBicyclePowerBatteryStatus.call(dp);
}

bool ProfileBicyclePowerDisplay::handleCumulativeOperatingTime(BicyclePowerBaseMainDataPage& dataPage) {
    BicyclePowerCumulativeOperatingTime dp(dataPage);
    return _onBicyclePowerCumulativeOperatingTime.call(dp);
}

bool ProfileBicyclePowerDisplay::handleManufacturerID(BicyclePowerBaseMainDataPage& dataPage) {
    BicyclePowerManufacturerID dp(dataPage);
    return _onBicyclePowerManufacturerID.call(dp);
}

bool ProfileBicyclePowerDisplay::handleProductID(BicyclePowerBaseMainDataPage& dataPage) {
    BicyclePowerProductID dp(dataPage);
    return _onBicyclePowerProductID.call(dp);
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
