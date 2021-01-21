#include <Profiles/Fec/Profiles/ANTPLUS_FecProfileDisplay.h>
#include <Profiles/Fec/ANTPLUS_FecPrivateDefines.h>

ProfileFecDisplay::ProfileFecDisplay() : BaseSlaveProfile() {
    setChannelConfig();
}

ProfileFecDisplay::ProfileFecDisplay(uint16_t deviceNumber) : BaseSlaveProfile(deviceNumber) {
    setChannelConfig();
}

ProfileFecDisplay::ProfileFecDisplay(uint16_t deviceNumber, uint8_t transmissionType) : BaseSlaveProfile(deviceNumber, transmissionType) {
    setChannelConfig();
}

void ProfileFecDisplay::onBroadcastData(BroadcastData& msg) {
    BaseDataPage<BroadcastData> dp = BaseDataPage<BroadcastData>(msg);
    BaseSlaveProfile::onBroadcastData(msg);
    if (!handleDataPage(dp)) {
        callOnOtherDataPage(msg);
    }
}

bool ProfileFecDisplay::handleDataPage(BaseDataPage<BroadcastData>& dp) {
    uint8_t dataPage = dp.getDataPageNumber();
    bool called = false;

    switch (dataPage) {
    case ANTPLUS_FEC_DATAPAGE_TRAINER_DATA_NUMBER:
        called = handleTrainerData(dp);
        break;
    }

    return called;
}

void ProfileFecDisplay::onAcknowledgedData(AcknowledgedData& msg) {
    BaseDataPage<BroadcastData> dp = BaseDataPage<BroadcastData>(msg);
    BaseSlaveProfile::onAcknowledgedData(msg);
    if (!handleDataPage(dp)) {
        callOnOtherDataPage(msg);
    }
}


void ProfileFecDisplay::setChannelConfig() {
    setChannelType(ANTPLUS_FEC_DISPLAY_CHANNELTYPE);
    setDeviceType(ANTPLUS_FEC_DEVICETYPE);
    setChannelPeriod(ANTPLUS_FEC_CHANNELPERIOD);
    setSearchTimeout(ANTPLUS_FEC_SEARCHTIMEOUT);
}

bool ProfileFecDisplay::handleTrainerData(BaseDataPage<BroadcastData>& dataPage) {
    FecSpecificTrainerData dp(dataPage);
    return _onFecSpecificTrainerData.call(dp);
}
