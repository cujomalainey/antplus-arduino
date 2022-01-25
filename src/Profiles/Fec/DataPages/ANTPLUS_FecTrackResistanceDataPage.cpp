#include <Profiles/Fec/DataPages/ANTPLUS_FecTrackResistanceDataPage.h>
#include <Profiles/Fec/ANTPLUS_FecPrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

// TODO this is a mixture of datapages
#define GRADE_LSB_BYTE 5
#define GRADE_MSB_BYTE 6

template<class T>
FecBaseTrackResistanceDataPage<T>::FecBaseTrackResistanceDataPage() :
    CoreDataPage<T>() {}

template<class T>
uint16_t FecBaseTrackResistanceDataPage<T>::getGrade() {
    return this->get16BitValue(GRADE_LSB_BYTE, GRADE_MSB_BYTE);
}

template class FecBaseTrackResistanceDataPage<BroadcastData>;
template class FecBaseTrackResistanceDataPage<BroadcastDataMsg>;

FecTrackResistanceDataPage::FecTrackResistanceDataPage(AntRxDataResponse& dp) :
    FecBaseMainDataPage(dp),
    FecBaseTrackResistanceDataPage<BroadcastData>() {}

FecTrackResistanceDataMsg::FecTrackResistanceDataMsg() :
    FecBaseMainDataPageMsg(TRACK_RESISTANCE_NUMBER),
    FecBaseTrackResistanceDataPage<BroadcastDataMsg>() {}

void FecTrackResistanceDataMsg::setTargetGrade(uint16_t TargetGrade) {
    set16BitValue(TargetGrade, GRADE_LSB_BYTE, GRADE_MSB_BYTE);
}
