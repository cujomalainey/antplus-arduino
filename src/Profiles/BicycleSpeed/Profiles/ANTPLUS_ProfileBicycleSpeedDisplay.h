#ifndef ANTPLUS_PROFILEBICYCLESPEEDDISPLAY_h
#define ANTPLUS_PROFILEBICYCLESPEEDDISPLAY_h

#include <BaseClasses/ANTPLUS_BaseSlaveProfile.h>
#include <Profiles/BicycleSpeed/ANTPLUS_BicycleSpeedDataPages.h>
#include <CommonDataPages/ANTPLUS_CommonDataPages.h>

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
    AntCallback<BicycleSpeedBatteryStatus&> _onBicycleSpeedBatteryStatus = { .func = NULL };
    AntCallback<BicycleSpeedCumulativeOperatingTime&> _onBicycleSpeedCumulativeOperatingTime = { .func = NULL };
    AntCallback<BicycleSpeedDefault&> _onBicycleSpeedDefault = { .func = NULL };
    AntCallback<BicycleSpeedManufacturerID&> _onBicycleSpeedManufacturerID = { .func = NULL };
    AntCallback<BicycleSpeedMotionAndSpeed&> _onBicycleSpeedMotionAndSpeed = { .func = NULL };
    AntCallback<BicycleSpeedProductID&> _onBicycleSpeedProductID = { .func = NULL };
};

#endif // ANTPLUS_PROFILEBICYCLESPEEDDISPLAY_h
