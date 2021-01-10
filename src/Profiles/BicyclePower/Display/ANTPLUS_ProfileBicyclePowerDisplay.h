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
    void onBicyclePowerStandardPowerOnly(void (*func)(BicyclePowerStandardPowerOnly&, uintptr_t), uintptr_t data = 0) { _onBicyclePowerStandardPowerOnly.set(func, data); }
    void onBicyclePowerStandardCrankTorque(void (*func)(BicyclePowerStandardCrankTorque&, uintptr_t), uintptr_t data = 0) { _onBicyclePowerStandardCrankTorque.set(func, data); }
    void onBicyclePowerStandardWheelTorque(void (*func)(BicyclePowerStandardWheelTorque&, uintptr_t), uintptr_t data = 0) { _onBicyclePowerStandardWheelTorque.set(func, data); }
    void onBicyclePowerTorqueEffectivenessAndPedalSmoothness(void (*func)(BicyclePowerTorqueEffectivenessAndPedalSmoothness&, uintptr_t), uintptr_t data = 0) { _onBicyclePowerTorqueEffectivenessAndPedalSmoothness.set(func, data); }

private:
    void setChannelConfig();
    void onBroadcastData(BroadcastData& msg) override;
    void onAcknowledgedData(AcknowledgedData& msg) override;

    bool handleDataPage(BicyclePowerBaseMainDataPage& dp);

    bool handleBatteryStatus(BicyclePowerBaseMainDataPage& dataPage);
    bool handleCumulativeOperatingTime(BicyclePowerBaseMainDataPage& dataPage);
    bool handleManufacturerID(BicyclePowerBaseMainDataPage& dataPage);
    bool handleProductID(BicyclePowerBaseMainDataPage& dataPage);
    bool handleStandardPowerOnly(BicyclePowerBaseMainDataPage& dataPage);
    bool handleStandardCrankTorque(BicyclePowerBaseMainDataPage& dataPage);
    bool handleStandardWheelTorque(BicyclePowerBaseMainDataPage& dataPage);
    bool handleTorqueEffectivenessAndPedalSmoothness(BicyclePowerBaseMainDataPage& dataPage);
    AntCallback<BicyclePowerBatteryStatus&> _onBicyclePowerBatteryStatus;
    AntCallback<BicyclePowerCumulativeOperatingTime&> _onBicyclePowerCumulativeOperatingTime;
    AntCallback<BicyclePowerManufacturerID&> _onBicyclePowerManufacturerID;
    AntCallback<BicyclePowerProductID&> _onBicyclePowerProductID;
    AntCallback<BicyclePowerStandardPowerOnly&> _onBicyclePowerStandardPowerOnly;
    AntCallback<BicyclePowerStandardCrankTorque&> _onBicyclePowerStandardCrankTorque;
    AntCallback<BicyclePowerStandardWheelTorque&> _onBicyclePowerStandardWheelTorque;
    AntCallback<BicyclePowerTorqueEffectivenessAndPedalSmoothness&> _onBicyclePowerTorqueEffectivenessAndPedalSmoothness;
};

#endif // ANTPLUS_PROFILEBICYCLEPOWERDISPLAY_h
