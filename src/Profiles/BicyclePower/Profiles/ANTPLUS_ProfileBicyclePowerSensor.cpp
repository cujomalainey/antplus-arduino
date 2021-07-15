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
    _flags(flags),
    _sensorType(BICYCLEPOWER_SENSORTYPE_POWERONLY) {
    // TODO add and parse flags to figure out sensor type
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
    uint8_t page = 0;
    if (isRequestedPagePending()) {
        transmitDataPage(getRequestedPage());
        return;
    }

    _patternStep++;
    if (_patternStep == 120) {
        _patternStep = 0;
    }

    switch (_sensorType) {
    case BICYCLEPOWER_SENSORTYPE_POWERONLY:
        page = getNextPowerOnlySensorPage();
        break;
    case BICYCLEPOWER_SENSORTYPE_TORQUEWHEEL:
    case BICYCLEPOWER_SENSORTYPE_TORQUECRANK:
        page = getNextTorqueSensorPage();
        break;
    case BICYCLEPOWER_SENSORTYPE_CTF:
        page = BICYCLEPOWER_CRANKTORQUEFREQUENCY_NUMBER;
        break;
    }

    transmitDataPage(page);
}

uint8_t ProfileBicyclePowerSensor::getNextPowerOnlySensorPage() {
    uint8_t backgroundPage;
    uint8_t mod_five = _patternStep % 5;

    if ((mod_five == 0) && _createBicyclePowerTorqueEffectivenessAndPedalSmoothnessMsg.func) {
        /* Interleave every 5th message if implemented */
        return BICYCLEPOWER_TORQUEEFFECTIVENESSANDPEDALSMOOTHNESS_NUMBER;
    }

    backgroundPage = getBackgroundPage();
    if (backgroundPage) {
        return backgroundPage;
    }
    return BICYCLEPOWER_STANDARDPOWERONLY_NUMBER;
}

uint8_t ProfileBicyclePowerSensor::getNextTorqueSensorPage() {
    uint8_t backgroundPage;
    uint8_t mod_five = _patternStep % 5;

    if (mod_five == 0) {
        /* Interleave every 5th message */
        return BICYCLEPOWER_STANDARDPOWERONLY_NUMBER;
    } else if ((mod_five == 1) && _createBicyclePowerTorqueEffectivenessAndPedalSmoothnessMsg.func) {
        /* Interleave every 5th message if implemented */
        return BICYCLEPOWER_TORQUEEFFECTIVENESSANDPEDALSMOOTHNESS_NUMBER;
    }

    backgroundPage = getBackgroundPage();
    if (backgroundPage) {
        return backgroundPage;
    }

    return _sensorType == BICYCLEPOWER_SENSORTYPE_TORQUECRANK ?
        BICYCLEPOWER_STANDARDCRANKTORQUE_NUMBER : BICYCLEPOWER_STANDARDWHEELTORQUE_NUMBER;
}


bool ProfileBicyclePowerSensor::handleRequestDataPage(BicyclePowerStandardPowerOnly& dataPage) {
    RequestDataPage dp(dataPage);
    return _onRequestDataPage.call(dp);
}

bool ProfileBicyclePowerSensor::handleGeneralCalibration(BicyclePowerStandardPowerOnly& dataPage) {
    // TODO
    return false;
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

void ProfileBicyclePowerSensor::transmitBatteryStatusMsg() {
    BatteryStatusMsg msg;
    _createBatteryStatusMsg.call(msg);
    transmitMsg(msg);
}

void ProfileBicyclePowerSensor::transmitBicyclePowerGeneralCalibrationResponse() {
    // TODO
}

uint8_t ProfileBicyclePowerSensor::getBackgroundPage() {
    /* Note: on logic behind numbers here
     *
     * Messages are on 5 page period, so first 2 slots (i.e N % 5 = 0 and N % 5 = 1) are
     * Main page 1
     * Main page 2
     * These slots may not actually be used but given this is configurable this makes it safe
     *
     * last 3 slots are synced in background pages in sub minimum requirement
     * The magic numbers are N % 5 > 1 and are within the period assuming the counter
     * resets on a 120 message period
     *
     * Verification
     * 118 % 5 = 3
     * 119 % 5 = 4
     * 33 % 5 = 3
     * 93 % 5 = 3
     * */

    if (_patternStep == 118) {
        return COMMON_MANUFACTURERSINFORMATION_NUMBER;
    }

    if (_patternStep == 119) {
        return COMMON_PRODUCTINFORMATION_NUMBER;
    }

    if ((_patternStep == 33 || _patternStep == 93) && _createBatteryStatusMsg.func) {
        return COMMON_BATTERYSTATUS_NUMBER;
    }

    /* we don't have anything to transmit */
    return 0;
}

void ProfileBicyclePowerSensor::transmitDataPage(uint8_t page) {
    switch (page) {
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
    case COMMON_BATTERYSTATUS_NUMBER:
        transmitBatteryStatusMsg();
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
    // TODO calibration data pages
    switch (dataPage) {
    case BICYCLEPOWER_STANDARDPOWERONLY_NUMBER:
        return _sensorType != BICYCLEPOWER_SENSORTYPE_CTF;
    case BICYCLEPOWER_STANDARDWHEELTORQUE_NUMBER:
        return _sensorType == BICYCLEPOWER_SENSORTYPE_TORQUEWHEEL;
    case BICYCLEPOWER_STANDARDCRANKTORQUE_NUMBER:
        return _sensorType == BICYCLEPOWER_SENSORTYPE_TORQUECRANK;
    case BICYCLEPOWER_TORQUEEFFECTIVENESSANDPEDALSMOOTHNESS_NUMBER:
        return _sensorType != BICYCLEPOWER_SENSORTYPE_CTF &&
            (bool)_createBicyclePowerTorqueEffectivenessAndPedalSmoothnessMsg.func;
    case BICYCLEPOWER_CRANKTORQUEFREQUENCY_NUMBER:
        return _sensorType == BICYCLEPOWER_SENSORTYPE_CTF;
    case COMMON_BATTERYSTATUS_NUMBER:
        return (bool)_createBatteryStatusMsg.func;
    case COMMON_PRODUCTINFORMATION_NUMBER:
    case COMMON_MANUFACTURERSINFORMATION_NUMBER:
        return true;
    default:
        return false;
    }
}
