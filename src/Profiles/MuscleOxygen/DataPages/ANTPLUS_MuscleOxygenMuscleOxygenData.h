#ifndef ANTPLUS_MUSCLEOXYGENMUSCLEOXYGENDATA_h
#define ANTPLUS_MUSCLEOXYGENMUSCLEOXYGENDATA_h

#include <Profiles/MuscleOxygen/DataPages/ANTPLUS_MuscleOxygenBaseMainDataPage.h>

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

class MuscleOxygenMuscleOxygenDataMsg : public MuscleOxygenBaseMainDataPageMsg, public MuscleOxygenBaseMuscleOxygenData<BroadcastDataMsg> {
public:
    MuscleOxygenMuscleOxygenDataMsg();
    void setEventCount(uint8_t n);
    void setNotifications(uint8_t notficications);
    void setCapabilities(uint8_t capabilities);
    void setTotalHemoglobinConcentration(uint16_t concentration);
    void setPreviousSaturatedHemoglobinPercentage(uint16_t percent);
    void setCurrentSaturatedHemoglobinPercentage(uint16_t percent);
};

#endif // ANTPLUS_MUSCLEOXYGENMUSCLEOXYGENDATA_h
