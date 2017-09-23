// TODO
/*
Code accidentally implemented in monitor, storing here for later

void onHeartRateCapabilities(void (*func)(HeartRateCapabilities&, uintptr_t), uintptr_t data = 0) { _onHeartRateCapabilities.set(func, data); }
void onRequestDataPage(void (*func)(RequestDataPage&, uintptr_t), uintptr_t data = 0) { _onRequestDataPage.set(func, data); }
bool handleCapabilities(HeartRateBaseMainDataPage& dataPage);
bool handleRequestDataPage(HeartRateBaseMainDataPage& dataPage);
Callback<HeartRateCapabilities&> _onHeartRateCapabilities;
Callback<RequestDataPage&> _onRequestDataPage;
*/