#ifndef ANTPLUS_FECTRAINERDATA_h
#define ANTPLUS_FECTRAINERDATA_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>

template<class T>
class FecBaseSpecificTrainerData : virtual public CoreDataPage<T> {
public:
    FecBaseSpecificTrainerData();
    uint8_t getDataPageNumber();
    uint8_t getUpdateEventCount();
    uint8_t getInstantaneousCadence();
    uint16_t getAccumulatedPower();
    uint16_t getInstantaneousPower();
    uint8_t getTrainerStatusBits();
    uint8_t getFlagsBits();
    uint8_t getFEStateBits();
};

class FecSpecificTrainerData : public BaseDataPage<BroadcastData>, public FecBaseSpecificTrainerData<BroadcastData> {
public:
    explicit FecSpecificTrainerData(AntRxDataResponse& dp);
};

#endif // ANTPLUS_FECTRAINERDATA_h
