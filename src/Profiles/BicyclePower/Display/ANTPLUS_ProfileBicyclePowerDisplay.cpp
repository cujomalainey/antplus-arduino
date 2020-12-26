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
    case ANTPLUS_BICYCLEPOWER_DATAPAGE_DATAPAGE_POWERONLY_NUMBER:
    	called = handlePowerOnly(dp);
    	break;
    case ANTPLUS_BICYCLEPOWER_DATAPAGE_DATAPAGE_CRANKTORQUE_NUMBER:
		called = handleCrankTorque(dp);
    	break;
    case ANTPLUS_BICYCLEPOWER_DATAPAGE_DATAPAGE_WHEELTORQUE_NUMBER:
		called = handleWheelTorque(dp);
    	break;
    case ANTPLUS_BICYCLEPOWER_DATAPAGE_DATAPAGE_PEDALSMOOTHNESS_NUMBER:
		called = handlePedalSmoothness(dp);
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
    BicyclePowerCumulativeOperatingTime dp = BicyclePowerCumulativeOperatingTime(dataPage);
    return _onBicyclePowerCumulativeOperatingTime.call(dp);
}

bool ProfileBicyclePowerDisplay::handleManufacturerID(BicyclePowerBaseMainDataPage& dataPage) {
    BicyclePowerManufacturerID dp = BicyclePowerManufacturerID(dataPage);
    return _onBicyclePowerManufacturerID.call(dp);
}

bool ProfileBicyclePowerDisplay::handleProductID(BicyclePowerBaseMainDataPage& dataPage) {
    BicyclePowerProductID dp = BicyclePowerProductID(dataPage);
    return _onBicyclePowerProductID.call(dp);
}

bool ProfileBicyclePowerDisplay::handlePowerOnly(BicyclePowerBaseMainDataPage& dataPage) {
    BicyclePowerPowerOnly dp = BicyclePowerPowerOnly(dataPage);
    return _onBicyclePowerPowerOnly.call(dp);
}

bool ProfileBicyclePowerDisplay::handleCrankTorque(BicyclePowerBaseMainDataPage& dataPage) {
    BicyclePowerCrankTorque dp = BicyclePowerCrankTorque(dataPage);
    return _onBicyclePowerCrankTorque.call(dp);
}

bool ProfileBicyclePowerDisplay::handleWheelTorque(BicyclePowerBaseMainDataPage& dataPage) {
    BicyclePowerWheelTorque dp = BicyclePowerWheelTorque(dataPage);
    return _onBicyclePowerWheelTorque.call(dp);
}

bool ProfileBicyclePowerDisplay::handlePedalSmoothness(BicyclePowerBaseMainDataPage& dataPage) {
    BicyclePowerPedalSmoothness dp = BicyclePowerPedalSmoothness(dataPage);
    return _onBicyclePowerPedalSmoothness.call(dp);
}
