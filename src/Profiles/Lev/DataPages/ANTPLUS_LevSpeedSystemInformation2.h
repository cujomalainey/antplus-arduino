#ifndef ANTPLUS_LEVSPEEDSYSTEMINFORMATION2_h
#define ANTPLUS_LEVSPEEDSYSTEMINFORMATION2_h

#include <Profiles/Lev/DataPages/ANTPLUS_LevBaseSpeedSystemInformation.h>

template<class T>
class LevBaseSpeedSystemInformation2 : virtual public CoreDataPage<T> {
public:
    LevBaseSpeedSystemInformation2();
    uint8_t getBatterySOC();
    uint8_t getBatteryEmptyWarning();
    uint8_t getPercentAssist();
};

class LevSpeedSystemInformation2 : public LevBaseSpeedSystemInformation, public LevBaseSpeedSystemInformation2<BroadcastData> {
public:
    explicit LevSpeedSystemInformation2(AntRxDataResponse& dp);
};

class LevSpeedSystemInformation2Msg : public LevBaseSpeedSystemInformationMsg, public LevBaseSpeedSystemInformation2<BroadcastDataMsg> {
public:
    LevSpeedSystemInformation2Msg();
    void setBatterySOC(uint8_t soc);
    void setBatteryEmptyWarning(uint8_t warning);
    void setPercentAssist(uint8_t percent);
};

#endif // ANTPLUS_LEVSPEEDSYSTEMINFORMATION2_h
