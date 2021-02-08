#ifndef ANTPLUS_PROFILEENVIRONMENTDISPLAY_h
#define ANTPLUS_PROFILEENVIRONMENTDISPLAY_h

#include <BaseClasses/ANTPLUS_BaseSlaveProfile.h>
#include <Profiles/Environment/ANTPLUS_EnvironmentDataPages.h>
#include <CommonDataPages/ANTPLUS_CommonDataPages.h>

class ProfileEnvironmentDisplay : public BaseSlaveProfile {
public:
    ProfileEnvironmentDisplay();
    explicit ProfileEnvironmentDisplay(uint16_t deviceNumber);
    explicit ProfileEnvironmentDisplay(uint16_t deviceNumber, uint8_t transmissionType);
    void onEnvironmentGeneralInformation(void (*func)(EnvironmentGeneralInformation&, uintptr_t), uintptr_t data = 0) { _onEnvironmentGeneralInformation.set(func, data); }
    void onEnvironmentTemperature(void (*func)(EnvironmentTemperature&, uintptr_t), uintptr_t data = 0) { _onEnvironmentTemperature.set(func, data); }
    void onManufacturersInformation(void (*func)(ManufacturersInformation&, uintptr_t), uintptr_t data = 0) { _onManufacturersInformation.set(func, data); }
    void onProductInformation(void (*func)(ProductInformation&, uintptr_t), uintptr_t data = 0) { _onProductInformation.set(func, data); }

private:
    void setChannelConfig();
    void onBroadcastData(BroadcastData& msg) override;
    void onAcknowledgedData(AcknowledgedData& msg) override;

    bool handleDataPage(EnvironmentBaseDataPage& dp);

    bool handleGeneralInformation(EnvironmentBaseDataPage& dataPage);
    bool handleTemperature(EnvironmentBaseDataPage& dataPage);
    bool handleManufacturersInformation(EnvironmentBaseDataPage& dataPage);
    bool handleProductInformation(EnvironmentBaseDataPage& dataPage);
    AntCallback<EnvironmentGeneralInformation&> _onEnvironmentGeneralInformation = { .func = NULL };
    AntCallback<EnvironmentTemperature&> _onEnvironmentTemperature = { .func = NULL };
    AntCallback<ManufacturersInformation&> _onManufacturersInformation = { .func = NULL };
    AntCallback<ProductInformation&> _onProductInformation = { .func = NULL };
};

#endif // ANTPLUS_PROFILEENVIRONMENTDISPLAY_h
