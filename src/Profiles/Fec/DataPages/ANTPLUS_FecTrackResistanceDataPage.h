#ifndef ANTPLUS_FECTRACKRESISTANCEDATAPAGE_h
#define ANTPLUS_FECTRACKRESISTANCEDATAPAGE_h

#include <Profiles/Fec/DataPages/ANTPLUS_FecBaseMainDataPage.h>

template<class T>
class FecBaseTrackResistanceDataPage : virtual public CoreDataPage<T> {
public:
    FecBaseTrackResistanceDataPage();
    uint16_t getGrade();
};

class FecTrackResistanceDataPage : public FecBaseMainDataPage, public FecBaseTrackResistanceDataPage<BroadcastData> {
public:
    explicit FecTrackResistanceDataPage(AntRxDataResponse& dp);
};

class FecTrackResistanceDataMsg : public FecBaseMainDataPageMsg, public FecBaseTrackResistanceDataPage<BroadcastDataMsg> {
public:
    FecTrackResistanceDataMsg();
    void setTargetGrade(uint16_t TargetGrade);
};


#endif // ANTPLUS_FECTRACKRESISTANCEDATAPAGE_h

