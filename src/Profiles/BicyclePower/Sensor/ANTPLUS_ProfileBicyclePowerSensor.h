#ifndef ANTPLUS_PROFILEBICYCLEPOWERSENSOR_h
#define ANTPLUS_PROFILEBICYCLEPOWERSENSOR_h

#include <BaseClasses/ANTPLUS_BaseMasterProfile.h>
#include <Profiles/BicyclePower/DataPages/ANTPLUS_ProfileBicyclePowerDataPages.h>
#include <CommonDataPages/ANTPLUS_CommonDataPages.h>

class ProfileBicyclePowerSensor : public BaseMasterProfile {
public:
    ProfileBicyclePowerSensor(uint16_t deviceNumber, uint8_t transmissionType);
    ProfileBicyclePowerSensor(uint16_t deviceNumber, uint8_t transmissionType, uint32_t flags);
    /**
     * Register callback to populate default data messages (Datapage 0)
     */
    void createBicyclePowerStdPowerOnlyDataPageMsg(void (*func)(BicyclePowerStdPowerOnlyDataPageMsg&, uintptr_t), uintptr_t data = 0) { _createBicyclePowerStdPowerOnlyDataPageMsg.set(func, data); }

protected:
    void transmitNextDataPage();
    void onAcknowledgedData(AcknowledgedData& msg);
    void onBroadcastData(BroadcastData& msg);
    bool isDataPageValid(uint8_t dataPage);
private:
    void setChannelConfig();
    void transmitPrimaryDataPage();
    void transmitBackgroundDataPage();
    void transmitRequestedDataPage();
    void transmitBicyclePowerDefaultMsg();
    void transmitBicycleStdPowerOnlyMsg(BicyclePowerStdPowerOnlyDataPageMsg& msg);
    uint8_t getNextBackgroundPage(uint8_t currentPage);
    AntCallback<BicyclePowerStdPowerOnlyDataPageMsg&> _createBicyclePowerStdPowerOnlyDataPageMsg;
    uint8_t _nextBackgroundPage;
    uint8_t _patternStep = 0;
    uint32_t _flags = 0;
};

#endif // ANTPLUS_PROFILEBICYCLEPOWERSENSOR_h
