#include <BaseClasses/ANTPLUS_BaseMasterProfile.h>

BaseMasterProfile::BaseMasterProfile(uint16_t deviceNumber) : BaseProfile(deviceNumber) {

}

void BaseMasterProfile::onChannelEventResponse(ChannelEventResponse& msg) {
    if (msg.getCode() == STATUS_EVENT_TX) {
        transmitNextDataPage();
    }
    BaseProfile::onChannelEventResponse(msg);
}