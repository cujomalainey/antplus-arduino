#include <Profiles/HeartRate/Display/ANTPLUS_ProfileHeartRateDisplay.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>
#include <CommonDataPages/RX/ANTPLUS_ModeSettings.h>
#include <CommonDataPages/ANTPLUS_CommonDataPageDefines.h>

ProfileHeartRateDisplay::ProfileHeartRateDisplay() : BaseSlaveProfile() {
    setChannelConfig();
}

ProfileHeartRateDisplay::ProfileHeartRateDisplay(uint16_t deviceNumber) : BaseSlaveProfile(deviceNumber) {
    setChannelConfig();
}

ProfileHeartRateDisplay::ProfileHeartRateDisplay(uint16_t deviceNumber, uint8_t transmissionType) : BaseSlaveProfile(deviceNumber, transmissionType) {
    setChannelConfig();
}

void ProfileHeartRateDisplay::onBroadcastData(BroadcastData& msg) {
    HeartRateBaseMainDataPage dp = HeartRateBaseMainDataPage(msg);
    BaseSlaveProfile::onBroadcastData(msg);
    if (!handleDataPage(dp)) {
        callOnOtherDataPage(msg);
    }
}

bool ProfileHeartRateDisplay::handleDataPage(HeartRateBaseMainDataPage& dp) {
    uint8_t dataPage = dp.getDataPageNumber();
    bool called = false;

    switch (dataPage) {
    case ANTPLUS_HEARTRATE_DATAPAGE_DEFAULT_NUMBER:
        called = handleDefault(dp);
        break;
    case ANTPLUS_HEARTRATE_DATAPAGE_CUMULATIVEOPERATINGTIME_NUMBER:
        called = handleCumulativeOperatingTime(dp);
        break;
    case ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_NUMBER:
        called = handleManufacturerInformation(dp);
        break;
    case ANTPLUS_HEARTRATE_DATAPAGE_PRODUCTINFORMATION_NUMBER:
        called = handleProductInformation(dp);
        break;
    case ANTPLUS_HEARTRATE_DATAPAGE_PREVIOUSHEARTBEAT_NUMBER:
        called = handlePreviousHeartBeat(dp);
        break;
    case ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_NUMBER:
        called = handleSwimIntervalSummary(dp);
        break;
    case ANTPLUS_HEARTRATE_DATAPAGE_BATTERYSTATUS_NUMBER:
        called = handleBatteryStatus(dp);
        break;
    case ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_NUMBER:
        called = handleCapabilities(dp);
        break;
    }

    return called;
}

void ProfileHeartRateDisplay::onAcknowledgedData(AcknowledgedData& msg) {
    HeartRateBaseMainDataPage dp = HeartRateBaseMainDataPage(msg);
    BaseSlaveProfile::onAcknowledgedData(msg);
    if (!handleDataPage(dp)) {
        callOnOtherDataPage(msg);
    }
}


void ProfileHeartRateDisplay::setChannelConfig() {
    setChannelType(ANTPLUS_HEARTRATE_CHANNELTYPE);
    setDeviceType(ANTPLUS_HEARTRATE_DEVICETYPE);
    setChannelPeriod(ANTPLUS_HEARTRATE_CHANNELPERIOD);
    setSearchTimeout(ANTPLUS_HEARTRATE_SEARCHTIMEOUT);
}

bool ProfileHeartRateDisplay::handleBatteryStatus(HeartRateBaseMainDataPage& dataPage) {
    HeartRateBatteryStatus dp = HeartRateBatteryStatus(dataPage);
    return _onHeartRateBatteryStatus.call(dp);
}

bool ProfileHeartRateDisplay::handleCumulativeOperatingTime(HeartRateBaseMainDataPage& dataPage) {
    HeartRateCumulativeOperatingTime dp = HeartRateCumulativeOperatingTime(dataPage);
    return _onHeartRateCumulativeOperatingTime.call(dp);
}

bool ProfileHeartRateDisplay::handleDefault(HeartRateBaseMainDataPage& dataPage) {
    HeartRateDefault dp = HeartRateDefault(dataPage);
    return _onHeartRateDefault.call(dp);
}

bool ProfileHeartRateDisplay::handleManufacturerInformation(HeartRateBaseMainDataPage& dataPage) {
    HeartRateManufacturerInformation dp = HeartRateManufacturerInformation(dataPage);
    return _onHeartRateManufacturerInformation.call(dp);
}

bool ProfileHeartRateDisplay::handlePreviousHeartBeat(HeartRateBaseMainDataPage& dataPage) {
    HeartRatePreviousHeartBeat dp = HeartRatePreviousHeartBeat(dataPage);
    return _onHeartRatePreviousHeartBeat.call(dp);
}

bool ProfileHeartRateDisplay::handleProductInformation(HeartRateBaseMainDataPage& dataPage) {
    HeartRateProductInformation dp = HeartRateProductInformation(dataPage);
    return _onHeartRateProductInformation.call(dp);
}

bool ProfileHeartRateDisplay::handleSwimIntervalSummary(HeartRateBaseMainDataPage& dataPage) {
    HeartRateSwimIntervalSummary dp = HeartRateSwimIntervalSummary(dataPage);
    return _onHeartRateSwimIntervalSummary.call(dp);
}

bool ProfileHeartRateDisplay::handleCapabilities(HeartRateBaseMainDataPage& dataPage) {
    HeartRateCapabilities dp = HeartRateCapabilities(dataPage);
    return _onHeartRateCapabilities.call(dp);
}
