#include <Profiles/HeartRate/Monitor/ANTPLUS_ProfileHeartRateMonitor.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRateDefines.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>

ProfileHeartRateMonitor::ProfileHeartRateMonitor(
        uint16_t deviceNumber,
        uint8_t transmissionType) :
    BaseMasterProfile(deviceNumber, transmissionType),
    _nextBackgroundPage(ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_NUMBER),
    _flags(0) {
    setChannelConfig();
}

ProfileHeartRateMonitor::ProfileHeartRateMonitor(
        uint16_t deviceNumber,
        uint8_t transmissionType,
        uint32_t flags) :
    BaseMasterProfile(deviceNumber, transmissionType),
    _nextBackgroundPage(ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_NUMBER),
    _flags(flags) {
    setChannelConfig();
}

void ProfileHeartRateMonitor::onBroadcastData(BroadcastData& msg) {
    HeartRateBaseMainDataPage dp = HeartRateBaseMainDataPage(msg);
    uint8_t dataPage = dp.getDataPageNumber();
    bool called = false;

    BaseProfile::onBroadcastData(msg);

    switch (dataPage) {
        // Display always should be using acknowledged messages
    }

    if (!called) {
        callOnOtherDataPage(msg);
    }
}

void ProfileHeartRateMonitor::onAcknowledgedData(AcknowledgedData& msg) {
    HeartRateBaseMainDataPage dp = HeartRateBaseMainDataPage(msg);
    uint8_t dataPage = dp.getDataPageNumber();
    bool called = false;

    BaseProfile::onAcknowledgedData(msg);

    switch (dataPage) {

    case ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_NUMBER:
        called = handleRequestDataPage(dp);
        break;
    case ANTPLUS_COMMON_DATAPAGE_MODESETTINGS_NUMBER:
        called = handleModeSettings(dp);
        break;
    }

    if (!called) {
        callOnOtherDataPage(msg);
    }
}

void ProfileHeartRateMonitor::transmitNextDataPage() {
    static uint8_t patternStep = 0;
    if (isRequestedPagePending()) {
        transmitRequestedDataPage();
    } else {
        if (patternStep++ < 64) {
            transmitPrimaryDataPage();
        } else {
            transmitBackgroundDataPage();
            if (patternStep > 67) {
                _nextBackgroundPage = getNextBackgroundPage(_nextBackgroundPage);
                patternStep = 0;
            }
        }
    }
}

void ProfileHeartRateMonitor::transmitPrimaryDataPage() {
    if (_sportsMode == ANTPLUS_COMMON_DATAPAGE_MODESETTINGS_SPORTSMODE_SWIMMING) {
        transmitHeartRateSwimIntervalSummaryMsg();
    } else {
        if (_flags & ANTPLUS_HEARTRATE_FLAGS_PREVIOUSHEARTBEAT_SUPPORTED) {
            transmitHeartRatePreviousHeartBeatMsg();
        } else {
            transmitHeartRateDefaultMsg();
        }
    }
}

void ProfileHeartRateMonitor::transmitBackgroundDataPage() {
    switch (_nextBackgroundPage) {
    case ANTPLUS_HEARTRATE_DATAPAGE_CUMULATIVEOPERATINGTIME_NUMBER:
        transmitHeartRateCumulativeOperatingTimeMsg();
        break;
    case ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_NUMBER:
        transmitHeartRateManufacturerInformationMsg();
        break;
    case ANTPLUS_HEARTRATE_DATAPAGE_PRODUCTINFORMATION_NUMBER:
        transmitHeartRateProductInformationMsg();
        break;
    }
}

uint8_t ProfileHeartRateMonitor::getNextBackgroundPage(uint8_t currentPage) {
    if ((currentPage < ANTPLUS_HEARTRATE_DATAPAGE_CUMULATIVEOPERATINGTIME_NUMBER) && (_flags & ANTPLUS_HEARTRATE_FLAGS_CUMULATIVEOPERATINGTIME_SUPPORTED)) {
        return ANTPLUS_HEARTRATE_DATAPAGE_CUMULATIVEOPERATINGTIME_NUMBER;
    } else if (currentPage < ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_NUMBER) {
        return ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_NUMBER;
    } else if (currentPage < ANTPLUS_HEARTRATE_DATAPAGE_PRODUCTINFORMATION_NUMBER) {
        return ANTPLUS_HEARTRATE_DATAPAGE_PRODUCTINFORMATION_NUMBER;
    } else if ((currentPage < ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_NUMBER) && (_flags & ANTPLUS_HEARTRATE_FLAGS_EXTENTED_FEATURES)) {
        return ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_NUMBER;
    } else if ((currentPage < ANTPLUS_HEARTRATE_DATAPAGE_BATTERYSTATUS_NUMBER) && (_flags & ANTPLUS_HEARTRATE_FLAGS_BATTERYSTATUS_SUPPORTED)) {
        return ANTPLUS_HEARTRATE_DATAPAGE_BATTERYSTATUS_NUMBER;
    } else {
        // Reached end of the loop, start again
        return getNextBackgroundPage(0);
    }
}

