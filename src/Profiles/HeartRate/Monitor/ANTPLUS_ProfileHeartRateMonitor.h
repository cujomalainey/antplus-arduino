#ifndef ANTPLUS_PROFILEHEARTRATESENSOR_h
#define ANTPLUS_PROFILEHEARTRATESENSOR_h

#include <BaseClasses/ANTPLUS_BaseMasterProfile.h>
#include <Profiles/HeartRate/DataPages/ANTPLUS_ProfileHeartRateDataPages.h>
#include <CommonDataPages/ANTPLUS_CommonDataPages.h>
#include <CommonDataPages/ANTPLUS_CommonDataPageDefines.h>

class ProfileHeartRateMonitor : BaseMasterProfile {
public:
    ProfileHeartRateMonitor(uint16_t deviceNumber, uint8_t transmissionType);
    ProfileHeartRateMonitor(uint16_t deviceNumber, uint8_t transmissionType, uint32_t flags);
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
     *
     */
    void setSportsMode(uint8_t mode) { _sportsMode = mode; }
    /**
     * Sets up the profile and begins broadcast pattern
     */
    void begin();
    /**
     * Closes channel and stops transmissions
     */
    void stop();
protected:
    void transmitNextDataPage();
    void onAcknowledgedData(AcknowledgedData& msg);
    void onBroadcastData(BroadcastData& msg);
private:
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
    Callback<RequestDataPage&> _onRequestDataPage;
    Callback<ModeSettings&> _onModeSettings;
    Callback<HeartRateDefaultMsg&> _createHeartRateDefaultMsg;
    Callback<HeartRateCumulativeOperatingTimeMsg&> _createHeartRateCumulativeOperatingTimeMsg;
    Callback<HeartRateManufacturerInformationMsg&> _createHeartRateManufacturerInformationMsg;
    Callback<HeartRateProductInformationMsg&> _createHeartRateProductInformationMsg;
    Callback<HeartRatePreviousHeartBeatMsg&> _createHeartRatePreviousHeartBeatMsg;
    Callback<HeartRateSwimIntervalSummaryMsg&> _createHeartRateSwimIntervalSummaryMsg;
    Callback<HeartRateCapabilitiesMsg&> _createHeartRateCapabilitiesMsg;
    Callback<HeartRateBatteryStatusMsg&> _createHeartRateBatteryStatusMsg;
    uint8_t _requestedCount = 0;
    uint8_t _requestedPage;
    uint8_t _nextBackgroundPage;
    uint8_t _sportsMode = ANTPLUS_COMMON_DATAPAGE_MODESETTINGS_SPORTSMODE_RUNNING;
    uint32_t flags = 0;
    bool _useDefaultDataPage = false;
    bool _useCumulativeOperatingTime = false;
};

#endif // ANTPLUS_PROFILEHEARTRATESENSOR_h
