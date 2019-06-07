#ifndef ANTPLUS_PROFILELEVDISPLAY_h
#define ANTPLUS_PROFILELEVDISPLAY_h

#include <BaseClasses/ANTPLUS_BaseSlaveProfile.h>
#include <Profiles/LEV/DataPages/ANTPLUS_ProfileLevDataPages.h>
#include <CommonDataPages/ANTPLUS_CommonDataPages.h>

#include "ANT.h"

class ProfileLevDisplay : public BaseSlaveProfile {
public:
    ProfileLevDisplay();
    ProfileLevDisplay(uint16_t deviceNumber);
    ProfileLevDisplay(uint16_t deviceNumber, uint8_t transmissionType);

	void onLevSpeedSysinfo1(void(*func)(LevSpeedSysinfo1&, uintptr_t), uintptr_t data = 0) { _onLevSpeedSysinfo1.set(func, data); }
	void onLevSpeedDist1(void(*func)(LevSpeedDist1&, uintptr_t), uintptr_t data = 0) { _onLevSpeedDist1.set(func, data); }
	void onLevSpeedDist2(void(*func)(LevSpeedDist2&, uintptr_t), uintptr_t data = 0) { _onLevSpeedDist2.set(func, data); }
	void onLevSpeedSysinfo2(void(*func)(LevSpeedSysinfo2&, uintptr_t), uintptr_t data = 0) { _onLevSpeedSysinfo2.set(func, data); }
	void onLevBatteryInfo(void(*func)(LevBatteryInfo&, uintptr_t), uintptr_t data = 0) { _onLevBatteryInfo.set(func, data); }
	void onLevCaps(void(*func)(LevCaps&, uintptr_t), uintptr_t data = 0) { _onLevCaps.set(func, data); }
	void onManufacturersInformation(void(*func)(ManufacturersInformation&, uintptr_t), uintptr_t data = 0) { _onManufacturersInformation.set(func, data); }
	void onProductInformation(void(*func)(ProductInformation&, uintptr_t), uintptr_t data = 0) { _onProductInformation.set(func, data); }

protected:
	// virtual void onChannelEventResponse(ChannelEventResponse& msg);

private:
    void setChannelConfig();
    void onBroadcastData(BroadcastData& msg);
    void onAcknowledgedData(AcknowledgedData& msg);

    bool handleDataPage(LevBaseMainDataPage& dataPage);
	bool handleSpeedSysinfo1(LevBaseMainDataPage& dataPage);
	bool handleSpeedDist1(LevBaseMainDataPage& dataPage);
	bool handleSpeedDist2(LevBaseMainDataPage& dataPage);
	bool handleSpeedSysinfo2(LevBaseMainDataPage& dataPage);
	bool handleBatteryInfo(LevBaseMainDataPage& dataPage);
	bool handleCaps(LevBaseMainDataPage& dataPage);
	bool handleManufacturersInformation(LevBaseMainDataPage& dataPage);
	bool handleProductInformation(LevBaseMainDataPage& dataPage);

	Callback<LevSpeedSysinfo1&> _onLevSpeedSysinfo1;
	Callback<LevSpeedDist1&> _onLevSpeedDist1;
	Callback<LevSpeedDist2&> _onLevSpeedDist2;
	Callback<LevSpeedSysinfo2&> _onLevSpeedSysinfo2;
	Callback<LevBatteryInfo&> _onLevBatteryInfo;
	Callback<LevCaps&> _onLevCaps;
	Callback<ManufacturersInformation&> _onManufacturersInformation;
	Callback<ProductInformation&> _onProductInformation;
};

#endif // ANTPLUS_PROFILELEVDISPLAY_h
