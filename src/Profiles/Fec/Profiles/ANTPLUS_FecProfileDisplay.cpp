#include <Profiles/Fec/Profiles/ANTPLUS_FecProfileDisplay.h>
#include <Profiles/Fec/ANTPLUS_FecPrivateDefines.h>
#include <CommonDataPages/ANTPLUS_CommonDataPageDefines.h>

#define DISPLAY_CHANNELTYPE CHANNEL_TYPE_BIDIRECTIONAL_RECEIVE

ProfileFecDisplay::ProfileFecDisplay(uint16_t deviceNumber, uint8_t transmissionType) : BaseSlaveProfile(deviceNumber, transmissionType) {
    setChannelConfig();
}

void ProfileFecDisplay::onBroadcastData(BroadcastData& msg) {
    FecBaseMainDataPage dp(msg);
    BaseSlaveProfile::onBroadcastData(msg);
    if (!handleDataPage(dp)) {
        callOnOtherDataPage(msg);
    }
}

bool ProfileFecDisplay::handleDataPage(FecBaseMainDataPage& dp) {
    uint8_t dataPage = dp.getDataPageNumber();
    bool called = false;

    switch (dataPage) {
    case ANTPLUS_FEC_DATAPAGE_SPECIFICTRAINERDATA_NUMBER:
        called = handleTrainerData(dp);
        break;

    case ANTPLUS_COMMON_DATAPAGE_MANUFACTURERSINFORMATION_NUMBER:
        called = handleManufacturerInformation(dp);
        break;

    case ANTPLUS_COMMON_DATAPAGE_PRODUCTINFORMATION_NUMBER:
        called = handleProductInformation(dp);
        break;

    case ANTPLUS_FEC_DATAPAGE_GENERALFEDATA_NUMBER:
        called = handleGeneralFeData(dp);
        break;

    case ANTPLUS_FEC_DATAPAGE_GENERALSETTINGSPAGE_NUMBER:
        called = handleGeneralSettingsPage(dp);
        break;

    case ANTPLUS_FEC_DATAPAGE_FECAPABILITIES_NUMBER:
        called = handleFeCapabilities(dp);
        break;
    }

    return called;
}

void ProfileFecDisplay::onAcknowledgedData(AcknowledgedData& msg) {
    FecBaseMainDataPage dp = FecBaseMainDataPage(msg);
    BaseSlaveProfile::onAcknowledgedData(msg);
    if (!handleDataPage(dp)) {
        callOnOtherDataPage(msg);
    }
}

void ProfileFecDisplay::setChannelConfig() {
    setChannelType(DISPLAY_CHANNELTYPE);
    setDeviceType(ANTPLUS_FEC_REALTIMECHANNEL_DEVICETYPE);
    setChannelPeriod(ANTPLUS_FEC_CHANNELPERIOD);
    setSearchTimeout(ANTPLUS_FEC_SEARCHTIMEOUT);
}

bool ProfileFecDisplay::handleManufacturerInformation(FecBaseMainDataPage& dataPage) {
    ManufacturersInformation dp(dataPage);
    return _onManufacturersInformation.call(dp);
}

bool ProfileFecDisplay::handleProductInformation(FecBaseMainDataPage& dataPage) {
    ProductInformation dp(dataPage);
    return _onProductInformation.call(dp);
}

bool ProfileFecDisplay::handleGeneralFeData(FecBaseMainDataPage& dataPage) {
    FecGeneralFeData dp(dataPage);
    return _onFecGeneralFeData.call(dp);
}

bool ProfileFecDisplay::handleGeneralSettingsPage(FecBaseMainDataPage& dataPage) {
    FecGeneralSettingsPage dp(dataPage);
    return _onFecGeneralSettingsPage.call(dp);
}

bool ProfileFecDisplay::handleFeCapabilities(FecBaseMainDataPage& dataPage) {
    FecFeCapabilities dp(dataPage);
    return _onFecFeCapabilities.call(dp);
}

bool ProfileFecDisplay::handleTrainerData(FecBaseMainDataPage& dataPage) {
    FecSpecificTrainerData dp(dataPage);
    return _onFecSpecificTrainerData.call(dp);
}
