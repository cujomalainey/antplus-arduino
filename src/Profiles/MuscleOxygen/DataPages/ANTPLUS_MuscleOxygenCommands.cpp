#include <Profiles/MuscleOxygen/DataPages/ANTPLUS_MuscleOxygenCommands.h>
#include <Profiles/MuscleOxygen/ANTPLUS_MuscleOxygenPrivateDefines.h>

#define COMMANDID_BYTE 1
#define RESERVED_BYTE 2
#define LOCALTIMEOFFSET_BYTE 3
#define CURRENTTIMETIMESTAMP_LSB_BYTE 4
#define CURRENTTIMETIMESTAMP_MSB_BYTE 7

#define RESERVED_VALUE 0xFF

template<class T>
MuscleOxygenBaseCommands<T>::MuscleOxygenBaseCommands() : CoreDataPage<T>() {}

template<class T>
uint8_t MuscleOxygenBaseCommands<T>::getCommandId() {
    return this->get8BitValue(COMMANDID_BYTE);
}

template<class T>
uint8_t MuscleOxygenBaseCommands<T>::getLocalTimeOffset() {
    return this->get8BitValue(LOCALTIMEOFFSET_BYTE);
}

template<class T>
uint32_t MuscleOxygenBaseCommands<T>::getCurrentTimestamp() {
    return this->get32BitValue(CURRENTTIMETIMESTAMP_LSB_BYTE,
            CURRENTTIMETIMESTAMP_MSB_BYTE);
}

template class MuscleOxygenBaseCommands<BroadcastData>;
template class MuscleOxygenBaseCommands<BroadcastDataMsg>;

MuscleOxygenCommands::MuscleOxygenCommands(AntRxDataResponse& dp) :
    MuscleOxygenBaseMainDataPage(dp),
    MuscleOxygenBaseCommands<BroadcastData>() {}

MuscleOxygenCommandsMsg::MuscleOxygenCommandsMsg() :
    MuscleOxygenBaseMainDataPageMsg(MUSCLEOXYGEN_COMMANDS_NUMBER),
    MuscleOxygenBaseCommands<BroadcastDataMsg>() {
    set8BitValue(RESERVED_VALUE, RESERVED_BYTE);
}

void MuscleOxygenCommandsMsg::setCommandId(uint8_t id) {
    set8BitValue(id, COMMANDID_BYTE);
}

void MuscleOxygenCommandsMsg::setLocalTimeOffset(uint8_t offset) {
    set8BitValue(offset, LOCALTIMEOFFSET_BYTE);
}

void MuscleOxygenCommandsMsg::setCurrentTimestamp(uint32_t timestamp) {
    set32BitValue(timestamp, CURRENTTIMETIMESTAMP_LSB_BYTE,
            CURRENTTIMETIMESTAMP_MSB_BYTE);
}
