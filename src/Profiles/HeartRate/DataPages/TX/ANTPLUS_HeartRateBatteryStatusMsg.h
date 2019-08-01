#ifndef ANTPLUS_HEARTRATEBATTERYSTATUSMSG_h
#define ANTPLUS_HEARTRATEBATTERYSTATUSMSG_h

#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseMainDataPageMsg.h>
#include <Profiles/HeartRate/DataPages/Base/ANTPLUS_HeartRateBaseBatteryStatus.h>

class HeartRateBatteryStatusMsg : public HeartRateBaseMainDataPageMsg, public HeartRateBaseBatteryStatus<BroadcastDataMsg> {
public:
    HeartRateBatteryStatusMsg();
    void setBatteryLevel(uint8_t level);
    void setFractionalBatteryVoltage(uint8_t voltage);
    void setCoarseBatteryVolage(uint8_t voltage);
    void setBatteryStatus(uint8_t status);
};

#endif // ANTPLUS_HEARTRATEBATTERYSTATUSMSG_h