void ProfileHeartRateMonitor::transmitRequestedDataPage() {
    uint8_t requestedPage = getRequestedPage();
    switch (requestedPage) {
    case ANTPLUS_HEARTRATE_DATAPAGE_DEFAULT_NUMBER:
        transmitHeartRateDefaultMsg();
        break;
    case ANTPLUS_HEARTRATE_DATAPAGE_CUMULATIVEOPERATINGTIME_NUMBER:
        transmitHeartRateCumulativeOperatingTimeMsg();
        break;
    case ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_NUMBER:
        transmitHeartRateManufacturerInformationMsg();
        break;
    case ANTPLUS_HEARTRATE_DATAPAGE_PRODUCTINFORMATION_NUMBER:
        transmitHeartRateProductInformationMsg();
        break;
    case ANTPLUS_HEARTRATE_DATAPAGE_PREVIOUSHEARTBEAT_NUMBER:
        transmitHeartRatePreviousHeartBeatMsg();
        break;
    case ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_NUMBER:
        transmitHeartRateSwimIntervalSummaryMsg();
        break;
    case ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_NUMBER:
        transmitHeartRateCapabilitiesMsg();
        break;
    case ANTPLUS_HEARTRATE_DATAPAGE_BATTERYSTATUS_NUMBER:
        transmitHeartRateBatteryStatusMsg();
        break;
    }
}

void ProfileHeartRateMonitor::transmitHeartRateDefaultMsg() {
    HeartRateDefaultMsg msg;
    _createHeartRateDefaultMsg.call(msg);
    transmitHeartRateMsg(msg);
}

void ProfileHeartRateMonitor::transmitHeartRateCumulativeOperatingTimeMsg() {
    HeartRateCumulativeOperatingTimeMsg msg;
    _createHeartRateCumulativeOperatingTimeMsg.call(msg);
    transmitHeartRateMsg(msg);
}

void ProfileHeartRateMonitor::transmitHeartRateManufacturerInformationMsg() {
    HeartRateManufacturerInformationMsg msg;
    _createHeartRateManufacturerInformationMsg.call(msg);
    transmitHeartRateMsg(msg);
}

void ProfileHeartRateMonitor::transmitHeartRateProductInformationMsg() {
    HeartRateProductInformationMsg msg;
    _createHeartRateProductInformationMsg.call(msg);
    transmitHeartRateMsg(msg);
}

void ProfileHeartRateMonitor::transmitHeartRatePreviousHeartBeatMsg() {
    HeartRatePreviousHeartBeatMsg msg;
    _createHeartRatePreviousHeartBeatMsg.call(msg);
    transmitHeartRateMsg(msg);
}

void ProfileHeartRateMonitor::transmitHeartRateSwimIntervalSummaryMsg() {
    HeartRateSwimIntervalSummaryMsg msg;
    _createHeartRateSwimIntervalSummaryMsg.call(msg);
    transmitHeartRateMsg(msg);
}

void ProfileHeartRateMonitor::transmitHeartRateCapabilitiesMsg() {
    HeartRateCapabilitiesMsg msg;
    _createHeartRateCapabilitiesMsg.call(msg);
    transmitHeartRateMsg(msg);
}

void ProfileHeartRateMonitor::transmitHeartRateBatteryStatusMsg() {
    HeartRateBatteryStatusMsg msg;
    _createHeartRateBatteryStatusMsg.call(msg);
    transmitHeartRateMsg(msg);
}

void ProfileHeartRateMonitor::transmitHeartRateMsg(HeartRateBaseMainDataPageMsg& msg) {
    uint8_t toggle = _toggleStep++;
    toggle /= 4;
    _toggleStep = _toggleStep % 8;
    msg.setPageChangeToggle(toggle);
    // TODO handle requested acknowledged types, even though it shouldnt happen
    send(msg);
}

bool ProfileHeartRateMonitor::isDataPageValid(uint8_t dataPage) {
    switch (dataPage) {
    case ANTPLUS_HEARTRATE_DATAPAGE_DEFAULT_NUMBER:
        return !(_flags & ANTPLUS_HEARTRATE_FLAGS_PREVIOUSHEARTBEAT_SUPPORTED);
    case ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_NUMBER:
    case ANTPLUS_HEARTRATE_DATAPAGE_PRODUCTINFORMATION_NUMBER:
        return true;
    case ANTPLUS_HEARTRATE_DATAPAGE_CUMULATIVEOPERATINGTIME_NUMBER:
        return _flags & ANTPLUS_HEARTRATE_FLAGS_CUMULATIVEOPERATINGTIME_SUPPORTED;
    case ANTPLUS_HEARTRATE_DATAPAGE_PREVIOUSHEARTBEAT_NUMBER:
        return _flags & ANTPLUS_HEARTRATE_FLAGS_PREVIOUSHEARTBEAT_SUPPORTED;
    case ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_NUMBER:
    case ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_NUMBER:
        return _flags & ANTPLUS_HEARTRATE_FLAGS_EXTENTED_FEATURES;
    case ANTPLUS_HEARTRATE_DATAPAGE_BATTERYSTATUS_NUMBER:
        return _flags & ANTPLUS_HEARTRATE_FLAGS_BATTERYSTATUS_SUPPORTED;
    default:
        return false;
    }
}

bool ProfileHeartRateMonitor::handleModeSettings(HeartRateBaseMainDataPage& dataPage) {
    ModeSettings dp(dataPage);
    return _onModeSettings.call(dp);
}

bool ProfileHeartRateMonitor::handleRequestDataPage(HeartRateBaseMainDataPage& dataPage) {
    RequestDataPage dp(dataPage);
    return _onRequestDataPage.call(dp);
}

void ProfileHeartRateMonitor::setChannelConfig() {
    setChannelType(ANTPLUS_HEARTRATE_MONITOR_CHANNELTYPE);
    setDeviceType(ANTPLUS_HEARTRATE_DEVICETYPE);
    setChannelPeriod(ANTPLUS_HEARTRATE_CHANNELPERIOD);
    setSearchTimeout(ANTPLUS_HEARTRATE_SEARCHTIMEOUT);
}
