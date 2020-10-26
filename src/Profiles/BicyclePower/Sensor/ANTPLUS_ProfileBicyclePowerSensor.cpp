#include <Profiles/BicyclePower/Sensor/ANTPLUS_ProfileBicyclePowerSensor.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerDefines.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerPrivateDefines.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>

ProfileBicyclePowerSensor::ProfileBicyclePowerSensor(
        uint16_t deviceNumber,
        uint8_t transmissionType) :
    BaseMasterProfile(deviceNumber, transmissionType),
    //_nextBackgroundPage(ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_NUMBER),
    _flags(0) {
    setChannelConfig();
}

ProfileBicyclePowerSensor::ProfileBicyclePowerSensor(
        uint16_t deviceNumber,
        uint8_t transmissionType,
        uint32_t flags) :
    BaseMasterProfile(deviceNumber, transmissionType),
    //_nextBackgroundPage(ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_NUMBER),
    _flags(flags) {
    setChannelConfig();
}

void ProfileBicyclePowerSensor::onBroadcastData(BroadcastData& msg) {
    BicyclePowerStdPowerOnlyDataPage dp(msg);
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

void ProfileBicyclePowerSensor::onAcknowledgedData(AcknowledgedData& msg) {
    BicyclePowerStdPowerOnlyDataPage dp(msg);
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

void ProfileBicyclePowerSensor::transmitNextDataPage() {
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
    transmitPrimaryDataPage();
}

bool ProfileBicyclePowerSensor::handleRequestDataPage(BicyclePowerStdPowerOnlyDataPage& dataPage) {
    RequestDataPage dp(dataPage);
    return _onRequestDataPage.call(dp);
}

void ProfileBicyclePowerSensor::transmitPrimaryDataPage() {
    transmitBicyclePowerDefaultMsg();
}

void ProfileBicyclePowerSensor::transmitBackgroundDataPage() {
    switch (_nextBackgroundPage) {
    case ANTPLUS_HEARTRATE_DATAPAGE_CUMULATIVEOPERATINGTIME_NUMBER:
        transmitBicyclePowerCumulativeOperatingTimeMsg();
        break;
    case ANTPLUS_HEARTRATE_DATAPAGE_MANUFACTURERINFORMATION_NUMBER:
        transmitBicyclePowerManufacturerInformationMsg();
        break;
    case ANTPLUS_HEARTRATE_DATAPAGE_PRODUCTINFORMATION_NUMBER:
        transmitBicyclePowerProductInformationMsg();
        break;
    case ANTPLUS_HEARTRATE_DATAPAGE_BATTERYSTATUS_NUMBER:
        transmitBicyclePowerBatteryStatusMsg();
        break;
    case ANTPLUS_HEARTRATE_DATAPAGE_CAPABILITIES_NUMBER:
        transmitBicyclePowerCapabilitiesMsg();
        break;
    }
}

uint8_t ProfileBicyclePowerSensor::getNextBackgroundPage(uint8_t currentPage) {
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
    return 0;
}

void ProfileBicyclePowerSensor::transmitRequestedDataPage() {
    uint8_t requestedPage = getRequestedPage();
    switch (requestedPage) {
    case ANTPLUS_BICYCLEPOWER_DATAPAGE_STD_POWERONLY_MAIN_DATAPAGE_NUMBER:
        transmitBicyclePowerDefaultMsg();
        break;
    }
}

void ProfileBicyclePowerSensor::transmitBicyclePowerDefaultMsg() {
    BicyclePowerStdPowerOnlyDataPageMsg msg;
    _createBicyclePowerStdPowerOnlyDataPageMsg.call(msg);
    transmitBicycleStdPowerOnlyMsg(msg);
}

void ProfileBicyclePowerSensor::transmitBicycleStdPowerOnlyMsg(BicyclePowerStdPowerOnlyDataPageMsg& msg) {
    send(msg);
}

void ProfileBicyclePowerSensor::setChannelConfig() {
    setChannelType(ANTPLUS_BICYCLEPOWER_SENSOR_CHANNELTYPE);
    setDeviceType(ANTPLUS_BICYCLEPOWER_DEVICETYPE);
    setChannelPeriod(ANTPLUS_BICYCLEPOWER_CHANNELPERIOD);
    setSearchTimeout(ANTPLUS_BICYCLEPOWER_SEARCHTIMEOUT);
}

bool ProfileBicyclePowerSensor::isDataPageValid(uint8_t dataPage) {
    return true;
}
