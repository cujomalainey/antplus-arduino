#ifndef ANTPLUS_HEARTRATEBASEMAINDATAPAGE_h
#define ANTPLUS_HEARTRATEBASEMAINDATAPAGE_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>
#include <BaseClasses/ANTPLUS_BaseDataPage.h>
#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>

#include "ANT.h"

template<class T>
class HeartRateCoreMainDataPage : virtual public CoreDataPage<T> {
public:
    HeartRateCoreMainDataPage();
    uint8_t getDataPageNumber() override;
    uint8_t getPageChangeToggle();
    uint16_t getHeartBeatEventTime();
    uint8_t getHeartBeatCount();
    uint8_t getComputedHeartRate();
};

class HeartRateBaseMainDataPage : public BaseDataPage<BroadcastData>, public HeartRateCoreMainDataPage<BroadcastData> {
public:
    explicit HeartRateBaseMainDataPage(AntRxDataResponse& dp);
};

class HeartRateBaseMainDataPageMsg : public BaseDataPageMsg<BroadcastDataMsg>, public HeartRateCoreMainDataPage<BroadcastDataMsg> {
public:
    explicit HeartRateBaseMainDataPageMsg(uint8_t dataPageNumber);
    void setPageChangeToggle(uint8_t toggle);
    void setHeartBeatEventTime(uint16_t time);
    void setHeartBeatCount(uint8_t count);
    void setComputedHeartRate(uint8_t heartRate);
protected:
    uint8_t _buffer[MESSAGE_SIZE];
};

#endif // ANTPLUS_HEARTRATEBASEMAINDATAPAGE_h
