#ifndef ANTPLUS_BATTERYSTATUSMSG_h
#define ANTPLUS_BATTERYSTATUSMSG_h

#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>
#include <CommonDataPages/Base/ANTPLUS_BaseBatteryStatus.h>

#include "ANT.h"

// Common page 82

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
};

#endif // ANTPLUS_BATTERYSTATUSMSG_h
