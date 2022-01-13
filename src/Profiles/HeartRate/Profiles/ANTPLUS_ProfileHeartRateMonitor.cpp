#include <Profiles/HeartRate/Profiles/ANTPLUS_ProfileHeartRateMonitor.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRateDefines.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

#define MONITOR_CHANNELTYPE CHANNEL_TYPE_BIDIRECTIONAL_TRANSMIT
#define MONITOR_TRANSMISSIONTYPE TRANSMISSION_TYPE_INDEPENDENT

// TODO switch from flags to checking if callbacks are set
ProfileHeartRateMonitor::ProfileHeartRateMonitor(
        uint16_t deviceNumber,
        uint8_t transmissionType,
        uint32_t flags) :
    BaseMasterProfile(deviceNumber,
            ANTPLUS_TRANSMISSION_SET_LSN(
                transmissionType, MONITOR_TRANSMISSIONTYPE)),
    _nextBackgroundPage(HEARTRATE_MANUFACTURERINFORMATION_NUMBER),
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

    case COMMON_REQUESTDATAPAGE_NUMBER:
        called = handleRequestDataPage(dp);
        break;
    case COMMON_MODESETTINGS_NUMBER:
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
        return;
    }

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

void ProfileHeartRateMonitor::transmitPrimaryDataPage() {
    if (_sportsMode == ANTPLUS_COMMON_DATAPAGE_MODESETTINGS_SPORTSMODE_SWIMMING) {
        transmitHeartRateSwimIntervalSummaryMsg();
        return;
    }

    if (_createHeartRatePreviousHeartBeatMsg.func) {
        transmitHeartRatePreviousHeartBeatMsg();
    } else {
        transmitHeartRateDefaultMsg();
    }
}

void ProfileHeartRateMonitor::transmitBackgroundDataPage() {
    switch (_nextBackgroundPage) {
    case HEARTRATE_CUMULATIVEOPERATINGTIME_NUMBER:
        transmitHeartRateCumulativeOperatingTimeMsg();
        break;
    case HEARTRATE_MANUFACTURERINFORMATION_NUMBER:
        transmitHeartRateManufacturerInformationMsg();
        break;
    case HEARTRATE_PRODUCTINFORMATION_NUMBER:
        transmitHeartRateProductInformationMsg();
        break;
    case HEARTRATE_BATTERYSTATUS_NUMBER:
        transmitHeartRateBatteryStatusMsg();
        break;
    case HEARTRATE_CAPABILITIES_NUMBER:
        transmitHeartRateCapabilitiesMsg();
        break;
    }
}

uint8_t ProfileHeartRateMonitor::getNextBackgroundPage(uint8_t currentPage) {
    if ((currentPage < HEARTRATE_CUMULATIVEOPERATINGTIME_NUMBER) &&
            (_createHeartRateCumulativeOperatingTimeMsg.func)) {
        return HEARTRATE_CUMULATIVEOPERATINGTIME_NUMBER;
    } else if (currentPage < HEARTRATE_MANUFACTURERINFORMATION_NUMBER) {
        return HEARTRATE_MANUFACTURERINFORMATION_NUMBER;
    } else if (currentPage < HEARTRATE_PRODUCTINFORMATION_NUMBER) {
        return HEARTRATE_PRODUCTINFORMATION_NUMBER;
    } else if ((currentPage < HEARTRATE_CAPABILITIES_NUMBER) &&
            (_flags & ANTPLUS_HEARTRATE_FLAGS_EXTENTED_FEATURES)) {
        return HEARTRATE_CAPABILITIES_NUMBER;
    } else if ((currentPage < HEARTRATE_BATTERYSTATUS_NUMBER) &&
            (_createHeartRateBatteryStatusMsg.func)) {
        return HEARTRATE_BATTERYSTATUS_NUMBER;
    } else {
        // Reached end of the loop, start again
        return getNextBackgroundPage(0);
    }
}

void ProfileHeartRateMonitor::transmitRequestedDataPage() {
    uint8_t requestedPage = getRequestedPage();
    switch (requestedPage) {
    case HEARTRATE_DEFAULT_NUMBER:
        transmitHeartRateDefaultMsg();
        break;
    case HEARTRATE_CUMULATIVEOPERATINGTIME_NUMBER:
        transmitHeartRateCumulativeOperatingTimeMsg();
        break;
    case HEARTRATE_MANUFACTURERINFORMATION_NUMBER:
        transmitHeartRateManufacturerInformationMsg();
        break;
    case HEARTRATE_PRODUCTINFORMATION_NUMBER:
        transmitHeartRateProductInformationMsg();
        break;
    case HEARTRATE_PREVIOUSHEARTBEAT_NUMBER:
        transmitHeartRatePreviousHeartBeatMsg();
        break;
    case HEARTRATE_SWIMINTERVALSUMMARY_NUMBER:
        transmitHeartRateSwimIntervalSummaryMsg();
        break;
    case HEARTRATE_CAPABILITIES_NUMBER:
        transmitHeartRateCapabilitiesMsg();
        break;
    case HEARTRATE_BATTERYSTATUS_NUMBER:
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
    case HEARTRATE_DEFAULT_NUMBER:
        return (bool)(_createHeartRateDefaultMsg.func);
    case HEARTRATE_CUMULATIVEOPERATINGTIME_NUMBER:
        return (bool)(_createHeartRateCumulativeOperatingTimeMsg.func);
    case HEARTRATE_MANUFACTURERINFORMATION_NUMBER:
    case HEARTRATE_PRODUCTINFORMATION_NUMBER:
        return true;
    case HEARTRATE_PREVIOUSHEARTBEAT_NUMBER:
        return (bool)(_createHeartRatePreviousHeartBeatMsg.func);
    case HEARTRATE_CAPABILITIES_NUMBER:
        return _flags & ANTPLUS_HEARTRATE_FLAGS_EXTENTED_FEATURES;
    case HEARTRATE_SWIMINTERVALSUMMARY_NUMBER:
        return _flags & ANTPLUS_HEARTRATE_FLAGS_EXTENTED_FEATURES &&
            (bool)(_createHeartRateSwimIntervalSummaryMsg.func);
    case HEARTRATE_BATTERYSTATUS_NUMBER:
        return (bool)(_createHeartRateBatteryStatusMsg.func);
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
    setChannelPeriod(HEARTRATE_CHANNELPERIOD);
    setSearchTimeout(HEARTRATE_SEARCHTIMEOUT);
}
