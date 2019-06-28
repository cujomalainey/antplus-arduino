#include <BaseClasses/ANTPLUS_BaseSlaveProfile.h>
#include <ANTPLUS_PrivateDefines.h>

BaseSlaveProfile::BaseSlaveProfile() : BaseProfile(ANTPLUS_DEVICENUMBER_WILDCARD, ANTPLUS_TRANSMISSIONTYPE_WILDCARD) {

}

BaseSlaveProfile::BaseSlaveProfile(uint16_t deviceNumber) : BaseProfile(deviceNumber, ANTPLUS_TRANSMISSIONTYPE_WILDCARD) {

}

BaseSlaveProfile::BaseSlaveProfile(uint16_t deviceNumber, uint8_t transmissionType) : BaseProfile(deviceNumber, transmissionType) {

}

uint8_t BaseSlaveProfile::waitForPair() {
    // TODO add a timeout in the event packed was dropped?
    while (getChannelStatus() == CHANNEL_STATUS_SEARCHING) {
        // If a event saying we disconnected happened then we will check it, otherwise wait for data to come in
        loop();
    }
    return getChannelStatus();
}
