#include <Profiles/BicyclePower/Profiles/ANTPLUS_ProfileBicyclePowerSensor.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerDefines.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerPrivateDefines.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>

#define SENSOR_CHANNELTYPE   CHANNEL_TYPE_BIDIRECTIONAL_TRANSMIT

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
    BicyclePowerStandardPowerOnly dp(msg);
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
    BicyclePowerStandardPowerOnly dp(msg);
    uint8_t dataPage = dp.getDataPageNumber();
    bool called = false;

    BaseMasterProfile::onAcknowledgedData(msg);
    switch (dataPage) {

    case REQUESTDATAPAGE_NUMBER:
        called = handleRequestDataPage(dp);
        break;
    case GENERALCALIBRATION_NUMBER:
        called = handleGeneralCalibration(dp);
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

bool ProfileBicyclePowerSensor::handleRequestDataPage(BicyclePowerStandardPowerOnly& dataPage) {
    RequestDataPage dp(dataPage);
    return _onRequestDataPage.call(dp);
}

bool ProfileBicyclePowerSensor::handleGeneralCalibration(BicyclePowerStandardPowerOnly& dataPage) {
    // TODO
    return false;
}

void ProfileBicyclePowerSensor::transmitPrimaryDataPage() {
    // TODO
}

void ProfileBicyclePowerSensor::transmitBackgroundDataPage() {
    switch (_nextBackgroundPage) {
    case STANDARDPOWERONLY_NUMBER:
        transmitBicyclePowerStandardPowerOnlyMsg();
        break;
    case STANDARDWHEELTORQUE_NUMBER:
        transmitBicyclePowerStandardWheelTorqueMsg();
        break;
    case STANDARDCRANKTORQUE_NUMBER:
        transmitBicyclePowerStandardCrankTorqueMsg();
        break;
    case TORQUEEFFECTIVENESSANDPEDALSMOOTHNESS_NUMBER:
        transmitBicyclePowerTorqueEffectivenessAndPedalSmoothnessMsg();
        break;
    case CRANKTORQUEFREQUENCY_NUMBER:
        transmitBicyclePowerCrankTorqueFrequencyMsg();
        break;
    case GENERALCALIBRATION_NUMBER: // TODO (check is this part of the background transmission, seems sus)
        transmistBicyclePowerGeneralCalibrationResponse();
        break;
    }
}

void ProfileBicyclePowerSensor::transmitBicyclePowerStandardPowerOnlyMsg() {
    // TODO
    BicyclePowerStandardPowerOnlyMsg msg;
    _createBicyclePowerStandardPowerOnlyMsg.call(msg);
    transmitMsg(msg);
}

void ProfileBicyclePowerSensor::transmitBicyclePowerStandardWheelTorqueMsg() {
    // TODO
}

void ProfileBicyclePowerSensor::transmitBicyclePowerStandardCrankTorqueMsg() {
    // TODO
}

void ProfileBicyclePowerSensor::transmitBicyclePowerTorqueEffectivenessAndPedalSmoothnessMsg() {
    // TODO
}

void ProfileBicyclePowerSensor::transmitBicyclePowerCrankTorqueFrequencyMsg() {
    // TODO
}

void ProfileBicyclePowerSensor::transmistBicyclePowerGeneralCalibrationResponse() {
    // TODO
}

uint8_t ProfileBicyclePowerSensor::getNextBackgroundPage(uint8_t currentPage) {
    // TODO
    return 0;
}

void ProfileBicyclePowerSensor::transmitRequestedDataPage() {
    uint8_t requestedPage = getRequestedPage();
    switch (requestedPage) {
    case STANDARDPOWERONLY_NUMBER:
        // TODO
        break;
    }
}

void ProfileBicyclePowerSensor::setChannelConfig() {
    setChannelType(SENSOR_CHANNELTYPE);
    setDeviceType(ANTPLUS_BICYCLEPOWER_DEVICETYPE);
    setChannelPeriod(CHANNELPERIOD);
    setSearchTimeout(SEARCHTIMEOUT);
}

bool ProfileBicyclePowerSensor::isDataPageValid(uint8_t dataPage) {
    // TODO
    return true;
}
