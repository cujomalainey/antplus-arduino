#include <Profiles/Shifting/Shifter/ANTPLUS_ProfileShiftingShifter.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>

#define INTERLEAVE_STEP 65

ProfileShiftingShifter::ProfileShiftingShifter(uint16_t deviceNumber, uint8_t transmissionType) :
    BaseMasterProfile(deviceNumber, transmissionType),
    _patternStep(0),
    _backgroundStep(0)
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
        return true;
    // TODO other datapages
    }
    return false;
}

void ProfileShiftingShifter::transmitNextDataPage() {
    // TODO the pattern needs to adjust in when a shift event occurs
    if (_patternStep++ < INTERLEAVE_STEP) {
        transmitShiftingMainPageMsg();
    } else {
        transmitBackgroundDataPage();
        _patternStep = 0;
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
    transmitMsg(msg);
}

