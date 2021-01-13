#ifndef ANTPLUS_MUSCLEOXYGENMUSCLEOXYGENDATAMSG_h
#define ANTPLUS_MUSCLEOXYGENMUSCLEOXYGENDATAMSG_h

#include <Profiles/MuscleOxygen/DataPages/Base/ANTPLUS_MuscleOxygenBaseMainDataPageMsg.h>

#include "ANT.h"

class MuscleOxygenMuscleOxygenDataMsg : public MuscleOxygenBaseMainDataPageMsg {
public:
    MuscleOxygenMuscleOxygenDataMsg();
    void setEventCount(uint8_t n);
    void setNotifications(uint8_t notficications);
    void setCapabilities(uint8_t capabilities);
    void setTotalHemoglobinConcentration(uint16_t concentration);
    void setPreviousSaturatedHemoglobinPercentage(uint16_t percent);
    void setCurrentSaturatedHemoglobinPercentage(uint16_t percent);
};

#endif // ANTPLUS_MUSCLEOXYGENMUSCLEOXYGENDATAMSG_h
