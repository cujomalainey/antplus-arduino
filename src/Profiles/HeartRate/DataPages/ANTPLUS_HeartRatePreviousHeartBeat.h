#ifndef ANTPLUS_HEARTRATEPREVIOUSHEARTBEAT_h
#define ANTPLUS_HEARTRATEPREVIOUSHEARTBEAT_h

#include <Profiles/HeartRate/DataPages/ANTPLUS_HeartRateBaseMainDataPage.h>

template<class T>
class HeartRateBasePreviousHeartBeat : virtual public CoreDataPage<T> {
public:
    HeartRateBasePreviousHeartBeat();
    uint8_t getManufacturerSpecific();
    uint16_t getPreviousHeartBeatEventTime();
};

class HeartRatePreviousHeartBeat : public HeartRateBaseMainDataPage, public HeartRateBasePreviousHeartBeat<BroadcastData> {
public:
    explicit HeartRatePreviousHeartBeat(AntRxDataResponse& dp);
};

class HeartRatePreviousHeartBeatMsg : public HeartRateBaseMainDataPageMsg, public HeartRateBasePreviousHeartBeat<BroadcastDataMsg> {
public:
    HeartRatePreviousHeartBeatMsg();
    void setManufacturerSpecific(uint8_t specificByte);
    void setPreviousHeartBeatEventTime(uint16_t eventTime);
};

#endif // ANTPLUS_HEARTRATEPREVIOUSHEARTBEAT_h
