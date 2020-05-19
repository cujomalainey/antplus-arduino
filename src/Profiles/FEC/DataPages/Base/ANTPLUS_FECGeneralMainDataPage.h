#ifndef ANTPLUS_FECCOREMAINDATAPAGE_h
#define ANTPLUS_FECCOREMAINDATAPAGE_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

template<class T>
class FECGeneralMainDataPage : virtual public CoreDataPage<T> {
public:
    FECGeneralMainDataPage();
    uint8_t getDataPageNumber();
    uint8_t getEquipmentTypeBits();
    uint8_t getElapsedTime();
    uint8_t getDistanceTraveled();
    uint16_t getSpeed();
    uint8_t getHeartRate();
    uint8_t getCapabilitiesBits();
    uint8_t getFEStateBits();
};

#endif // ANTPLUS_FECCOREMAINDATAPAGE_h
