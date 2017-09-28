#include <BaseClasses/ANTPLUS_BaseSlaveProfile.h>
#include <ANTPLUS_PrivateDefines.h>

BaseSlaveProfile::BaseSlaveProfile() : BaseProfile(ANTPLUS_DEVICENUMBER_WILDCARD, ANTPLUS_TRANSMISSIONTYPE_WILDCARD) {

}

BaseSlaveProfile::BaseSlaveProfile(uint16_t deviceNumber) : BaseProfile(deviceNumber, ANTPLUS_TRANSMISSIONTYPE_WILDCARD) {

}

BaseSlaveProfile::BaseSlaveProfile(uint16_t deviceNumber, uint8_t transmissionType) : BaseProfile(deviceNumber, transmissionType) {

}
