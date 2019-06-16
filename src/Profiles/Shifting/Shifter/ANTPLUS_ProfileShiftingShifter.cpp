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

    // some static aux messages (TODO preliminary solution)
    const uint8_t manufacturer[]  = { 0x50, 0xFF, 0xFF, 0x01, 0x0F, 0x00, 0x85, 0x83 };
    const uint8_t product[]       = { 0x51, 0xFF, 0xFF, 0x01, 0x01, 0x00, 0x00, 0x00 };

    if (_patternStep++ < 64) {
        transmitShiftingMainPageMsg();
    }
    else {
        // TODO manufacturer and product handling
        ShiftingBaseMainDataPageMsg msg;
        if (_toggle++ % 2 == 0)
            memcpy( msg.getDataBuffer(), manufacturer, MESSAGE_SIZE );
        else
			memcpy(msg.getDataBuffer(), product, MESSAGE_SIZE);
        // TODO battery status
        send(msg);
        _patternStep = 0;
    }
}

void ProfileShiftingShifter::transmitShiftingMainPageMsg() {
    ShiftingBaseMainDataPageMsg msg;
    _createShiftingDataMsg.call(msg);
    send(msg);
}

