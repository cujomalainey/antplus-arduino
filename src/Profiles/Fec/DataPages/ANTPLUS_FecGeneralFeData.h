#ifndef ANTPLUS_FECGENERALFEDATA_h
#define ANTPLUS_FECGENERALFEDATA_h

#include <Profiles/Fec/DataPages/ANTPLUS_FecBaseMainDataPage.h>

template<class T>
class FecBaseGeneralFeData : virtual public CoreDataPage<T> {
public:
    FecBaseGeneralFeData();
    uint8_t getFeType();
    uint8_t getElapsedTime();
    uint8_t getDistanceTraveled();
    uint16_t getSpeed();
    uint8_t getHeartRate();
    uint8_t getHrDataSource();
    uint8_t getDistanceTraveledEnabled();
    uint8_t getVirtualSpeedFlag();
    uint8_t getFeState();
    uint8_t getLapToggleBit();
};

class FecGeneralFeData : public FecBaseMainDataPage, public FecBaseGeneralFeData<BroadcastData> {
public:
    explicit FecGeneralFeData(AntRxDataResponse& dp);
};

class FecGeneralFeDataMsg : public FecBaseMainDataPageMsg, public FecBaseGeneralFeData<BroadcastDataMsg> {
public:
    FecGeneralFeDataMsg();
    void setFeType(uint8_t fe_type);
    void setElapsedTime(uint8_t time);
    void setDistanceTraveled(uint8_t distance);
    void setSpeed(uint16_t speed);
    void setHeartRate(uint8_t hr);
    void setHrDataSource(uint8_t source);
    void setDistanceTraveledEnabled(uint8_t enabled);
    void setVirtualSpeedFlag(uint8_t real);
    void setFeState(uint8_t state);
    void setLapToggleBit(uint8_t toggle);
};


#endif // ANTPLUS_FECGENERALFEDATA_h
