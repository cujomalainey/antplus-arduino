#ifndef ANTPLUS_PROFILEBICYCLEPOWERSENSOR_h
#define ANTPLUS_PROFILEBICYCLEPOWERSENSOR_h

#include <BaseClasses/ANTPLUS_BaseMasterProfile.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerDataPages.h>
#include <CommonDataPages/ANTPLUS_CommonDataPages.h>

class ProfileBicyclePowerSensor : public BaseMasterProfile {
public:
    ProfileBicyclePowerSensor(uint16_t deviceNumber, uint8_t transmissionType = 0, uint32_t flags = 0);
    /**
     * Register callback to populate default data messages (Datapage 0)
     */
    void createBicyclePowerStandardPowerOnlyMsg(void (*func)(BicyclePowerStandardPowerOnlyMsg&, uintptr_t), uintptr_t data = 0) { _createBicyclePowerStandardPowerOnlyMsg.set(func, data); }
    void createBicyclePowerStandardWheelTorqueMsg(void (*func)(BicyclePowerStandardWheelTorqueMsg&, uintptr_t), uintptr_t data = 0) { _createBicyclePowerStandardWheelTorqueMsg.set(func, data); }
    void createBicyclePowerStandardCrankTorqueMsg(void (*func)(BicyclePowerStandardCrankTorqueMsg&, uintptr_t), uintptr_t data = 0) { _createBicyclePowerStandardCrankTorqueMsg.set(func, data); }
    void createBicyclePowerCrankTorqueFrequencyMsg(void (*func)(BicyclePowerCrankTorqueFrequencyMsg&, uintptr_t), uintptr_t data = 0) { _createBicyclePowerCrankTorqueFrequencyMsg.set(func, data); }
    void createBicyclePowerTorqueEffectivenessAndPedalSmoothnessMsg(void (*func)(BicyclePowerTorqueEffectivenessAndPedalSmoothnessMsg&, uintptr_t), uintptr_t data = 0) { _createBicyclePowerTorqueEffectivenessAndPedalSmoothnessMsg.set(func, data); }

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
    void transmitBicycleStandardPowerOnlyMsg(BicyclePowerStandardPowerOnlyMsg& msg);
    void transmitBicyclePowerStandardPowerOnlyMsg();
    void transmitBicyclePowerStandardWheelTorqueMsg();
    void transmitBicyclePowerStandardCrankTorqueMsg();
    void transmitBicyclePowerTorqueEffectivenessAndPedalSmoothnessMsg();
    void transmitBicyclePowerCrankTorqueFrequencyMsg();
    void transmistBicyclePowerGeneralCalibrationResponse();
    bool handleRequestDataPage(BicyclePowerStandardPowerOnly& dataPage);
    bool handleGeneralCalibration(BicyclePowerStandardPowerOnly& dataPage);
    uint8_t getNextBackgroundPage(uint8_t currentPage);
    AntCallback<RequestDataPage&> _onRequestDataPage = { .func = NULL };
    AntCallback<BicyclePowerStandardPowerOnlyMsg&> _createBicyclePowerStandardPowerOnlyMsg = { .func = NULL };
    AntCallback<BicyclePowerStandardWheelTorqueMsg&> _createBicyclePowerStandardWheelTorqueMsg = { .func = NULL };
    AntCallback<BicyclePowerStandardCrankTorqueMsg&> _createBicyclePowerStandardCrankTorqueMsg = { .func = NULL };
    AntCallback<BicyclePowerCrankTorqueFrequencyMsg&> _createBicyclePowerCrankTorqueFrequencyMsg = { .func = NULL };
    AntCallback<BicyclePowerTorqueEffectivenessAndPedalSmoothnessMsg&> _createBicyclePowerTorqueEffectivenessAndPedalSmoothnessMsg = { .func = NULL };
    uint8_t _nextBackgroundPage;
    uint8_t _patternStep = 0;
    uint32_t _flags = 0;
};

#endif // ANTPLUS_PROFILEBICYCLEPOWERSENSOR_h
