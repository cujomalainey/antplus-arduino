#ifndef ANTPLUS_MUSCLEOXYGENCOMMANDS_h
#define ANTPLUS_MUSCLEOXYGENCOMMANDS_h

#include <Profiles/MuscleOxygen/DataPages/ANTPLUS_MuscleOxygenBaseMainDataPage.h>

template<class T>
class MuscleOxygenBaseCommands : public virtual CoreDataPage<T> {
public:
    MuscleOxygenBaseCommands();
    uint8_t getCommandId();
    uint8_t getLocalTimeOffset();
    uint32_t getCurrentTimestamp();
};

class MuscleOxygenCommands :
    public MuscleOxygenBaseMainDataPage,
    public MuscleOxygenBaseCommands<BroadcastData> {
public:
    explicit MuscleOxygenCommands(AntRxDataResponse& dp);
};

class MuscleOxygenCommandsMsg :
    public MuscleOxygenBaseMainDataPageMsg,
    public MuscleOxygenBaseCommands<BroadcastDataMsg> {
public:
    MuscleOxygenCommandsMsg();
    void setCommandId(uint8_t id);
    void setLocalTimeOffset(uint8_t offset);
    void setCurrentTimestamp(uint32_t timestamp);
};

#endif // ANTPLUS_MUSCLEOXYGENMUSCLEOXYGENDATA_h
