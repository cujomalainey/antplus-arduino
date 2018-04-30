#include <Profiles/HeartRate/Monitor/ANTPLUS_ProfileHeartRateMonitor.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>

void ProfileHeartRateMonitor::onBroadcastData(BroadcastData& msg) {
    HeartRateBaseMainDataPage dp = HeartRateBaseMainDataPage(msg);
    uint8_t dataPage = dp.getDataPageNumber();
    bool called = false;

    BaseProfile::onBroadcastData(msg);

    switch (dataPage) {

    case ANTPLUS_COMMON_DATAPAGE_MODESETTINGS_NUMBER:
        called = handleModeSettings(dp);
        break;
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
    }

    if (!called) {
        callOnOtherDataPage(msg);
    }
}

void ProfileHeartRateMonitor::transmitNextDataPage() {
    static uint8_t patternStep = 0;
    if (_requestedCount > 0) {
        if (patternStep++ < 65) {
            transmitPrimaryDataPage();
        } else {
            transmitBackgroundDataPage();
            patternStep = 0;
        }
    } else {
        transmitRequestedDataPage();
    }
}

void ProfileHeartRateMonitor::transmitPrimaryDataPage() {
}

void ProfileHeartRateMonitor::transmitBackgroundDataPage() {
}

void ProfileHeartRateMonitor::transmitRequestedDataPage() {
}

bool ProfileHeartRateMonitor::handleModeSettings(HeartRateBaseMainDataPage& dataPage) {
    ModeSettings dp(dataPage);
    return _onModeSettings.call(dp);
}

bool ProfileHeartRateMonitor::handleRequestDataPage(HeartRateBaseMainDataPage& dataPage) {
    RequestDataPage dp(dataPage);
    // TODO handle requested data and populate members
    return _onRequestDataPage.call(dp);
}
