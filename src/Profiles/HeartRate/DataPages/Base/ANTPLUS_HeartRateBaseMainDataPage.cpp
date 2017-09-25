#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPage.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

HeartRateBaseMainDataPage::HeartRateBaseMainDataPage(BroadcastData& dp) : BaseDataPage<BroadcastData>(dp) {

}

uint8_t HeartRateBaseMainDataPage::getDataPageNumber() {
    return getData(ANTPLUS_HEARTRATE_DATAPAGEBASE_DATAPAGE_BYTE) & ANTPLUS_HEARTRATE_DATAPAGEBASE_DATAPAGE_MASK;
}

uint8_t HeartRateBaseMainDataPage::getPageChangeToggle() {
    return (getData(ANTPLUS_HEARTRATE_DATAPAGEBASE_TOGGLE_BYTE) & ANTPLUS_HEARTRATE_DATAPAGEBASE_TOGGLE_MASK) >> ANTPLUS_HEARTRATE_DATAPAGEBASE_TOGGLE_SHIFT;
}

uint16_t HeartRateBaseMainDataPage::getHeartBeatEventTime() {
    return (getData(ANTPLUS_HEARTRATE_DATAPAGEBASE_HEARTBEATEVENTTIMEMSB_BYTE) << ANTPLUS_HEARTRATE_DATAPAGEBASE_HEARTBEATEVENTTIMEMSB_SHIFT) | getData(ANTPLUS_HEARTRATE_DATAPAGEBASE_HEARTBEATEVENTTIMELSB_BYTE);
}

uint8_t HeartRateBaseMainDataPage::getHeartBeatCount() {
    return getData(ANTPLUS_HEARTRATE_DATAPAGEBASE_HEARTBEATCOUNT_BYTE);
}

uint8_t HeartRateBaseMainDataPage::getComputedHeartRate() {
    return getData(ANTPLUS_HEARTRATE_DATAPAGEBASE_COMPUTEDHEARTRATE_BYTE);
}
