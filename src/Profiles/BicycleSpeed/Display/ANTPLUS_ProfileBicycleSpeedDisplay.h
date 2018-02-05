#ifndef ANTPLUS_PROFILEBICYCLESPEEDDISPLAY_h
#define ANTPLUS_PROFILEBICYCLESPEEDDISPLAY_h

#include <BaseClasses/ANTPLUS_BaseSlaveProfile.h>
#include <Profiles/BicycleSpeed/DataPages/ANTPLUS_ProfileBicycleSpeedDataPages.h>
#include <CommonDataPages/ANTPLUS_CommonDataPages.h>

#include "ANT.h"

class ProfileBicycleSpeedDisplay : public BaseSlaveProfile {
public:
    ProfileBicycleSpeedDisplay();
    ProfileBicycleSpeedDisplay(uint16_t deviceNumber);
    ProfileBicycleSpeedDisplay(uint16_t deviceNumber, uint8_t transmissionType);
    void onBicycleSpeedBatteryStatus(void (*func)(BicycleSpeedBatteryStatus&, uintptr_t), uintptr_t data = 0) { _onBicycleSpeedBatteryStatus.set(func, data); }
    void onBicycleSpeedCumulativeOperatingTime(void (*func)(BicycleSpeedCumulativeOperatingTime&, uintptr_t), uintptr_t data = 0) { _onBicycleSpeedCumulativeOperatingTime.set(func, data); }
    void onBicycleSpeedDefault(void (*func)(BicycleSpeedDefault&, uintptr_t), uintptr_t data = 0) { _onBicycleSpeedDefault.set(func, data); }
    void onBicycleSpeedManufacturerID(void (*func)(BicycleSpeedManufacturerID&, uintptr_t), uintptr_t data = 0) { _onBicycleSpeedManufacturerID.set(func, data); }
    void onBicycleSpeedMotionAndSpeed(void (*func)(BicycleSpeedMotionAndSpeed&, uintptr_t), uintptr_t data = 0) { _onBicycleSpeedMotionAndSpeed.set(func, data); }
    void onBicycleSpeedProductID(void (*func)(BicycleSpeedProductID&, uintptr_t), uintptr_t data = 0) { _onBicycleSpeedProductID.set(func, data); }

private:
    void setChannelConfig();
    void onBroadcastData(BroadcastData& msg);
    void onAcknowledgedData(AcknowledgedData& msg);

    bool handleDataPage(BicycleSpeedBaseMainDataPage& dataPage);
    bool handleBatteryStatus(BicycleSpeedBaseMainDataPage& dataPage);
    bool handleCumulativeOperatingTime(BicycleSpeedBaseMainDataPage& dataPage);
    bool handleDefault(BicycleSpeedBaseMainDataPage& dataPage);
    bool handleManufacturerID(BicycleSpeedBaseMainDataPage& dataPage);
    bool handleMotionAndSpeed(BicycleSpeedBaseMainDataPage& dataPage);
    bool handleProductID(BicycleSpeedBaseMainDataPage& dataPage);
    Callback<BicycleSpeedBatteryStatus&> _onBicycleSpeedBatteryStatus;
    Callback<BicycleSpeedCumulativeOperatingTime&> _onBicycleSpeedCumulativeOperatingTime;
    Callback<BicycleSpeedDefault&> _onBicycleSpeedDefault;
    Callback<BicycleSpeedManufacturerID&> _onBicycleSpeedManufacturerID;
    Callback<BicycleSpeedMotionAndSpeed&> _onBicycleSpeedMotionAndSpeed;
    Callback<BicycleSpeedProductID&> _onBicycleSpeedProductID;
};

#endif // ANTPLUS_PROFILEBICYCLESPEEDDISPLAY_h
