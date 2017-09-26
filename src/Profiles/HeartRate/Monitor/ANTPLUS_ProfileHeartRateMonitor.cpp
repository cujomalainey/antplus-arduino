#include <Profiles/HeartRate/Monitor/ANTPLUS_ProfileHeartRateMonitor.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>
#include <CommonDataPages/RX/ANTPLUS_ModeSettings.h>

ProfileHeartRateMonitor::ProfileHeartRateMonitor() : BaseSlaveProfile() {
    // TODO remove magic numbers
    setDeviceNumber(0);
    setChannelType(CHANNEL_TYPE_BIDIRECTIONAL_RECEIVE);
    setDeviceType(120);
    setTransmissionType(0);
    setChannelPeriod(8070);
    setSearchTimeout(30);
}

ProfileHeartRateMonitor::ProfileHeartRateMonitor(uint16_t deviceNumber) : BaseSlaveProfile(deviceNumber) {
    // TODO remove magic numbers
    setChannelType(CHANNEL_TYPE_BIDIRECTIONAL_RECEIVE);
    setDeviceType(120);
    setTransmissionType(0);
    setChannelPeriod(8070);
    setSearchTimeout(30);
}

void ProfileHeartRateMonitor::onBroadcastData(BroadcastData& msg) {
    HeartRateBaseMainDataPage dp = HeartRateBaseMainDataPage(msg);
    uint8_t dataPage = dp.getDataPageNumber();
    bool called = false;
    // TODO Add general callback here
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
    // TODO mode settings
    }

    if (!called) {
        // TODO handle nothing called
    }
}

void ProfileHeartRateMonitor::begin() {
    pushChannelConfig();
    openChannel();
}

void ProfileHeartRateMonitor::stop() {
    closeChannel();
}

bool ProfileHeartRateMonitor::handleBatteryStatus(HeartRateBaseMainDataPage& dataPage) {
    HeartRateBatteryStatus dp = HeartRateBatteryStatus(dataPage);
    return _onHeartRateBatteryStatus.call(dp);
}

bool ProfileHeartRateMonitor::handleCumulativeOperatingTime(HeartRateBaseMainDataPage& dataPage) {
    HeartRateCumulativeOperatingTime dp = HeartRateCumulativeOperatingTime(dataPage);
    return _onHeartRateCumulativeOperatingTime.call(dp);
}

bool ProfileHeartRateMonitor::handleDefault(HeartRateBaseMainDataPage& dataPage) {
    HeartRateDefault dp = HeartRateDefault(dataPage);
    return _onHeartRateDefault.call(dp);
}

bool ProfileHeartRateMonitor::handleManufacturerInformation(HeartRateBaseMainDataPage& dataPage) {
    HeartRateManufacturerInformation dp = HeartRateManufacturerInformation(dataPage);
    return _onHeartRateManufacturerInformation.call(dp);
}

bool ProfileHeartRateMonitor::handlePreviousHeartBeat(HeartRateBaseMainDataPage& dataPage) {
    HeartRatePreviousHeartBeat dp = HeartRatePreviousHeartBeat(dataPage);
    return _onHeartRatePreviousHeartBeat.call(dp);
}

bool ProfileHeartRateMonitor::handleProductInformation(HeartRateBaseMainDataPage& dataPage) {
    HeartRateProductInformation dp = HeartRateProductInformation(dataPage);
    return _onHeartRateProductInformation.call(dp);
}

bool ProfileHeartRateMonitor::handleSwimIntervalSummary(HeartRateBaseMainDataPage& dataPage) {
    HeartRateSwimIntervalSummary dp = HeartRateSwimIntervalSummary(dataPage);
    return _onHeartRateSwimIntervalSummary.call(dp);
}

bool ProfileHeartRateMonitor::handleModeSettings(HeartRateBaseMainDataPage& dataPage) {
    ModeSettings dp = ModeSettings(dataPage);
    return _onModeSettings.call(dp);
}
