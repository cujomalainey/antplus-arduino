#ifndef ANTPLUS_MUSCLEOXYGENBASEMUSCLEOXYGENDATA_h
#define ANTPLUS_MUSCLEOXYGENBASEMUSCLEOXYGENDATA_h

#include <Profiles/MuscleOxygen/DataPages/Base/ANTPLUS_MuscleOxygenBaseMainDataPage.h>

template<class T>
class MuscleOxygenBaseMuscleOxygenData : public virtual CoreDataPage<T> {
public:
    MuscleOxygenBaseMuscleOxygenData();
    uint8_t getEventCount();
    uint8_t getNotifications();
    uint8_t getCapabilities();
    uint16_t getTotalHemoglobinConcentration();
    uint16_t getPreviousSaturatedHemoglobinPercentage();
    uint16_t getCurrentSaturatedHemoglobinPercentage();
};

#endif // ANTPLUS_MUSCLEOXYGENBASEMUSCLEOXYGENDATA_h
