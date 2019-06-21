#include <Profiles/Shifting/Shifter/ANTPLUS_ProfileShiftingShifter.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>


ProfileShiftingShifter::ProfileShiftingShifter( uint16_t deviceNumber, uint8_t transmissionType) :
    BaseMasterProfile(deviceNumber, transmissionType),
    _patternStep( 0 ),
    _toggle(0)
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
    if (_patternStep++ < 64) {
        transmitShiftingMainPageMsg();
    }
    else {

        if (_toggle++ % 2 == 0) {
            transmitShiftingManufacturerInformationMsg();
        }
        else {
            transmitShiftingProductInformationMsg();
        }
        // TODO battery status and some more pages
        _patternStep = 0;
    }
}

void ProfileShiftingShifter::transmitShiftingManufacturerInformationMsg() {
    ManufacturersInformationMsg msg;
    _createShiftingManufacturerInformationMsg.call(msg);
    send(msg);
}

void ProfileShiftingShifter::transmitShiftingProductInformationMsg() {
    ProductInformationMsg msg;
    _createShiftingProductInformationMsg.call(msg);
   send(msg);
}

void ProfileShiftingShifter::transmitShiftingMainPageMsg() {
    ShiftingBaseMainDataPageMsg msg;
    _createShiftingDataMsg.call(msg);
    send(msg);
}

