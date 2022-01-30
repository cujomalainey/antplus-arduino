#include <Profiles/Fec/DataPages/ANTPLUS_FecTrackResistance.h>
#include <Profiles/Fec/ANTPLUS_FecPrivateDefines.h>

#define RESERVED_LSB_BYTE 1
#define RESERVED_MSB_BYTE 4
#define RESERVED_VALUE 0xFFFFFFFF
#define GRADE_LSB_BYTE 5
#define GRADE_MSB_BYTE 6
#define COEFFICIENTOFROLLINGRESISTANCE_BYTE 7

template<class T>
FecBaseTrackResistance<T>::FecBaseTrackResistance() :
    CoreDataPage<T>() {}

template<class T>
uint16_t FecBaseTrackResistance<T>::getGrade() {
    return this->get16BitValue(GRADE_LSB_BYTE, GRADE_MSB_BYTE);
}

template<class T>
uint8_t FecBaseTrackResistance<T>::getCoefficientOfRollingResistance() {
    return this->get8BitValue(COEFFICIENTOFROLLINGRESISTANCE_BYTE);
}

template class FecBaseTrackResistance<BroadcastData>;
template class FecBaseTrackResistance<BroadcastDataMsg>;

FecTrackResistance::FecTrackResistance(AntRxDataResponse& dp) :
    FecBaseMainDataPage(dp),
    FecBaseTrackResistance<BroadcastData>() {}

FecTrackResistanceMsg::FecTrackResistanceMsg() :
    FecBaseMainDataPageMsg(ANTPLUS_FEC_DATAPAGE_TRACKRESISTANCE_NUMBER),
    FecBaseTrackResistance<BroadcastDataMsg>() {
    set32BitValue(RESERVED_VALUE, RESERVED_LSB_BYTE, RESERVED_MSB_BYTE);
    setTargetGrade(ANTPLUS_FEC_DATAPAGE_TRACKRESISTANCE_GRADE_INVALID);
    setCoefficientOfRollingResistance(ANTPLUS_FEC_DATAPAGE_TRACKRESISTANCE_COEFFICIENTOFROLLINGRESISTANCE_INVALID);
}

void FecTrackResistanceMsg::setTargetGrade(uint16_t TargetGrade) {
    set16BitValue(TargetGrade, GRADE_LSB_BYTE, GRADE_MSB_BYTE);
}

void FecTrackResistanceMsg::setCoefficientOfRollingResistance(uint8_t coefficient) {
    set8BitValue(coefficient, COEFFICIENTOFROLLINGRESISTANCE_BYTE);
}
