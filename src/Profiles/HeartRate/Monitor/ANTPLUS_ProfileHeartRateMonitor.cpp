#include <Profiles/HeartRate/Monitor/ANTPLUS_ProfileHeartRateMonitor.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>

ProfileHeartRateMonitor::ProfileHeartRateMonitor(uint16_t deviceNumber, uint8_t transmissionType) : BaseMasterProfile(deviceNumber, transmissionType), _nextBackgroundPage(ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_NUMBER) {
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
    if (_requestedCount > 0) {
        if (patternStep++ < 64) {
            transmitPrimaryDataPage();
        } else {
            transmitBackgroundDataPage();
            if (patternStep > 67) {
                patternStep = 0;
            }
        }
    } else {
        transmitRequestedDataPage();
        _requestedCount--;
    }
}

void ProfileHeartRateMonitor::transmitPrimaryDataPage() {
    if (_sportsMode == ANTPLUS_COMMON_DATAPAGE_MODESETTINGS_SPORTSMODE_SWIMMING) {
        transmitHeartRateSwimIntervalSummaryMsg();
    } else {
        if (_useDefaultDataPage) {
            transmitHeartRateDefaultMsg();
        } else {
            transmitHeartRatePreviousHeartBeatMsg();
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

    if (_requestedCount == 68) {
        _nextBackgroundPage++;
        if (_nextBackgroundPage == 4) {
            if (_useCumulativeOperatingTime) {
                _nextBackgroundPage = ANTPLUS_HEARTRATE_DATAPAGE_CUMULATIVEOPERATINGTIME_NUMBER;
            } else {
                _nextBackgroundPage = ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_NUMBER;
            }
        }
    }
}

void ProfileHeartRateMonitor::transmitRequestedDataPage() {
    _requestedCount--;
    switch (_requestedPage) {
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
    // TODO set page toggle
    send(msg);
}

bool ProfileHeartRateMonitor::handleModeSettings(HeartRateBaseMainDataPage& dataPage) {
    ModeSettings dp(dataPage);
    return _onModeSettings.call(dp);
}

bool ProfileHeartRateMonitor::handleRequestDataPage(HeartRateBaseMainDataPage& dataPage) {
    RequestDataPage dp(dataPage);
    // NOTE, according to the HR profile, we should ignore the use acknowledged bit and use
    // only broadcast messages which makes handling requests easier
    if (dp.getRequestedPageNumber() < 8 && (dp.getRequestedPageNumber() != ANTPLUS_HEARTRATE_DATAPAGE_SWIMINTERVALSUMMARY_NUMBER || _sportsMode == ANTPLUS_COMMON_DATAPAGE_MODESETTINGS_SPORTSMODE_SWIMMING)) {
        _requestedCount = dp.getRequestedPageCount();
        _requestedPage = dp.getRequestedPageNumber();
    }
    return _onRequestDataPage.call(dp);
}
