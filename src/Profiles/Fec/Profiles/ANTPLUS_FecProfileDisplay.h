#ifndef ANTPLUS_PROFILEFECDISPLAY_h
#define ANTPLUS_PROFILEFECDISPLAY_h

#include <BaseClasses/ANTPLUS_BaseSlaveProfile.h>
#include <Profiles/Fec/ANTPLUS_FecDataPages.h>
#include <CommonDataPages/ANTPLUS_CommonDataPages.h>

class ProfileFecDisplay : public BaseSlaveProfile {
public:
    ProfileFecDisplay(uint16_t deviceNumber = 0, uint8_t transmissionType = 0);
    void onFecTrainerData(void (*func)(FecSpecificTrainerData&, uintptr_t), uintptr_t data = 0) { _onFecSpecificTrainerData.set(func, data); }
    void onManufacturersInformation(void (*func)(ManufacturersInformation&, uintptr_t), uintptr_t data = 0) { _onManufacturersInformation.set(func, data); }
    void onProductInformation(void (*func)(ProductInformation&, uintptr_t), uintptr_t data = 0) { _onProductInformation.set(func, data); }
    void onFecGeneralFeData(void (*func)(FecGeneralFeData&, uintptr_t), uintptr_t data = 0) { _onFecGeneralFeData.set(func, data); }
    void onFecGeneralSettingsPage(void (*func)(FecGeneralSettingsPage&, uintptr_t), uintptr_t data = 0) { _onFecGeneralSettingsPage.set(func, data); }
    void onFecFeCapabilities(void (*func)(FecFeCapabilities&, uintptr_t), uintptr_t data = 0) { _onFecFeCapabilities.set(func, data); }

private:
    void setChannelConfig();
    void onBroadcastData(BroadcastData& msg) override;
    void onAcknowledgedData(AcknowledgedData& msg) override;

    bool handleDataPage(FecBaseMainDataPage& dp);
    bool handleManufacturerInformation(FecBaseMainDataPage& dataPage);
    bool handleProductInformation(FecBaseMainDataPage& dataPage);
    bool handleGeneralFeData(FecBaseMainDataPage& dataPage);
    bool handleGeneralSettingsPage(FecBaseMainDataPage& dataPage);
    bool handleTrainerData(FecBaseMainDataPage& dataPage);
    bool handleFeCapabilities(FecBaseMainDataPage& dataPage);

    AntCallback<FecSpecificTrainerData&> _onFecSpecificTrainerData = { .func = NULL };
    AntCallback<ManufacturersInformation&> _onManufacturersInformation = { .func = NULL };
    AntCallback<ProductInformation&> _onProductInformation = { .func = NULL };
    AntCallback<FecGeneralFeData&> _onFecGeneralFeData = { .func = NULL };
    AntCallback<FecGeneralSettingsPage&> _onFecGeneralSettingsPage = { .func = NULL };
    AntCallback<FecFeCapabilities&> _onFecFeCapabilities = { .func = NULL };
};

#endif // ANTPLUS_PROFILEFECDISPLAY_h
