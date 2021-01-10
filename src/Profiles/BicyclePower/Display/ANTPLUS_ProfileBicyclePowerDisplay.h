#ifndef ANTPLUS_PROFILEBICYCLEPOWERDISPLAY_h
#define ANTPLUS_PROFILEBICYCLEPOWERDISPLAY_h

#include <BaseClasses/ANTPLUS_BaseSlaveProfile.h>
#include <Profiles/BicyclePower/DataPages/ANTPLUS_ProfileBicyclePowerDataPages.h>
#include <CommonDataPages/ANTPLUS_CommonDataPages.h>

#include "ANT.h"

class ProfileBicyclePowerDisplay : public BaseSlaveProfile {
public:
    ProfileBicyclePowerDisplay();
    ProfileBicyclePowerDisplay(uint16_t deviceNumber);
    ProfileBicyclePowerDisplay(uint16_t deviceNumber, uint8_t transmissionType);
    void onBicyclePowerBatteryStatus(void (*func)(BicyclePowerBatteryStatus&, uintptr_t), uintptr_t data = 0) { _onBicyclePowerBatteryStatus.set(func, data); }
    void onBicyclePowerCumulativeOperatingTime(void (*func)(BicyclePowerCumulativeOperatingTime&, uintptr_t), uintptr_t data = 0) { _onBicyclePowerCumulativeOperatingTime.set(func, data); }
    void onBicyclePowerManufacturerID(void (*func)(BicyclePowerManufacturerID&, uintptr_t), uintptr_t data = 0) { _onBicyclePowerManufacturerID.set(func, data); }
    void onBicyclePowerProductID(void (*func)(BicyclePowerProductID&, uintptr_t), uintptr_t data = 0) { _onBicyclePowerProductID.set(func, data); }
    void onBicyclePowerPowerOnly(void (*func)(BicyclePowerPowerOnly&, uintptr_t), uintptr_t data = 0) { _onBicyclePowerPowerOnly.set(func, data); }
    void onBicyclePowerCrankTorque(void (*func)(BicyclePowerCrankTorque&, uintptr_t), uintptr_t data = 0) { _onBicyclePowerCrankTorque.set(func, data); }
    void onBicyclePowerWheelTorque(void (*func)(BicyclePowerWheelTorque&, uintptr_t), uintptr_t data = 0) { _onBicyclePowerWheelTorque.set(func, data); }
    void onBicyclePowerPedalSmoothness(void (*func)(BicyclePowerPedalSmoothness&, uintptr_t), uintptr_t data = 0) { _onBicyclePowerPedalSmoothness.set(func, data); }

private:
    void setChannelConfig();
    void onBroadcastData(BroadcastData& msg) override;
    void onAcknowledgedData(AcknowledgedData& msg) override;

    bool handleDataPage(BicyclePowerBaseMainDataPage& dp);

    bool handleBatteryStatus(BicyclePowerBaseMainDataPage& dataPage);
    bool handleCumulativeOperatingTime(BicyclePowerBaseMainDataPage& dataPage);
    bool handleManufacturerID(BicyclePowerBaseMainDataPage& dataPage);
    bool handleProductID(BicyclePowerBaseMainDataPage& dataPage);
    bool handlePowerOnly(BicyclePowerBaseMainDataPage& dataPage);
    bool handleCrankTorque(BicyclePowerBaseMainDataPage& dataPage);
    bool handleWheelTorque(BicyclePowerBaseMainDataPage& dataPage);
    bool handlePedalSmoothness(BicyclePowerBaseMainDataPage& dataPage);
    AntCallback<BicyclePowerBatteryStatus&> _onBicyclePowerBatteryStatus;
    AntCallback<BicyclePowerCumulativeOperatingTime&> _onBicyclePowerCumulativeOperatingTime;
    AntCallback<BicyclePowerManufacturerID&> _onBicyclePowerManufacturerID;
    AntCallback<BicyclePowerProductID&> _onBicyclePowerProductID;
    AntCallback<BicyclePowerPowerOnly&> _onBicyclePowerPowerOnly;
    AntCallback<BicyclePowerCrankTorque&> _onBicyclePowerCrankTorque;
    AntCallback<BicyclePowerWheelTorque&> _onBicyclePowerWheelTorque;
    AntCallback<BicyclePowerPedalSmoothness&> _onBicyclePowerPedalSmoothness;
};

#endif // ANTPLUS_PROFILEBICYCLEPOWERDISPLAY_h
