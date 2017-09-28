#include <Profiles/HeartRate/Sensor/ANTPLUS_ProfileHeartRateSensor.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>
#include <CommonDataPages/ANTPLUS_CommonDataPageDefines.h>

void ProfileHeartRateSensor::onBroadcastData(BroadcastData& msg) {
    HeartRateBaseMainDataPage dp = HeartRateBaseMainDataPage(msg);
    uint8_t dataPage = dp.getDataPageNumber();
    bool called = false;

    BaseProfile::onBroadcastData(msg);

    switch (dataPage) {

    case ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_NUMBER:
        called = handleCapabilities(dp);
        break;
    }

    if (!called) {
        callOnOtherDataPage(msg);
    }
}

void ProfileHeartRateSensor::onAcknowledgedData(AcknowledgedData& msg) {
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

bool ProfileHeartRateSensor::handleCapabilities(HeartRateBaseMainDataPage& dataPage) {
    HeartRateCapabilities dp = HeartRateCapabilities(dataPage);
    return _onHeartRateCapabilities.call(dp);
}

bool ProfileHeartRateSensor::handleRequestDataPage(HeartRateBaseMainDataPage& dataPage) {
    RequestDataPage dp = RequestDataPage(dataPage);
    return _onRequestDataPage.call(dp);
}
