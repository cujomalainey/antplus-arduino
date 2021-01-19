#ifndef ANTPLUS_FECTRAINERDATA_h
#define ANTPLUS_FECTRAINERDATA_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>

template<class T>
class FECTrainerDataPage : virtual public CoreDataPage<T> {
public:
    FECTrainerDataPage();
    uint8_t getDataPageNumber();
    uint8_t getUpdateEventCount();
    uint8_t getInstantaneousCadence();
    uint16_t getAccumulatedPower();
    uint16_t getInstantaneousPower();
    uint8_t getTrainerStatusBits();
    uint8_t getFlagsBits();
    uint8_t getFEStateBits();
};

class FECTrainerData : public BaseDataPage<BroadcastData>, public FECTrainerDataPage<BroadcastData> {
public:
    explicit FECTrainerData(AntRxDataResponse& dp);
};

#endif // ANTPLUS_FECTRAINERDATA_h
