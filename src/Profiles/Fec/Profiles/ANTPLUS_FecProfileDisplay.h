#ifndef ANTPLUS_PROFILEFECDISPLAY_h
#define ANTPLUS_PROFILEFECDISPLAY_h

#include <BaseClasses/ANTPLUS_BaseSlaveProfile.h>
#include <Profiles/Fec/ANTPLUS_FecDataPages.h>
#include <CommonDataPages/ANTPLUS_CommonDataPages.h>

class ProfileFecDisplay : public BaseSlaveProfile {
public:
    ProfileFecDisplay(uint16_t deviceNumber = 0, uint8_t transmissionType = 0);
    void onFecTrainerData(void (*func)(FecSpecificTrainerData&, uintptr_t), uintptr_t data = 0) { _onFecSpecificTrainerData.set(func, data); }
    void onFecManufacturerInformation(void (*func)(FecManufacturerInformation&, uintptr_t), uintptr_t data = 0) { _onFecManufacturerInformation.set(func, data); }
    void onFecProductInformation(void (*func)(FecProductInformation&, uintptr_t), uintptr_t data = 0) { _onFecProductInformation.set(func, data); }
    void onFecGeneralDataPage(void (*func)(FecGeneralMainDataPage&, uintptr_t), uintptr_t data = 0) { _onFecGeneralDataPage.set(func, data); }
    void onFecGeneralSettingsDataPage(void (*func)(FecGeneralSettingsDataPage&, uintptr_t), uintptr_t data = 0) { _onFecGeneralSettingsDataPage.set(func, data); }
    void onFecTargetPowerDataPage(void (*func)(FecTargetPowerDataPage&, uintptr_t), uintptr_t data = 0) { _onFecTargetPowerDataPage.set(func, data); }
    void onFecTrackResistanceDataPage(void (*func)(FecTrackResistanceDataPage&, uintptr_t), uintptr_t data = 0) { _onFecTrackResistanceDataPage.set(func, data); }
    void onFecBasicResistanceDataPage(void (*func)(FecBasicResistanceDataPage&, uintptr_t), uintptr_t data = 0) { _onFecBasicResistanceDataPage.set(func, data); }
    void onFecUserInformationDataPage(void (*func)(FecUserInformationDatapage&, uintptr_t), uintptr_t data = 0) { _onFecUserInformationDataPage.set(func, data); }
    void onFecCapabilitiesInformationDataPage(void (*func)(FecCapabilitiesInformationDatapage&, uintptr_t), uintptr_t data = 0) { _onFecCapabilitiesInformationDataPage.set(func, data); }
    bool transmitFecTargetPowerMsg(uint16_t TargetPower);
    bool transmitFecTrackResistanceMsg(uint16_t TrackResistance);
    bool transmitFecBasicResistanceMsg(uint8_t Power);
    bool transmitFecUserInformationMsg(uint16_t UserWeight, uint16_t BikeWeight);
    bool transmitFecCapabitiliesRequestMsg();

private:
    void setChannelConfig();
    void onBroadcastData(BroadcastData& msg) override;
    void onAcknowledgedData(AcknowledgedData& msg) override;

    bool handleDataPage(BaseDataPage<BroadcastData>& dp);
    bool handleManufacturerInformation(BaseDataPage<BroadcastData>& dataPage);
    bool handleProductInformation(BaseDataPage<BroadcastData>& dataPage);
    bool handleGeneralDataPage(BaseDataPage<BroadcastData>& dataPage);
    bool handleGeneralSettingsDataPage(BaseDataPage<BroadcastData>& dataPage);
    bool handleTrainerData(BaseDataPage<BroadcastData>& dataPage);
    bool handleTargetPowerDataPage(BaseDataPage<BroadcastData>& dataPage);
    bool handleTrackResistanceDataPage(BaseDataPage<BroadcastData>& dataPage);
    bool handleBasicResistanceDataPage(BaseDataPage<BroadcastData>& dataPage);
    bool handleUserInformationDataPage(BaseDataPage<BroadcastData>& dataPage);
    bool handleCapabilitiesInformationDataPage(BaseDataPage<BroadcastData>& dataPage);

    AntCallback<FecSpecificTrainerData&> _onFecSpecificTrainerData = { .func = NULL };
    AntCallback<FecManufacturerInformation&> _onFecManufacturerInformation = { .func = NULL };
    AntCallback<FecProductInformation&> _onFecProductInformation = { .func = NULL };
    AntCallback<FecGeneralMainDataPage&> _onFecGeneralDataPage = { .func = NULL };
    AntCallback<FecGeneralSettingsDataPage&> _onFecGeneralSettingsDataPage = { .func = NULL };
    AntCallback<FecTargetPowerDataPage&> _onFecTargetPowerDataPage = { .func = NULL };
    AntCallback<FecTrackResistanceDataPage&> _onFecTrackResistanceDataPage = { .func = NULL };
    AntCallback<FecBasicResistanceDataPage&> _onFecBasicResistanceDataPage = { .func = NULL };
    AntCallback<FecUserInformationDatapage&> _onFecUserInformationDataPage = { .func = NULL };
    AntCallback<FecCapabilitiesInformationDatapage&> _onFecCapabilitiesInformationDataPage = { .func = NULL };
};

#endif // ANTPLUS_PROFILEFECDISPLAY_h
