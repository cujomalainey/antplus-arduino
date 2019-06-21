#ifndef ANTPLUS_MUSCLEOXYGENBASEMAINDATAPAGEMSG_h
#define ANTPLUS_MUSCLEOXYGENBASEMAINDATAPAGEMSG_h

#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>
#include <Profiles/MuscleOxygen/ANTPLUS_MuscleOxygenPrivateDefines.h>

#include "ANT.h"

class MuscleOxygenBaseMainDataPageMsg : public BaseDataPageMsg<BroadcastDataMsg> {
public:
    MuscleOxygenBaseMainDataPageMsg(uint8_t dataPageNumber = ANTPLUS_MUSCLEOXYGEN_DATAPAGE_MUSCLEOXYGENDATA_NUMBER);

    void setTotalHemoglobinConcentration( uint16_t tc );
    void setCurrentSaturatedHemoglobinPercentage(uint16_t cp);
    void setNotifications(uint8_t n = 0x00);
    void setCapabilities(uint8_t c = 0x06);
    void setEventCount(uint8_t n);

protected:
    uint8_t _buffer[MESSAGE_SIZE];
};

#endif // ANTPLUS_MUSCLEOXYGENBASEMAINDATAPAGEMSG_h
