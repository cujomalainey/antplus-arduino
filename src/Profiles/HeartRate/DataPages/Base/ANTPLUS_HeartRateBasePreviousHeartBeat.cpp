#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBasePreviousHeartBeat.h>
#include <Profiles/HeartRate/ANTPLUS_HeartRatePrivateDefines.h>

template<class T>
HeartRateBasePreviousHeartBeat<T>::HeartRateBasePreviousHeartBeat() : CoreDataPage<T>() {
}

template<class T>
uint8_t HeartRateBasePreviousHeartBeat<T>::getManufacturerSpecific() {
    return this->get8BitValue(
            ANTPLUS_HEARTRATE_DATAPAGE_PREVIOUSHEARTBEAT_MANUFACTURERSPECIFIC_BYTE);
}

template<class T>
uint16_t HeartRateBasePreviousHeartBeat<T>::getPreviousHeartBeatEventTime() {
    return this->get16BitValue(
            ANTPLUS_HEARTRATE_DATAPAGE_PREVIOUSHEARTBEAT_PREVIOUSHEARTBEATEVENTTIMELSB_BYTE,
            ANTPLUS_HEARTRATE_DATAPAGE_PREVIOUSHEARTBEAT_PREVIOUSHEARTBEATEVENTTIMEMSB_BYTE);
}

template class HeartRateBasePreviousHeartBeat<BroadcastData>;
template class HeartRateBasePreviousHeartBeat<BroadcastDataMsg>;
