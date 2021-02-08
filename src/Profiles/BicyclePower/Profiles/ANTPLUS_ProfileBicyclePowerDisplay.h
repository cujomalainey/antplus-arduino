#ifndef ANTPLUS_PROFILEBICYCLEPOWERDISPLAY_h
#define ANTPLUS_PROFILEBICYCLEPOWERDISPLAY_h

#include <BaseClasses/ANTPLUS_BaseSlaveProfile.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerDataPages.h>
#include <CommonDataPages/ANTPLUS_CommonDataPages.h>

class ProfileBicyclePowerDisplay : public BaseSlaveProfile {
public:
    ProfileBicyclePowerDisplay(uint16_t deviceNumber = 0, uint8_t transmissionType = 0);
    void onBatteryStatus(void (*func)(BatteryStatus&, uintptr_t), uintptr_t data = 0) { _onBatteryStatus.set(func, data); }
    void onManufacturersInformation(void (*func)(ManufacturersInformation&, uintptr_t), uintptr_t data = 0) { _onManufacturersInformation.set(func, data); }
    void onProductInformation(void (*func)(ProductInformation&, uintptr_t), uintptr_t data = 0) { _onProductInformation.set(func, data); }
    void onBicyclePowerStandardPowerOnly(void (*func)(BicyclePowerStandardPowerOnly&, uintptr_t), uintptr_t data = 0) { _onBicyclePowerStandardPowerOnly.set(func, data); }
    void onBicyclePowerStandardCrankTorque(void (*func)(BicyclePowerStandardCrankTorque&, uintptr_t), uintptr_t data = 0) { _onBicyclePowerStandardCrankTorque.set(func, data); }
    void onBicyclePowerStandardWheelTorque(void (*func)(BicyclePowerStandardWheelTorque&, uintptr_t), uintptr_t data = 0) { _onBicyclePowerStandardWheelTorque.set(func, data); }
    void onBicyclePowerCrankTorqueFrequency(void (*func)(BicyclePowerCrankTorqueFrequency&, uintptr_t), uintptr_t data = 0) { _onBicyclePowerCrankTorqueFrequency.set(func, data); }
    void onBicyclePowerTorqueEffectivenessAndPedalSmoothness(void (*func)(BicyclePowerTorqueEffectivenessAndPedalSmoothness&, uintptr_t), uintptr_t data = 0) { _onBicyclePowerTorqueEffectivenessAndPedalSmoothness.set(func, data); }

private:
    void setChannelConfig();
    void onBroadcastData(BroadcastData& msg) override;
    void onAcknowledgedData(AcknowledgedData& msg) override;

    bool handleDataPage(BicyclePowerBaseMainDataPage& dp);

    bool handleBatteryStatus(BicyclePowerBaseMainDataPage& dataPage);
    bool handleManufacturersInformation(BicyclePowerBaseMainDataPage& dataPage);
    bool handleProductInformation(BicyclePowerBaseMainDataPage& dataPage);
    bool handleStandardPowerOnly(BicyclePowerBaseMainDataPage& dataPage);
    bool handleStandardCrankTorque(BicyclePowerBaseMainDataPage& dataPage);
    bool handleCrankTorqueFrequency(BicyclePowerBaseMainDataPage& dataPage);
    bool handleStandardWheelTorque(BicyclePowerBaseMainDataPage& dataPage);
    bool handleTorqueEffectivenessAndPedalSmoothness(BicyclePowerBaseMainDataPage& dataPage);
    AntCallback<BatteryStatus&> _onBatteryStatus = { .func = NULL };
    AntCallback<ManufacturersInformation&> _onManufacturersInformation = { .func = NULL };
    AntCallback<ProductInformation&> _onProductInformation = { .func = NULL };
    AntCallback<BicyclePowerStandardPowerOnly&> _onBicyclePowerStandardPowerOnly = { .func = NULL };
    AntCallback<BicyclePowerStandardCrankTorque&> _onBicyclePowerStandardCrankTorque = { .func = NULL };
    AntCallback<BicyclePowerCrankTorqueFrequency&> _onBicyclePowerCrankTorqueFrequency = { .func = NULL };
    AntCallback<BicyclePowerStandardWheelTorque&> _onBicyclePowerStandardWheelTorque = { .func = NULL };
    AntCallback<BicyclePowerTorqueEffectivenessAndPedalSmoothness&> _onBicyclePowerTorqueEffectivenessAndPedalSmoothness = { .func = NULL };
};

#endif // ANTPLUS_PROFILEBICYCLEPOWERDISPLAY_h
