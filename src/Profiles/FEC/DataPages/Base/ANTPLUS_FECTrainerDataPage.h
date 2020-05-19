#ifndef ANTPLUS_FECTRAINERDATAPAGE_h
#define ANTPLUS_FECTRAINERDATAPAGE_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

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

#endif // ANTPLUS_FECTRAINERDATAPAGE_h
