#include <Profiles/Shifting/Shifter/ANTPLUS_ProfileShiftingShifter.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>
#include <Profiles/Shifting/ANTPLUS_ShiftingDefines.h>

ProfileShiftingShifter::ProfileShiftingShifter(uint16_t deviceNumber, uint8_t transmissionType, uint16_t componentFlags) :
    BaseMasterProfile(deviceNumber, transmissionType),
    _componentFlags(componentFlags)
{
    setChannelConfig();
    setAckMessageUsage(false);

    if (isMultiComponentDevice()) {
        // calculate interleave step
        while (componentFlags) {
            componentFlags &= (componentFlags - 1);
            _componentCount++;
        }
    } else {
        _componentCount = 1;
        _componentState = 0xF;
    }
    _interleaveStep = ANTPLUS_SHIFTING_BACKGROUNDPAGE_INTERLEAVEINTERVAL /
        (ANTPLUS_SHIFTING_NUMBERBACKGROUNDPAGES_PERCOMPONENT * _componentCount);
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
    if (_patternStep++ < _interleaveStep || _shiftCounter--) {
        transmitShiftingMainPageMsg();
    } else {
        transmitBackgroundDataPage();
        _patternStep -= _interleaveStep;
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

        // Don't adjust state if we are handling a request
        if (isMultiComponentDevice() && !isRequestedPagePending()) {
            // knock out component bit
            _componentState &= (_componentState - 1);

            if (!_componentState) {
                // reset back to first component
                _componentState = _componentFlags;
            }
        }
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

bool ProfileShiftingShifter::isMultiComponentDevice() {
    return _componentFlags != ANTPLUS_SHIFTING_COMPONENTIDENTIFIER_NOTUSED;
}

bool ProfileShiftingShifter::isSupportedComponent(uint8_t id) {
    return _componentFlags & (1 << id);
}

uint8_t ProfileShiftingShifter::getLowestBitPosition(uint16_t id) {
    uint16_t lowestBitUnset = id & (id - 1);
    uint8_t count = 0;
    id ^= lowestBitUnset;
    while (id) {
        id >>= 1;
        count++;
    }
    return count - 1;
}

void ProfileShiftingShifter::transmitMultiComponentSystemManufacturersInformationMsg() {
    MultiComponentSystemManufacturersInformationMsg msg;
    msg.setComponentIdentifier(getLowestBitPosition(_componentState));
    msg.setNumberOfComponents(_componentCount);
    _createMultiComponentSystemManufacturersInformationMsg.call(msg);
    transmitMsg(msg);
}

void ProfileShiftingShifter::transmitMultiComponentSystemProductInformationMsg() {
    MultiComponentSystemProductInformationMsg msg;
    msg.setComponentIdentifier(getLowestBitPosition(_componentState));
    msg.setNumberOfComponents(_componentCount);
    _createMultiComponentSystemProductInformationMsg.call(msg);
    transmitMsg(msg);
}

void ProfileShiftingShifter::transmitBatteryStatusMsg() {
    BatteryStatusMsg msg;
    msg.setBatteryIdentifier(getLowestBitPosition(_componentState));
    msg.setNumberOfBatteries(_componentCount);
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
    uint8_t dataPageRequestedNumber = dp.getRequestedPageNumber();

    switch (dataPageRequestedNumber) {
    case ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMMANUFACTURERSINFORMATION_NUMBER:
    case ANTPLUS_COMMON_DATAPAGE_MULTICOMPONENTSYSTEMPRODUCTINFORMATION_NUMBER:
    case ANTPLUS_COMMON_DATAPAGE_BATTERYSTATUS_NUMBER:
        break;
    default:
        // skip check if not multicomponent message
        return _onRequestDataPage.call(dp);
    }

    // invalidate invalid component requests
    if (isMultiComponentDevice()) {
        if (isSupportedComponent(dp.getDescriptorByte1())) {
            // override transmission state, will automatically reset after
            _componentState = 1 << dp.getDescriptorByte1();
        } else {
            invalidateDataPageRequest();
        }
    }

    return _onRequestDataPage.call(dp);
}
