#ifndef ANTPLUS_PROFILEHEARTRATESENSOR_h
#define ANTPLUS_PROFILEHEARTRATESENSOR_h

#include <BaseClasses/ANTPLUS_BaseMasterProfile.h>
#include <Profiles/HeartRate/DataPages/ANTPLUS_ProfileHeartRateDataPages.h>
#include <CommonDataPages/ANTPLUS_CommonDataPages.h>
#include <CommonDataPages/ANTPLUS_CommonDataPageDefines.h>

class ProfileHeartRateMonitor : BaseMasterProfile {
public:
    ProfileHeartRateMonitor(uint16_t deviceNumber, uint8_t transmissionType);
    void createHeartRateDefaultMsg(void (*func)(HeartRateDefaultMsg&, uintptr_t), uintptr_t data = 0) { _createHeartRateDefaultMsg.set(func, data); }
    void createHeartRateCumulativeOperatingTimeMsg(void (*func)(HeartRateCumulativeOperatingTimeMsg&, uintptr_t), uintptr_t data = 0) { _createHeartRateCumulativeOperatingTimeMsg.set(func, data); }
    void createHeartRateManufacturerInformationMsg(void (*func)(HeartRateManufacturerInformationMsg&, uintptr_t), uintptr_t data = 0) { _createHeartRateManufacturerInformationMsg.set(func, data); }
    void createHeartRateProductInformationMsg(void (*func)(HeartRateProductInformationMsg&, uintptr_t), uintptr_t data = 0) { _createHeartRateProductInformationMsg.set(func, data); }
    void createHeartRatePreviousHeartBeatMsg(void (*func)(HeartRatePreviousHeartBeatMsg&, uintptr_t), uintptr_t data = 0) { _createHeartRatePreviousHeartBeatMsg.set(func, data); }
    void createHeartRateSwimIntervalSummaryMsg(void (*func)(HeartRateSwimIntervalSummaryMsg&, uintptr_t), uintptr_t data = 0) { _createHeartRateSwimIntervalSummaryMsg.set(func, data); }
    void createHeartRateCapabilitiesMsg(void (*func)(HeartRateCapabilitiesMsg&, uintptr_t), uintptr_t data = 0) { _createHeartRateCapabilitiesMsg.set(func, data); }
    void createHeartRateBatteryStatusMsg(void (*func)(HeartRateBatteryStatusMsg&, uintptr_t), uintptr_t data = 0) { _createHeartRateBatteryStatusMsg.set(func, data); }
    void onRequestDataPage(void (*func)(RequestDataPage&, uintptr_t), uintptr_t data = 0) { _onRequestDataPage.set(func, data); }
    void onModeSettings(void (*func)(ModeSettings&, uintptr_t), uintptr_t data = 0) { _onModeSettings.set(func, data); }
    void setSportsMode(uint8_t mode) { _sportsMode = mode; }
    void useDefaultDatapage(bool useDefault) { _useDefaultDataPage = useDefault; }
    void useCumulativeOperatingTime(bool useCumulativeOperatingTime) { _useCumulativeOperatingTime = useCumulativeOperatingTime; }
    void begin();
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
    bool _useDefaultDataPage = false;
    bool _useCumulativeOperatingTime = false;
};

#endif // ANTPLUS_PROFILEHEARTRATESENSOR_h
