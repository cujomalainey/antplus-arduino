#ifndef ANTPLUS_PROFILEBICYCLESPEEDDISPLAY_h
#define ANTPLUS_PROFILEBICYCLESPEEDDISPLAY_h

#include <BaseClasses/ANTPLUS_BaseSlaveProfile.h>
#include <Profiles/BicycleSpeed/ANTPLUS_ProfileBicycleSpeedDataPages.h>
#include <CommonDataPages/ANTPLUS_CommonDataPages.h>

#include "ANT.h"

class ProfileBicycleSpeedDisplay : public BaseSlaveProfile {
public:
    ProfileBicycleSpeedDisplay();
    explicit ProfileBicycleSpeedDisplay(uint16_t deviceNumber);
    explicit ProfileBicycleSpeedDisplay(uint16_t deviceNumber, uint8_t transmissionType);
    void onBicycleSpeedBatteryStatus(void (*func)(BicycleSpeedBatteryStatus&, uintptr_t), uintptr_t data = 0) { _onBicycleSpeedBatteryStatus.set(func, data); }
    void onBicycleSpeedCumulativeOperatingTime(void (*func)(BicycleSpeedCumulativeOperatingTime&, uintptr_t), uintptr_t data = 0) { _onBicycleSpeedCumulativeOperatingTime.set(func, data); }
    void onBicycleSpeedDefault(void (*func)(BicycleSpeedDefault&, uintptr_t), uintptr_t data = 0) { _onBicycleSpeedDefault.set(func, data); }
    void onBicycleSpeedManufacturerID(void (*func)(BicycleSpeedManufacturerID&, uintptr_t), uintptr_t data = 0) { _onBicycleSpeedManufacturerID.set(func, data); }
    void onBicycleSpeedMotionAndSpeed(void (*func)(BicycleSpeedMotionAndSpeed&, uintptr_t), uintptr_t data = 0) { _onBicycleSpeedMotionAndSpeed.set(func, data); }
    void onBicycleSpeedProductID(void (*func)(BicycleSpeedProductID&, uintptr_t), uintptr_t data = 0) { _onBicycleSpeedProductID.set(func, data); }

private:
    void setChannelConfig();
    void onBroadcastData(BroadcastData& msg) override;
    void onAcknowledgedData(AcknowledgedData& msg) override;

    bool handleDataPage(BicycleSpeedBaseMainDataPage& dataPage);
    bool handleBatteryStatus(BicycleSpeedBaseMainDataPage& dataPage);
    bool handleCumulativeOperatingTime(BicycleSpeedBaseMainDataPage& dataPage);
    bool handleDefault(BicycleSpeedBaseMainDataPage& dataPage);
    bool handleManufacturerID(BicycleSpeedBaseMainDataPage& dataPage);
    bool handleMotionAndSpeed(BicycleSpeedBaseMainDataPage& dataPage);
    bool handleProductID(BicycleSpeedBaseMainDataPage& dataPage);
    AntCallback<BicycleSpeedBatteryStatus&> _onBicycleSpeedBatteryStatus;
    AntCallback<BicycleSpeedCumulativeOperatingTime&> _onBicycleSpeedCumulativeOperatingTime;
    AntCallback<BicycleSpeedDefault&> _onBicycleSpeedDefault;
    AntCallback<BicycleSpeedManufacturerID&> _onBicycleSpeedManufacturerID;
    AntCallback<BicycleSpeedMotionAndSpeed&> _onBicycleSpeedMotionAndSpeed;
    AntCallback<BicycleSpeedProductID&> _onBicycleSpeedProductID;
};

#endif // ANTPLUS_PROFILEBICYCLESPEEDDISPLAY_h
