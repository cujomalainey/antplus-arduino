#ifndef ANTPLUS_FECTRACKRESISTANCE_h
#define ANTPLUS_FECTRACKRESISTANCE_h

#include <Profiles/Fec/DataPages/ANTPLUS_FecBaseMainDataPage.h>

template<class T>
class FecBaseTrackResistance : virtual public CoreDataPage<T> {
public:
    FecBaseTrackResistance();
    uint16_t getGrade();
    uint8_t getCoefficientOfRollingResistance();
};

class FecTrackResistance : public FecBaseMainDataPage, public FecBaseTrackResistance<BroadcastData> {
public:
    explicit FecTrackResistance(AntRxDataResponse& dp);
};

class FecTrackResistanceMsg : public FecBaseMainDataPageMsg, public FecBaseTrackResistance<BroadcastDataMsg> {
public:
    FecTrackResistanceMsg();
    void setTargetGrade(uint16_t targetGrade);
    void setCoefficientOfRollingResistance(uint8_t coefficient);
};


#endif // ANTPLUS_FECTRACKRESISTANCE_h

