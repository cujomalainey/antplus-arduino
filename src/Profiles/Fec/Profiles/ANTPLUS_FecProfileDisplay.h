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
    void onFecTargetPowerDataPage(void (*func)(FecTargetPowerDataPage&, uintptr_t), uintptr_t data = 0) { _onFecTargetPowerDataPage.set(func, data); }
    void onFecTrackResistanceDataPage(void (*func)(FecTrackResistanceDataPage&, uintptr_t), uintptr_t data = 0) { _onFecTrackResistanceDataPage.set(func, data); }
    void onFecFeCapabilities(void (*func)(FecFeCapabilities&, uintptr_t), uintptr_t data = 0) { _onFecFeCapabilities.set(func, data); }
    bool transmitFecTargetPowerMsg(uint16_t TargetPower);
    bool transmitFecTrackResistanceMsg(uint16_t TrackResistance);
    bool transmitFecBasicResistanceMsg(uint8_t total_resistance);
    bool transmitFecUserConfigurationMsg(uint16_t UserWeight, uint16_t BikeWeight);
    // TODO delete these
    // TODO also move data page numbers to public, otherwise requests don't work

private:
    void setChannelConfig();
    void onBroadcastData(BroadcastData& msg) override;
    void onAcknowledgedData(AcknowledgedData& msg) override;

    bool handleDataPage(BaseDataPage<BroadcastData>& dp);
    bool handleManufacturerInformation(BaseDataPage<BroadcastData>& dataPage);
    bool handleProductInformation(BaseDataPage<BroadcastData>& dataPage);
    bool handleGeneralFeData(BaseDataPage<BroadcastData>& dataPage);
    bool handleGeneralSettingsPage(BaseDataPage<BroadcastData>& dataPage);
    bool handleTrainerData(BaseDataPage<BroadcastData>& dataPage);
    bool handleTargetPowerDataPage(BaseDataPage<BroadcastData>& dataPage);
    bool handleTrackResistanceDataPage(BaseDataPage<BroadcastData>& dataPage);
    bool handleFeCapabilities(BaseDataPage<BroadcastData>& dataPage);
    // TODO update to base main dp

    AntCallback<FecSpecificTrainerData&> _onFecSpecificTrainerData = { .func = NULL };
    AntCallback<ManufacturersInformation&> _onManufacturersInformation = { .func = NULL };
    AntCallback<ProductInformation&> _onProductInformation = { .func = NULL };
    AntCallback<FecGeneralFeData&> _onFecGeneralFeData = { .func = NULL };
    AntCallback<FecGeneralSettingsPage&> _onFecGeneralSettingsPage = { .func = NULL };
    AntCallback<FecTargetPowerDataPage&> _onFecTargetPowerDataPage = { .func = NULL };
    AntCallback<FecTrackResistanceDataPage&> _onFecTrackResistanceDataPage = { .func = NULL };
    AntCallback<FecFeCapabilities&> _onFecFeCapabilities = { .func = NULL };
};

#endif // ANTPLUS_PROFILEFECDISPLAY_h
