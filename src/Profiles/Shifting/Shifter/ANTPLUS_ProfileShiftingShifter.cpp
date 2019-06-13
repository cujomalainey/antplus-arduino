#include <Profiles/Shifting/Shifter/ANTPLUS_ProfileShiftingShifter.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>


ProfileShiftingShifter::ProfileShiftingShifter(	uint16_t deviceNumber, uint8_t transmissionType) :
    BaseMasterProfile(deviceNumber, transmissionType),
    _patternStep( 0 ),
    _toggle(0),
    _eventCount( 0 )
{
    setChannelConfig();
}

void ProfileShiftingShifter::setChannelConfig() {
    setChannelType(ANTPLUS_SHIFTING_MASTER_CHANNELTYPE);
    setDeviceType(ANTPLUS_SHIFTING_DEVICETYPE);
    setChannelPeriod(ANTPLUS_SHIFTING_CHANNELPERIOD);
    setSearchTimeout(ANTPLUS_SHIFTING_SEARCHTIMEOUT);
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
        ShiftingBaseGenericMsg msg;
        if (_toggle++ % 1 == 0)
            msg.copyData((uint8_t*)manufacturer, MESSAGE_SIZE);
        else
            msg.copyData((uint8_t*)product, MESSAGE_SIZE);
        send(msg);
        _patternStep = 0;
    }
}

void ProfileShiftingShifter::transmitShiftingMainPageMsg() {
    ShiftingBaseMainDataPageMsg msg;
    msg.setEventCount(_eventCount);
    if( _patternStep % 4 == 0 ) // TODO make event count time dependent
      _eventCount++;
    _createShiftingDataMsg.call(msg);
    send(msg);
}

