#ifndef ANTPLUS_PROFILEHEARTRATEMONITOR_h
#define ANTPLUS_PROFILEHEARTRATEMONITOR_h

#include <BaseClasses/ANTPLUS_BaseMasterProfile.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRateDataPages.h>
#include <CommonDataPages/ANTPLUS_CommonDataPages.h>
#include <CommonDataPages/ANTPLUS_CommonDataPageDefines.h>

class ProfileHeartRateMonitor : public BaseMasterProfile {
public:
    ProfileHeartRateMonitor(uint16_t deviceNumber, uint8_t transmissionType = 0, uint32_t flags = 0);
    /**
     * Register callback to populate default data messages (Datapage 0)
     */
    void createHeartRateDefaultMsg(void (*func)(HeartRateDefaultMsg&, uintptr_t), uintptr_t data = 0) { _createHeartRateDefaultMsg.set(func, data); }
    /**
     * Register callback to populate cumulative operating time data messages (Datapage 1)
     */
    void createHeartRateCumulativeOperatingTimeMsg(void (*func)(HeartRateCumulativeOperatingTimeMsg&, uintptr_t), uintptr_t data = 0) { _createHeartRateCumulativeOperatingTimeMsg.set(func, data); }
    /**
     * Register callback to populate manufacturer information data messages (Datapage 2)
     */
    void createHeartRateManufacturerInformationMsg(void (*func)(HeartRateManufacturerInformationMsg&, uintptr_t), uintptr_t data = 0) { _createHeartRateManufacturerInformationMsg.set(func, data); }
    /**
     * Register callback to populate product information data messages (Datapage 3)
     */
    void createHeartRateProductInformationMsg(void (*func)(HeartRateProductInformationMsg&, uintptr_t), uintptr_t data = 0) { _createHeartRateProductInformationMsg.set(func, data); }
    /**
     * Register callback to populate previous heart beat data messages (Datapage 4)
     */
    void createHeartRatePreviousHeartBeatMsg(void (*func)(HeartRatePreviousHeartBeatMsg&, uintptr_t), uintptr_t data = 0) { _createHeartRatePreviousHeartBeatMsg.set(func, data); }
    /**
     * Register callback to populate swim interval summary data messages (Datapage 5)
     * This must be registered for swim mode
     */
    void createHeartRateSwimIntervalSummaryMsg(void (*func)(HeartRateSwimIntervalSummaryMsg&, uintptr_t), uintptr_t data = 0) { _createHeartRateSwimIntervalSummaryMsg.set(func, data); }
    /**
     * Register callback to populate capabilities data messages (Datapage 6)
     */
    void createHeartRateCapabilitiesMsg(void (*func)(HeartRateCapabilitiesMsg&, uintptr_t), uintptr_t data = 0) { _createHeartRateCapabilitiesMsg.set(func, data); }
    /**
     * Register callback to populate battery status data messages (Datapage 7)
     */
    void createHeartRateBatteryStatusMsg(void (*func)(HeartRateBatteryStatusMsg&, uintptr_t), uintptr_t data = 0) { _createHeartRateBatteryStatusMsg.set(func, data); }
    /**
     * Register callback to handle incoming request dataPage. The profile will automatically
     * adjust the broadcast pattern, there is no need for you to do anything with this message.
     */
    void onRequestDataPage(void (*func)(RequestDataPage&, uintptr_t), uintptr_t data = 0) { _onRequestDataPage.set(func, data); }
    /**
     * Register callback that handles modes settings message that is incoming,
     * no need to update the sports mode as the system will handle that based on the flags
     */
    void onModeSettings(void (*func)(ModeSettings&, uintptr_t), uintptr_t data = 0) { _onModeSettings.set(func, data); }
    /**
     * Force a sports mode change, this is designed for external interfaces
     * (such as a switch) to force a mode change
     */
    void setSportsMode(uint8_t mode) { _sportsMode = mode; }
protected:
    void transmitNextDataPage() override;
    void onAcknowledgedData(AcknowledgedData& msg) override;
    void onBroadcastData(BroadcastData& msg) override;
    bool isDataPageValid(uint8_t dataPage) override;
private:
    void setChannelConfig();
    void transmitPrimaryDataPage();
    void transmitBackgroundDataPage();
    void transmitRequestedDataPage();
    void transmitHeartRateDefaultMsg();
    void transmitHeartRateCumulativeOperatingTimeMsg();
    void transmitHeartRateManufacturerInformationMsg();
    void transmitHeartRateProductInformationMsg();
    void transmitHeartRatePreviousHeartBeatMsg();
    void transmitHeartRateSwimIntervalSummaryMsg();
    void transmitHeartRateCapabilitiesMsg();
    void transmitHeartRateBatteryStatusMsg();
    void transmitHeartRateMsg(HeartRateBaseMainDataPageMsg& msg);
    bool handleModeSettings(HeartRateBaseMainDataPage& dataPage);
    bool handleRequestDataPage(HeartRateBaseMainDataPage& dataPage);
    uint8_t getNextBackgroundPage(uint8_t currentPage);
    AntCallback<RequestDataPage&> _onRequestDataPage = { .func = NULL };
    AntCallback<ModeSettings&> _onModeSettings = { .func = NULL };
    AntCallback<HeartRateDefaultMsg&> _createHeartRateDefaultMsg = { .func = NULL };
    AntCallback<HeartRateCumulativeOperatingTimeMsg&> _createHeartRateCumulativeOperatingTimeMsg = { .func = NULL };
    AntCallback<HeartRateManufacturerInformationMsg&> _createHeartRateManufacturerInformationMsg = { .func = NULL };
    AntCallback<HeartRateProductInformationMsg&> _createHeartRateProductInformationMsg = { .func = NULL };
    AntCallback<HeartRatePreviousHeartBeatMsg&> _createHeartRatePreviousHeartBeatMsg = { .func = NULL };
    AntCallback<HeartRateSwimIntervalSummaryMsg&> _createHeartRateSwimIntervalSummaryMsg = { .func = NULL };
    AntCallback<HeartRateCapabilitiesMsg&> _createHeartRateCapabilitiesMsg = { .func = NULL };
    AntCallback<HeartRateBatteryStatusMsg&> _createHeartRateBatteryStatusMsg = { .func = NULL };
    uint8_t _nextBackgroundPage;
    uint8_t _sportsMode = ANTPLUS_COMMON_DATAPAGE_MODESETTINGS_SPORTSMODE_RUNNING;
    uint32_t _flags = 0;
    uint8_t _toggleStep = 0;
    uint8_t _patternStep = 0;
};

#endif // ANTPLUS_PROFILEHEARTRATEMONITOR_h
