#include <Profiles/Fec/DataPages/ANTPLUS_FecBasicResistance.h>
#include <Profiles/Fec/ANTPLUS_FecPrivateDefines.h>

#define RESERVED0_LSB_BYTE 1
#define RESERVED0_MSB_BYTE 4
#define RESERVED0_VALUE 0xFFFFFFFF
#define RESERVED1_LSB_BYTE 5
#define RESERVED1_MSB_BYTE 6
#define RESERVED1_VALUE 0xFFFF
#define TOTAL_RESISTANCE_BYTE 7

template<class T>
FecBaseBasicResistance<T>::FecBaseBasicResistance() :
    CoreDataPage<T>() {}

template<class T>
uint8_t FecBaseBasicResistance<T>::getTotalResistance() {
    return this->get8BitValue(TOTAL_RESISTANCE_BYTE);
}

template class FecBaseBasicResistance<BroadcastData>;
template class FecBaseBasicResistance<BroadcastDataMsg>;

FecBasicResistance::FecBasicResistance(AntRxDataResponse& dp) :
    FecBaseMainDataPage(dp),
    FecBaseBasicResistance<BroadcastData>() {}

FecBasicResistanceMsg::FecBasicResistanceMsg() :
    FecBaseMainDataPageMsg(ANTPLUS_FEC_DATAPAGE_TRACKRESISTANCE_NUMBER),
    FecBaseBasicResistance<BroadcastDataMsg>() {
    set32BitValue(RESERVED0_VALUE, RESERVED0_LSB_BYTE, RESERVED0_MSB_BYTE);
    set16BitValue(RESERVED1_VALUE, RESERVED1_LSB_BYTE, RESERVED1_MSB_BYTE);
}

void FecBasicResistanceMsg::setTotalResistance(uint8_t totalResistance) {
    set8BitValue(totalResistance, TOTAL_RESISTANCE_BYTE);
}
