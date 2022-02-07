#ifndef ANTPLUS_FECTRAINERDATA_h
#define ANTPLUS_FECTRAINERDATA_h

#include <Profiles/Fec/DataPages/ANTPLUS_FecBaseMainDataPage.h>

template<class T>
class FecBaseSpecificTrainerData : virtual public CoreDataPage<T> {
public:
    FecBaseSpecificTrainerData();
    uint8_t getUpdateEventCount();
    uint8_t getInstantaneousCadence();
    uint16_t getAccumulatedPower();
    uint16_t getInstantaneousPower();
    uint8_t getBicyclePowerCalibration();
    uint8_t getResistanceCalibration();
    uint8_t getUserConfiguration();
    uint8_t getTargetPowerLimits();
    uint8_t getFeState();
    uint8_t getLapToggleBit();
};

class FecSpecificTrainerData : public BaseDataPage<BroadcastData>, public FecBaseSpecificTrainerData<BroadcastData> {
public:
    explicit FecSpecificTrainerData(AntRxDataResponse& dp);
};

class FecSpecificTrainerDataMsg : public BaseDataPageMsg<BroadcastDataMsg>, public FecBaseSpecificTrainerData<BroadcastDataMsg> {
public:
    FecSpecificTrainerDataMsg();
    void setUpdateEventCount(uint8_t eventCount);
    void setInstantaneousCadence(uint8_t cadence);
    void setAccumulatedPower(uint16_t accPower);
    void setInstantaneousPower(uint16_t intPower);
    void setBicyclePowerCalibration(uint8_t powerCalibration);
    void setResistanceCalibration(uint8_t resistanceCalibration);
    void setUserConfiguration(uint8_t userConfiguration);
    void setTargetPowerLimits(uint8_t targetPower);
    void setFeState(uint8_t feState);
    void setLapToggleBit(uint8_t lapToggle);
};

#endif // ANTPLUS_FECTRAINERDATA_h
