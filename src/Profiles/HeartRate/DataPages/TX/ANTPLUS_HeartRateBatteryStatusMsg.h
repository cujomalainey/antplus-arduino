#ifndef ANTPLUS_HEARTRATEBATTERYSTATUSMSG_h
#define ANTPLUS_HEARTRATEBATTERYSTATUSMSG_h

#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPageMsg.h>

class HeartRateBatteryStatusMsg : public HeartRateBaseMainDataPageMsg {
public:
    HeartRateBatteryStatusMsg();
    uint8_t getBatteryLevel();
    uint8_t getFractionalBatteryVoltage();
    uint8_t getCoarseBatteryVolage();
    uint8_t getBatteryStatus();
    void setBatteryLevel(uint8_t level);
    void setFractionalBatteryVoltage(uint8_t voltage);
    void setCoarseBatteryVolage(uint8_t voltage);
    void setBatteryStatus(uint8_t status);
};

#endif // ANTPLUS_HEARTRATEBATTERYSTATUSMSG_h