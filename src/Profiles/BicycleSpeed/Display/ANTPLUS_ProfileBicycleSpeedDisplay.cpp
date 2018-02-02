#include <Profiles/BicycleSpeed/Display/ANTPLUS_ProfileBicycleSpeedDisplay.h>
#include <Profiles/BicycleSpeed/ANTPLUS_BicycleSpeedPrivateDefines.h>
#include <CommonDataPages/RX/ANTPLUS_ModeSettings.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>

ProfileBicycleSpeedDisplay::ProfileBicycleSpeedDisplay() : BaseSlaveProfile() {
    setChannelConfig();
}

ProfileBicycleSpeedDisplay::ProfileBicycleSpeedDisplay(uint16_t deviceNumber) : BaseSlaveProfile(deviceNumber) {
    setChannelConfig();
}

ProfileBicycleSpeedDisplay::ProfileBicycleSpeedDisplay(uint16_t deviceNumber, uint8_t transmissionType) : BaseSlaveProfile(deviceNumber, transmissionType) {
    setChannelConfig();
}

void ProfileBicycleSpeedDisplay::onBroadcastData(BroadcastData& msg) {
    BicycleSpeedBaseMainDataPage dp = BicycleSpeedBaseMainDataPage(msg);
    BaseProfile::onBroadcastData(msg);
    if (!handleDataPage(dp)) {
        callOnOtherDataPage(msg);
    }
}

bool ProfileBicycleSpeedDisplay::handleDataPage(BicycleSpeedBaseMainDataPage& dp) {
    uint8_t dataPage = dp.getDataPageNumber();
    bool called = false;

    switch (dataPage) {
    case ANTPLUS_BICYCLESPEED_DATAPAGE_DEFAULT_NUMBER:
        called = handleDefault(dp);
        break;
    case ANTPLUS_BICYCLESPEED_DATAPAGE_CUMULATIVEOPERATINGTIME_NUMBER:
        called = handleCumulativeOperatingTime(dp);
        break;
    case ANTPLUS_BICYCLESPEED_DATAPAGE_MANUFACTURERID_NUMBER:
        called = handleManufacturerID(dp);
        break;
    case ANTPLUS_BICYCLESPEED_DATAPAGE_PRODUCTID_NUMBER:
        called = handleProductID(dp);
        break;
    case ANTPLUS_BICYCLESPEED_DATAPAGE_BATTERYSTATUS_NUMBER:
        called = handleBatteryStatus(dp);
        break;
    case ANTPLUS_BICYCLESPEED_DATAPAGE_MOTIONANDSPEED_NUMBER:
        called = handleMotionAndSpeed(dp);
        break;
    }

    return called;
}

void ProfileBicycleSpeedDisplay::onAcknowledgedData(AcknowledgedData& msg) {
    BicycleSpeedBaseMainDataPage dp = BicycleSpeedBaseMainDataPage(msg);
    BaseProfile::onAcknowledgedData(msg);
    if (!handleDataPage(dp)) {
        callOnOtherDataPage(msg);
    }
}


void ProfileBicycleSpeedDisplay::setChannelConfig() {
    setChannelType(ANTPLUS_BICYCLESPEED_CHANNELTYPE);
    setDeviceType(ANTPLUS_BICYCLESPEED_DEVICETYPE);
    setChannelPeriod(ANTPLUS_BICYCLESPEED_CHANNELPERIOD);
    setSearchTimeout(ANTPLUS_BICYCLESPEED_SEARCHTIMEOUT);
}

bool ProfileBicycleSpeedDisplay::handleBatteryStatus(BicycleSpeedBaseMainDataPage& dataPage) {
    BicycleSpeedBatteryStatus dp = BicycleSpeedBatteryStatus(dataPage);
    return _onBicycleSpeedBatteryStatus.call(dp);
}

bool ProfileBicycleSpeedDisplay::handleCumulativeOperatingTime(BicycleSpeedBaseMainDataPage& dataPage) {
    BicycleSpeedCumulativeOperatingTime dp = BicycleSpeedCumulativeOperatingTime(dataPage);
    return _onBicycleSpeedCumulativeOperatingTime.call(dp);
}

bool ProfileBicycleSpeedDisplay::handleDefault(BicycleSpeedBaseMainDataPage& dataPage) {
    BicycleSpeedDefault dp = BicycleSpeedDefault(dataPage);
    return _onBicycleSpeedDefault.call(dp);
}

bool ProfileBicycleSpeedDisplay::handleManufacturerID(BicycleSpeedBaseMainDataPage& dataPage) {
    BicycleSpeedManufacturerID dp = BicycleSpeedManufacturerID(dataPage);
    return _onBicycleSpeedManufacturerID.call(dp);
}

bool ProfileBicycleSpeedDisplay::handleProductID(BicycleSpeedBaseMainDataPage& dataPage) {
    BicycleSpeedProductID dp = BicycleSpeedProductID(dataPage);
    return _onBicycleSpeedProductID.call(dp);
}

bool ProfileBicycleSpeedDisplay::handleMotionAndSpeed(BicycleSpeedBaseMainDataPage& dataPage) {
    BicycleSpeedMotionAndSpeed dp = BicycleSpeedMotionAndSpeed(dataPage);
    return _onBicycleSpeedMotionAndSpeed.call(dp);
}
