#ifndef ANTPLUS_FECBASEMAINDATAPAGE_h
#define ANTPLUS_FECBASEMAINDATAPAGE_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>
#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>

template<class T>
class FecCoreMainDataPage : virtual public CoreDataPage<T> {
public:
    FecCoreMainDataPage();
    uint8_t getDataPageNumber() override;
    uint8_t getPageChangeToggle();
    uint16_t getHeartBeatEventTime();
    uint8_t getHeartBeatCount();
    uint8_t getComputedHeartRate();
};

class FecBaseMainDataPage : public BaseDataPage<BroadcastData>, public FecCoreMainDataPage<BroadcastData> {
public:
    explicit FecBaseMainDataPage(AntRxDataResponse& dp);
};

class FecBaseMainDataPageMsg : public BaseDataPageMsg<BroadcastDataMsg>, public FecCoreMainDataPage<BroadcastDataMsg> {
public:
    explicit FecBaseMainDataPageMsg(uint8_t dataPageNumber);
    void setPageChangeToggle(uint8_t toggle);
    void setHeartBeatEventTime(uint16_t time);
    void setHeartBeatCount(uint8_t count);
    void setComputedHeartRate(uint8_t heartRate);
protected:
    uint8_t _buffer[MESSAGE_SIZE] = {0};
};

#endif // ANTPLUS_FECBASEMAINDATAPAGE_h
