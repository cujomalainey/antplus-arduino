#include <Profiles/FitnessEquipmentControls/Profiles/ANTPLUS_FitnessEquipmentControlsProfileDisplay.h>
#include <Profiles/FitnessEquipmentControls/ANTPLUS_FitnessEquipmentControlsPrivateDefines.h>

ProfileFECDisplay::ProfileFECDisplay() : BaseSlaveProfile() {
    setChannelConfig();
}

ProfileFECDisplay::ProfileFECDisplay(uint16_t deviceNumber) : BaseSlaveProfile(deviceNumber) {
    setChannelConfig();
}

ProfileFECDisplay::ProfileFECDisplay(uint16_t deviceNumber, uint8_t transmissionType) : BaseSlaveProfile(deviceNumber, transmissionType) {
    setChannelConfig();
}

void ProfileFECDisplay::onBroadcastData(BroadcastData& msg) {
    BaseDataPage<BroadcastData> dp = BaseDataPage<BroadcastData>(msg);
    BaseSlaveProfile::onBroadcastData(msg);
    if (!handleDataPage(dp)) {
        callOnOtherDataPage(msg);
    }
}

bool ProfileFECDisplay::handleDataPage(BaseDataPage<BroadcastData>& dp) {
    uint8_t dataPage = dp.getDataPageNumber();
    bool called = false;

    switch (dataPage) {
    case ANTPLUS_FEC_DATAPAGE_TRAINER_DATA_NUMBER:
        called = handleTrainerData(dp);
        break;
    }

    return called;
}

void ProfileFECDisplay::onAcknowledgedData(AcknowledgedData& msg) {
    BaseDataPage<BroadcastData> dp = BaseDataPage<BroadcastData>(msg);
    BaseSlaveProfile::onAcknowledgedData(msg);
    if (!handleDataPage(dp)) {
        callOnOtherDataPage(msg);
    }
}


void ProfileFECDisplay::setChannelConfig() {
    setChannelType(ANTPLUS_FEC_DISPLAY_CHANNELTYPE);
    setDeviceType(ANTPLUS_FEC_DEVICETYPE);
    setChannelPeriod(ANTPLUS_FEC_CHANNELPERIOD);
    setSearchTimeout(ANTPLUS_FEC_SEARCHTIMEOUT);
}

bool ProfileFECDisplay::handleTrainerData(BaseDataPage<BroadcastData>& dataPage) {
    FECTrainerData dp = FECTrainerData(dataPage);
    return _onFECTrainerData.call(dp);
}
