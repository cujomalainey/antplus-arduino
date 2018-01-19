#ifndef ANTPLUS_PROFILEENVIRONMENTDISPLAY_h
#define ANTPLUS_PROFILEENVIRONMENTDISPLAY_h

#include <BaseClasses/ANTPLUS_BaseSlaveProfile.h>
#include <Profiles/Environment/DataPages/ANTPLUS_ProfileEnvironmentDataPages.h>
#include <CommonDataPages/ANTPLUS_CommonDataPages.h>

#include "ANT.h"

class ProfileEnvironmentDisplay : public BaseSlaveProfile {
public:
    ProfileEnvironmentDisplay();
    ProfileEnvironmentDisplay(uint16_t deviceNumber);
    ProfileEnvironmentDisplay(uint16_t deviceNumber, uint8_t transmissionType);
    void onEnvironmentGeneralInformation(void (*func)(EnvironmentGeneralInformation&, uintptr_t), uintptr_t data = 0) { _onEnvironmentGeneralInformation.set(func, data); }
    void onEnvironmentTemperature(void (*func)(EnvironmentTemperature&, uintptr_t), uintptr_t data = 0) { _onEnvironmentTemperature.set(func, data); }
    void onManufacturersInformation(void (*func)(ManufacturersInformation&, uintptr_t), uintptr_t data = 0) { _onManufacturersInformation.set(func, data); }
    void onProductInformation(void (*func)(ProductInformation&, uintptr_t), uintptr_t data = 0) { _onProductInformation.set(func, data); }

private:
    void setChannelConfig();
    void onBroadcastData(BroadcastData& msg);
    void onAcknowledgedData(AcknowledgedData& msg);

    bool handleDataPage(EnvironmentBaseDataPage& dp);

    bool handleGeneralInformation(EnvironmentBaseDataPage& dataPage);
    bool handleTemperature(EnvironmentBaseDataPage& dataPage);
    bool handleManufacturersInformation(EnvironmentBaseDataPage& dataPage);
    bool handleProductInformation(EnvironmentBaseDataPage& dataPage);
    Callback<EnvironmentGeneralInformation&> _onEnvironmentGeneralInformation;
    Callback<EnvironmentTemperature&> _onEnvironmentTemperature;
    Callback<ManufacturersInformation&> _onManufacturersInformation;
    Callback<ProductInformation&> _onProductInformation;
};

#endif // ANTPLUS_PROFILEENVIRONMENTDISPLAY_h
