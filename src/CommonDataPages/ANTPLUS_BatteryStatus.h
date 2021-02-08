#ifndef ANTPLUS_BATTERYSTATUS_h
#define ANTPLUS_BATTERYSTATUS_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>
#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>

// Common page 82

template<class T>
class BaseBatteryStatus : virtual public CoreDataPage<T> {
public:
    BaseBatteryStatus();
    uint8_t getNumberOfBatteries();
    uint8_t getBatteryIdentifier();
    uint32_t getCumulativeOperatingTime();
    uint8_t getFractionalBatteryVoltage();
    uint8_t getCoarseBatteryVoltage();
    uint8_t getBatteryStatus();
    uint8_t getCumulativeOperatingTimeResolution();
};

class BatteryStatus : public BaseDataPage<BroadcastData>, public BaseBatteryStatus<BroadcastData> {
public:
    explicit BatteryStatus(AntRxDataResponse& dp);
};

class BatteryStatusMsg : public BaseDataPageMsg<BroadcastDataMsg>, public BaseBatteryStatus<BroadcastDataMsg> {
public:
    BatteryStatusMsg();
    void setNumberOfBatteries(uint8_t num);
    void setBatteryIdentifier(uint8_t id);
    void setCumulativeOperatingTime(uint32_t time);
    void setFractionalBatteryVoltage(uint8_t voltage);
    void setCoarseBatteryVoltage(uint8_t voltage);
    void setBatteryStatus(uint8_t status);
    void setCumulativeOperatingTimeResolution(uint8_t resolution);
private:
    uint8_t _buffer[MESSAGE_SIZE];
};

#endif // ANTPLUS_BATTERYSTATUS_h
