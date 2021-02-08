#include <Profiles/BicyclePower/Profiles/ANTPLUS_ProfileBicyclePowerSensor.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerDefines.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerPrivateDefines.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

#define SENSOR_CHANNELTYPE   CHANNEL_TYPE_BIDIRECTIONAL_TRANSMIT
#define SENSOR_TRANSMISSIONTYPE (TRANSMISSION_TYPE_INDEPENDENT | TRANSMISSION_TYPE_GLOBALDATAPGESUSED)

ProfileBicyclePowerSensor::ProfileBicyclePowerSensor(
        uint16_t deviceNumber,
        uint8_t transmissionType,
        uint32_t flags) :
    BaseMasterProfile(deviceNumber,
            ANTPLUS_TRANSMISSION_SET_LSN(
                transmissionType, SENSOR_TRANSMISSIONTYPE)),
    // TODO
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

    case COMMON_REQUESTDATAPAGE_NUMBER:
        called = handleRequestDataPage(dp);
        break;
    case BICYCLEPOWER_GENERALCALIBRATION_NUMBER:
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
    case BICYCLEPOWER_STANDARDPOWERONLY_NUMBER:
        transmitBicyclePowerStandardPowerOnlyMsg();
        break;
    case BICYCLEPOWER_STANDARDWHEELTORQUE_NUMBER:
        transmitBicyclePowerStandardWheelTorqueMsg();
        break;
    case BICYCLEPOWER_STANDARDCRANKTORQUE_NUMBER:
        transmitBicyclePowerStandardCrankTorqueMsg();
        break;
    case BICYCLEPOWER_TORQUEEFFECTIVENESSANDPEDALSMOOTHNESS_NUMBER:
        transmitBicyclePowerTorqueEffectivenessAndPedalSmoothnessMsg();
        break;
    case BICYCLEPOWER_CRANKTORQUEFREQUENCY_NUMBER:
        transmitBicyclePowerCrankTorqueFrequencyMsg();
        break;
    case BICYCLEPOWER_GENERALCALIBRATION_NUMBER: // TODO (check is this part of the background transmission, seems sus)
        transmistBicyclePowerGeneralCalibrationResponse();
        break;
    }
}

void ProfileBicyclePowerSensor::transmitBicyclePowerStandardPowerOnlyMsg() {
    BicyclePowerStandardPowerOnlyMsg msg;
    _createBicyclePowerStandardPowerOnlyMsg.call(msg);
    transmitMsg(msg);
}

void ProfileBicyclePowerSensor::transmitBicyclePowerStandardWheelTorqueMsg() {
    BicyclePowerStandardWheelTorqueMsg msg;
    _createBicyclePowerStandardWheelTorqueMsg.call(msg);
    transmitMsg(msg);
}

void ProfileBicyclePowerSensor::transmitBicyclePowerStandardCrankTorqueMsg() {
    BicyclePowerStandardCrankTorqueMsg msg;
    _createBicyclePowerStandardCrankTorqueMsg.call(msg);
    transmitMsg(msg);
}

void ProfileBicyclePowerSensor::transmitBicyclePowerTorqueEffectivenessAndPedalSmoothnessMsg() {
    BicyclePowerTorqueEffectivenessAndPedalSmoothnessMsg msg;
    _createBicyclePowerTorqueEffectivenessAndPedalSmoothnessMsg.call(msg);
    transmitMsg(msg);
}

void ProfileBicyclePowerSensor::transmitBicyclePowerCrankTorqueFrequencyMsg() {
    BicyclePowerCrankTorqueFrequencyMsg msg;
    _createBicyclePowerCrankTorqueFrequencyMsg.call(msg);
    transmitMsg(msg);
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
    // TODO rest of datapages
    case BICYCLEPOWER_STANDARDPOWERONLY_NUMBER:
        transmitBicyclePowerStandardPowerOnlyMsg();
        break;
    case BICYCLEPOWER_STANDARDWHEELTORQUE_NUMBER:
        transmitBicyclePowerStandardWheelTorqueMsg();
        break;
    case BICYCLEPOWER_STANDARDCRANKTORQUE_NUMBER:
        transmitBicyclePowerStandardCrankTorqueMsg();
        break;
    case BICYCLEPOWER_TORQUEEFFECTIVENESSANDPEDALSMOOTHNESS_NUMBER:
        transmitBicyclePowerTorqueEffectivenessAndPedalSmoothnessMsg();
        break;
    case BICYCLEPOWER_CRANKTORQUEFREQUENCY_NUMBER:
        transmitBicyclePowerCrankTorqueFrequencyMsg();
        break;
    }
}

void ProfileBicyclePowerSensor::setChannelConfig() {
    setChannelType(SENSOR_CHANNELTYPE);
    setDeviceType(ANTPLUS_BICYCLEPOWER_DEVICETYPE);
    setChannelPeriod(BICYCLEPOWER_CHANNELPERIOD);
    setSearchTimeout(BICYCLEPOWER_SEARCHTIMEOUT);
}

bool ProfileBicyclePowerSensor::isDataPageValid(uint8_t dataPage) {
    // TODO
    return true;
}
