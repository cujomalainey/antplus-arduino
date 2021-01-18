#ifndef ANTPLUS_BICYCLESPEEDBASEMAINDATAPAGE_h
#define ANTPLUS_BICYCLESPEEDBASEMAINDATAPAGE_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>
#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>

template<class T>
class BicycleSpeedCoreMainDataPage : virtual public CoreDataPage<T> {
public:
    BicycleSpeedCoreMainDataPage();
    uint8_t getDataPageNumber() override;
    uint8_t getPageChangeToggle();
    uint16_t getBikeSpeedEventTime();
    uint16_t getCumulativeSpeedRevolutionCount();
};

class BicycleSpeedBaseMainDataPage : public BaseDataPage<BroadcastData>, public BicycleSpeedCoreMainDataPage<BroadcastData> {
public:
    explicit BicycleSpeedBaseMainDataPage(AntRxDataResponse& dp);
};

class BicycleSpeedBaseMainDataPageMsg : public BaseDataPageMsg<BroadcastDataMsg>, public BicycleSpeedCoreMainDataPage<BroadcastDataMsg> {
public:
    explicit BicycleSpeedBaseMainDataPageMsg(uint8_t dataPageNumber);
    void setPageChangeToggle(uint8_t toggle);
    void setBikeSpeedEventTime(uint16_t time);
    void setCumulativeSpeedRevolutionCount(uint16_t count);
protected:
    uint8_t _buffer[MESSAGE_SIZE];
};

#endif // ANTPLUS_BICYCLESPEEDBASEMAINDATAPAGE_h
