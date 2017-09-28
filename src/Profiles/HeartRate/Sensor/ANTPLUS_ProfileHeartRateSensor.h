#ifndef ANTPLUS_PROFILEHEARTRATESENSOR_h
#define ANTPLUS_PROFILEHEARTRATESENSOR_h

#include <BaseClasses/ANTPLUS_BaseMasterProfile.h>
#include <Profiles/HeartRate/DataPages/ANTPLUS_ProfileHeartRateDataPages.h>
#include <CommonDataPages/ANTPLUS_CommonDataPages.h>

class ProfileHeartRateSensor : BaseMasterProfile {
public:
    void onHeartRateCapabilities(void (*func)(HeartRateCapabilities&, uintptr_t), uintptr_t data = 0) { _onHeartRateCapabilities.set(func, data); }
    void onRequestDataPage(void (*func)(RequestDataPage&, uintptr_t), uintptr_t data = 0) { _onRequestDataPage.set(func, data); }
    void begin();
    void stop();
    /******************************************
     *LIBRARY INTERNAL ONLY FUNCTIONS BELOW
     ******************************************/
    void onAcknowledgedData(AcknowledgedData& msg);
    void onBroadcastData(BroadcastData& msg);
protected:
    void transmitNextDataPage();
private:
    bool handleCapabilities(HeartRateBaseMainDataPage& dataPage);
    bool handleRequestDataPage(HeartRateBaseMainDataPage& dataPage);
    Callback<HeartRateCapabilities&> _onHeartRateCapabilities;
    Callback<RequestDataPage&> _onRequestDataPage;
};

#endif // ANTPLUS_PROFILEHEARTRATESENSOR_h