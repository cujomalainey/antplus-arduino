#ifndef ANTPLUS_FECTRAINERDATA_h
#define ANTPLUS_FECTRAINERDATA_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>

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

// TODO TX type

#endif // ANTPLUS_FECTRAINERDATA_h
