#ifndef ANTPLUS_MUSCLEOXYGENBASEMAINDATAPAGEMSG_h
#define ANTPLUS_MUSCLEOXYGENBASEMAINDATAPAGEMSG_h

#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>
#include <Profiles/MuscleOxygen/ANTPLUS_MuscleOxygenPrivateDefines.h>

#include "ANT.h"

class MuscleOxygenBaseGenericMsg : public BaseDataPageMsg<BroadcastDataMsg> {
public:
    MuscleOxygenBaseGenericMsg();

    void      copyData(uint8_t * buf, size_t len) { memcpy(_buffer, buf, len); }

protected:
    uint8_t _buffer[MESSAGE_SIZE];
};

class MuscleOxygenBaseMainDataPageMsg : public MuscleOxygenBaseGenericMsg {
public:
    MuscleOxygenBaseMainDataPageMsg(uint8_t dataPageNumber = ANTPLUS_MUSCLEOXYGEN_DATAPAGE_MUSCLEOXYGENDATA);

    void setTotalHemoglobinConcentration( uint16_t tc );
    void setCurrentSaturatedHemoglobinPercentage(uint16_t cp);

    // internal
    void setEventCount(uint8_t n);
    void setNotifications(uint8_t n = 0x00);
    void setCapabilities(uint8_t c = 0x06);
};

#endif // ANTPLUS_MUSCLEOXYGENBASEMAINDATAPAGEMSG_h
