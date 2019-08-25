#include <Profiles/Shifting/Shifter/ANTPLUS_ProfileShiftingShifter.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>

#define INTERLEAVE_STEP 65

ProfileShiftingShifter::ProfileShiftingShifter(uint16_t deviceNumber, uint8_t transmissionType) :
    BaseMasterProfile(deviceNumber, transmissionType),
    _patternStep(0),
    _backgroundStep(0),
    _shiftCounter(0)
{
    setChannelConfig();
}

void ProfileShiftingShifter::setChannelConfig() {
    setChannelType(ANTPLUS_SHIFTING_SHIFTER_CHANNELTYPE);
    setDeviceType(ANTPLUS_SHIFTING_DEVICETYPE);
    setChannelPeriod(ANTPLUS_SHIFTING_CHANNELPERIOD);
    setSearchTimeout(ANTPLUS_SHIFTING_SEARCHTIMEOUT);
}

bool ProfileShiftingShifter::isDataPageValid(uint8_t dataPage)
{
    switch (dataPage) {
    case ANTPLUS_SHIFTING_DATAPAGE_SHIFTSYSTEMSTATUS_NUMBER:
    case ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_NUMBER:
    case ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_NUMBER:
    case ANTPLUS_COMMON_DATAPAGE_BATTERYSTATUS_NUMBER:
        return true;
    }
    return false;
}

void ProfileShiftingShifter::transmitNextDataPage() {
    if (_patternStep++ < INTERLEAVE_STEP || _shiftCounter--) {
        transmitShiftingMainPageMsg();
    } else {
        transmitBackgroundDataPage();
        _patternStep -= INTERLEAVE_STEP;
    }
}

void ProfileShiftingShifter::transmitBackgroundDataPage() {
    _backgroundStep += 1;
    switch (_backgroundStep) {
    case 0:
        transmitMultiComponentSystemManufacturersInformationMsg();
        break;
    case 1:
        transmitMultiComponentSystemProductInformationMsg();
        break;
    case 2:
        transmitBatteryStatusMsg();
        // prevent roll overs
        _backgroundStep = 0;
        break;
    }
}

void ProfileShiftingShifter::onBroadcastData(BroadcastData& msg) {
    BaseDataPage<BroadcastData> dp(msg);
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

void ProfileShiftingShifter::onAcknowledgedData(AcknowledgedData& msg) {
    BaseDataPage<AcknowledgedData> dp(msg);
    uint8_t dataPage = dp.getDataPageNumber();
    bool called = false;

    BaseMasterProfile::onAcknowledgedData(msg);

    switch (dataPage) {

    case ANTPLUS_COMMON_DATAPAGE_REQUESTDATAPAGE_NUMBER:
        called = handleRequestDataPage(dp);
        break;
    }

    if (!called) {
        callOnOtherDataPage(msg);
    }
}

void ProfileShiftingShifter::transmitMultiComponentSystemManufacturersInformationMsg() {
    MultiComponentSystemManufacturersInformationMsg msg;
    _createMultiComponentSystemManufacturersInformationMsg.call(msg);
    transmitMsg(msg);
}

void ProfileShiftingShifter::transmitMultiComponentSystemProductInformationMsg() {
    MultiComponentSystemProductInformationMsg msg;
    _createMultiComponentSystemProductInformationMsg.call(msg);
    transmitMsg(msg);
}

void ProfileShiftingShifter::transmitBatteryStatusMsg() {
    BatteryStatusMsg msg;
    _createBatteryStatusMsg.call(msg);
    transmitMsg(msg);
}

void ProfileShiftingShifter::transmitShiftingMainPageMsg() {
    ShiftingShiftSystemStatusMsg msg;
    _createShiftingShiftSystemStatusMsg.call(msg);
    // TODO track shifting internally and adjust transmission pattern accodingly (if shifter _shiftCounter = 4);
    transmitMsg(msg);
}

bool ProfileShiftingShifter::handleRequestDataPage(BaseDataPage<AcknowledgedData>& dataPage) {
    RequestDataPage dp(dataPage);
    // TODO disable use of ack messages as per spec
    return _onRequestDataPage.call(dp);
}
