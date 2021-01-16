#include <Profiles/HeartRate/Monitor/ANTPLUS_ProfileHeartRateMonitor.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRateDefines.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>

#define MONITOR_CHANNELTYPE CHANNEL_TYPE_BIDIRECTIONAL_TRANSMIT

ProfileHeartRateMonitor::ProfileHeartRateMonitor(
        uint16_t deviceNumber,
        uint8_t transmissionType) :
    BaseMasterProfile(deviceNumber, transmissionType),
    _nextBackgroundPage(MANUFACTURERINFORMATION_NUMBER),
    _flags(0) {
    setChannelConfig();
}

ProfileHeartRateMonitor::ProfileHeartRateMonitor(
        uint16_t deviceNumber,
        uint8_t transmissionType,
        uint32_t flags) :
    BaseMasterProfile(deviceNumber, transmissionType),
    _nextBackgroundPage(MANUFACTURERINFORMATION_NUMBER),
    _flags(flags) {
    setChannelConfig();
}

void ProfileHeartRateMonitor::onBroadcastData(BroadcastData& msg) {
    HeartRateBaseMainDataPage dp(msg);
    uint8_t dataPage = dp.getDataPageNumber();
    bool called = false;

    BaseMasterProfile::onBroadcastData(msg);

    switch (dataPage) {
        // Display always should be using acknowledged messages
    }

    if (!called) {
        callOnOtherDataPage(msg);
    }
}

void ProfileHeartRateMonitor::onAcknowledgedData(AcknowledgedData& msg) {
    HeartRateBaseMainDataPage dp(msg);
    uint8_t dataPage = dp.getDataPageNumber();
    bool called = false;

    BaseMasterProfile::onAcknowledgedData(msg);

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
    if (isRequestedPagePending()) {
        transmitRequestedDataPage();
    } else {
        if (_patternStep++ < 64) {
            transmitPrimaryDataPage();
        } else {
            transmitBackgroundDataPage();
            if (_patternStep > 67) {
                _nextBackgroundPage = getNextBackgroundPage(_nextBackgroundPage);
                _patternStep = 0;
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
    case CUMULATIVEOPERATINGTIME_NUMBER:
        transmitHeartRateCumulativeOperatingTimeMsg();
        break;
    case MANUFACTURERINFORMATION_NUMBER:
        transmitHeartRateManufacturerInformationMsg();
        break;
    case PRODUCTINFORMATION_NUMBER:
        transmitHeartRateProductInformationMsg();
        break;
    case BATTERYSTATUS_NUMBER:
        transmitHeartRateBatteryStatusMsg();
        break;
    case CAPABILITIES_NUMBER:
        transmitHeartRateCapabilitiesMsg();
        break;
    }
}

uint8_t ProfileHeartRateMonitor::getNextBackgroundPage(uint8_t currentPage) {
    if ((currentPage < CUMULATIVEOPERATINGTIME_NUMBER) && (_flags & ANTPLUS_HEARTRATE_FLAGS_CUMULATIVEOPERATINGTIME_SUPPORTED)) {
        return CUMULATIVEOPERATINGTIME_NUMBER;
    } else if (currentPage < MANUFACTURERINFORMATION_NUMBER) {
        return MANUFACTURERINFORMATION_NUMBER;
    } else if (currentPage < PRODUCTINFORMATION_NUMBER) {
        return PRODUCTINFORMATION_NUMBER;
    } else if ((currentPage < CAPABILITIES_NUMBER) && (_flags & ANTPLUS_HEARTRATE_FLAGS_EXTENTED_FEATURES)) {
        return CAPABILITIES_NUMBER;
    } else if ((currentPage < BATTERYSTATUS_NUMBER) && (_flags & ANTPLUS_HEARTRATE_FLAGS_BATTERYSTATUS_SUPPORTED)) {
        return BATTERYSTATUS_NUMBER;
    } else {
        // Reached end of the loop, start again
        return getNextBackgroundPage(0);
    }
}

void ProfileHeartRateMonitor::transmitRequestedDataPage() {
    uint8_t requestedPage = getRequestedPage();
    switch (requestedPage) {
    case DEFAULT_NUMBER:
        transmitHeartRateDefaultMsg();
        break;
    case CUMULATIVEOPERATINGTIME_NUMBER:
        transmitHeartRateCumulativeOperatingTimeMsg();
        break;
    case MANUFACTURERINFORMATION_NUMBER:
        transmitHeartRateManufacturerInformationMsg();
        break;
    case PRODUCTINFORMATION_NUMBER:
        transmitHeartRateProductInformationMsg();
        break;
    case PREVIOUSHEARTBEAT_NUMBER:
        transmitHeartRatePreviousHeartBeatMsg();
        break;
    case SWIMINTERVALSUMMARY_NUMBER:
        transmitHeartRateSwimIntervalSummaryMsg();
        break;
    case CAPABILITIES_NUMBER:
        transmitHeartRateCapabilitiesMsg();
        break;
    case BATTERYSTATUS_NUMBER:
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
    transmitMsg(msg);
}

bool ProfileHeartRateMonitor::isDataPageValid(uint8_t dataPage) {
    switch (dataPage) {
    case DEFAULT_NUMBER:
        // TODO double check this is correct that dp 4 is only needed if imlemented
        return !(_flags & ANTPLUS_HEARTRATE_FLAGS_PREVIOUSHEARTBEAT_SUPPORTED);
    case CUMULATIVEOPERATINGTIME_NUMBER:
        return _flags & ANTPLUS_HEARTRATE_FLAGS_CUMULATIVEOPERATINGTIME_SUPPORTED;
    case MANUFACTURERINFORMATION_NUMBER:
    case PRODUCTINFORMATION_NUMBER:
        return true;
    case PREVIOUSHEARTBEAT_NUMBER:
        return _flags & ANTPLUS_HEARTRATE_FLAGS_PREVIOUSHEARTBEAT_SUPPORTED;
    case SWIMINTERVALSUMMARY_NUMBER:
    case CAPABILITIES_NUMBER:
        return _flags & ANTPLUS_HEARTRATE_FLAGS_EXTENTED_FEATURES;
    case BATTERYSTATUS_NUMBER:
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
    setChannelType(MONITOR_CHANNELTYPE);
    setDeviceType(ANTPLUS_HEARTRATE_DEVICETYPE);
    setChannelPeriod(ANTPLUS_HEARTRATE_CHANNELPERIOD);
    setSearchTimeout(ANTPLUS_HEARTRATE_SEARCHTIMEOUT);
}
