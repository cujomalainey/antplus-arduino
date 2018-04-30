#ifndef ANTPLUS_PROFILEHEARTRATESENSOR_h
#define ANTPLUS_PROFILEHEARTRATESENSOR_h

#include <BaseClasses/ANTPLUS_BaseMasterProfile.h>
#include <Profiles/HeartRate/DataPages/ANTPLUS_ProfileHeartRateDataPages.h>
#include <CommonDataPages/ANTPLUS_CommonDataPages.h>

class ProfileHeartRateMonitor : BaseMasterProfile {
public:
    void createHeartRateDefault(void (*func)(HeartRateDefault&, uintptr_t), uintptr_t data = 0) { _createHeartRateDefault.set(func, data); }
    void createHeartRateCapabilities(void (*func)(HeartRateCapabilities&, uintptr_t), uintptr_t data = 0) { _createHeartRateCapabilities.set(func, data); }
    void createHeartRateBatteryStatus(void (*func)(HeartRateBatteryStatus&, uintptr_t), uintptr_t data = 0) { _createHeartRateBatteryStatus.set(func, data); }
    void onRequestDataPage(void (*func)(RequestDataPage&, uintptr_t), uintptr_t data = 0) { _onRequestDataPage.set(func, data); }
    void onModeSettings(void (*func)(ModeSettings&, uintptr_t), uintptr_t data = 0) { _onModeSettings.set(func, data); }
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
    bool handleModeSettings(HeartRateBaseMainDataPage& dataPage);
    bool handleRequestDataPage(HeartRateBaseMainDataPage& dataPage);
    Callback<RequestDataPage&> _onRequestDataPage;
    Callback<ModeSettings&> _onModeSettings;
    Callback<HeartRateDefault&> _createHeartRateDefault;
    Callback<HeartRateCapabilities&> _createHeartRateCapabilities;
    Callback<HeartRateBatteryStatus&> _createHeartRateBatteryStatus;
    uint8_t _requestedCount = 0;
};

#endif // ANTPLUS_PROFILEHEARTRATESENSOR_h
