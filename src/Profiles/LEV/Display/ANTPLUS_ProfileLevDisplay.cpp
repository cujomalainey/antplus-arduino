#include <Profiles/LEV/Display/ANTPLUS_ProfileLevDisplay.h>
#include <Profiles/LEV/ANTPLUS_LevPrivateDefines.h>
#include <CommonDataPages/RX/ANTPLUS_ModeSettings.h>
#include <CommonDataPages/ANTPLUS_CommonDataPagePrivateDefines.h>

ProfileLevDisplay::ProfileLevDisplay() : BaseSlaveProfile() {
    setChannelConfig();
}

ProfileLevDisplay::ProfileLevDisplay(uint16_t deviceNumber) : BaseSlaveProfile(deviceNumber) {
    setChannelConfig();
}

ProfileLevDisplay::ProfileLevDisplay(uint16_t deviceNumber, uint8_t transmissionType) : BaseSlaveProfile(deviceNumber, transmissionType) {
    setChannelConfig();
}

void ProfileLevDisplay::setChannelConfig() {
	setChannelType(ANTPLUS_LEV_CHANNELTYPE);
	setDeviceType(ANTPLUS_LEV_DEVICETYPE);
	setChannelPeriod(ANTPLUS_LEV_CHANNELPERIOD);
	setSearchTimeout(ANTPLUS_LEV_SEARCHTIMEOUT);
}

void ProfileLevDisplay::onBroadcastData(BroadcastData& msg) {
	BaseProfile::onBroadcastData(msg);
    LevBaseMainDataPage dp = LevBaseMainDataPage(msg);
    if (!handleDataPage(dp)) {
        callOnOtherDataPage(msg);
    }
}

void ProfileLevDisplay::onAcknowledgedData(AcknowledgedData& msg) {
	BaseProfile::onAcknowledgedData(msg);
	LevBaseMainDataPage dp = LevBaseMainDataPage(msg);
	if (!handleDataPage(dp)) {
		callOnOtherDataPage(msg);
	}
}

/*
void ProfileLevDisplay::onChannelEventResponse(ChannelEventResponse& msg) {
	Serial.print("lev event: ");
	Serial.println(msg.getCode());
}*/

bool ProfileLevDisplay::handleDataPage(LevBaseMainDataPage& dp) {
    uint8_t dataPage = dp.getDataPageNumber();
    bool called = false;

	switch (dataPage) {

	case ANTPLUS_LEV_DATAPAGE_SPEEDSYSINFO1_NUMBER:
		called = handleSpeedSysinfo1(dp);
		break;
	case ANTPLUS_LEV_DATAPAGE_SPEEDDIST1_NUMBER:
		called = handleSpeedDist1(dp);
		break;
	case ANTPLUS_LEV_DATAPAGE_SPEEDDIST2_NUMBER:
		called = handleSpeedDist2(dp);
		break;
	case ANTPLUS_LEV_DATAPAGE_SPEEDSYSINFO2_NUMBER:
		called = handleSpeedSysinfo2(dp);
		break;
	case ANTPLUS_LEV_DATAPAGE_BATTERYINFO_NUMBER:
		called = handleBatteryInfo(dp);
		break;
	case ANTPLUS_LEV_DATAPAGE_CAPS_NUMBER:
		called = handleCaps(dp);
		break;
	case ANTPLUS_COMMON_DATAPAGE_MANUFACTURERSINFORMATION_NUMBER:
		// Called Manufacturers Identification in Environment Profile PDF
		called = handleManufacturersInformation(dp);
		break;
	case ANTPLUS_COMMON_DATAPAGE_PRODUCTINFORMATION_NUMBER:
		called = handleProductInformation(dp);
		break;
	}
    return called;
}

bool ProfileLevDisplay::handleSpeedSysinfo1(LevBaseMainDataPage& dataPage) {
	LevSpeedSysinfo1 dp = LevSpeedSysinfo1(dataPage);
	return _onLevSpeedSysinfo1.call(dp);
}

bool ProfileLevDisplay::handleSpeedDist1(LevBaseMainDataPage& dataPage) {
	LevSpeedDist1 dp = LevSpeedDist1(dataPage);
	return _onLevSpeedDist1.call(dp);
}

bool ProfileLevDisplay::handleSpeedDist2(LevBaseMainDataPage& dataPage) {
	LevSpeedDist2 dp = LevSpeedDist2(dataPage);
	return _onLevSpeedDist2.call(dp);
}

bool ProfileLevDisplay::handleSpeedSysinfo2(LevBaseMainDataPage& dataPage) {
	LevSpeedSysinfo2 dp = LevSpeedSysinfo2(dataPage);
	return _onLevSpeedSysinfo2.call(dp);
}

bool ProfileLevDisplay::handleBatteryInfo(LevBaseMainDataPage& dataPage) {
	LevBatteryInfo dp = LevBatteryInfo(dataPage);
	return _onLevBatteryInfo.call(dp);
}

bool ProfileLevDisplay::handleCaps(LevBaseMainDataPage& dataPage) {
	LevCaps dp = LevCaps(dataPage);
	return _onLevCaps.call(dp);
}

bool ProfileLevDisplay::handleManufacturersInformation(LevBaseMainDataPage& dataPage) {
	ManufacturersInformation dp = ManufacturersInformation(dataPage);
	return _onManufacturersInformation.call(dp);
}

bool ProfileLevDisplay::handleProductInformation(LevBaseMainDataPage& dataPage) {
	ProductInformation dp = ProductInformation(dataPage);
	return _onProductInformation.call(dp);
}
