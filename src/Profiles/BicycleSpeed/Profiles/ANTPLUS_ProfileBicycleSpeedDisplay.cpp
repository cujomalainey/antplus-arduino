#include <Profiles/BicycleSpeed/Profiles/ANTPLUS_ProfileBicycleSpeedDisplay.h>
#include <Profiles/BicycleSpeed/ANTPLUS_BicycleSpeedPrivateDefines.h>

#define DISPLAY_CHANNELTYPE CHANNEL_TYPE_BIDIRECTIONAL_RECEIVE

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
    case BICYCLESPEED_DEFAULT_NUMBER:
        called = handleDefault(dp);
        break;
    case BICYCLESPEED_CUMULATIVEOPERATINGTIME_NUMBER:
        called = handleCumulativeOperatingTime(dp);
        break;
    case BICYCLESPEED_MANUFACTURERID_NUMBER:
        called = handleManufacturerID(dp);
        break;
    case BICYCLESPEED_PRODUCTID_NUMBER:
        called = handleProductID(dp);
        break;
    case BICYCLESPEED_BATTERYSTATUS_NUMBER:
        called = handleBatteryStatus(dp);
        break;
    case BICYCLESPEED_MOTIONANDSPEED_NUMBER:
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
    setChannelType(DISPLAY_CHANNELTYPE);
    setDeviceType(ANTPLUS_BICYCLESPEED_DEVICETYPE);
    setChannelPeriod(BICYCLESPEED_CHANNELPERIOD);
    setSearchTimeout(BICYCLESPEED_SEARCHTIMEOUT);
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
