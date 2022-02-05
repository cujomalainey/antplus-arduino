#ifndef ANTPLUS_LEVSPEEDSYSTEMINFORMATION1_h
#define ANTPLUS_LEVSPEEDSYSTEMINFORMATION1_h

#include <Profiles/Lev/DataPages/ANTPLUS_LevBaseSpeedSystemInformation.h>

template<class T>
class LevBaseSpeedSystemInformation1 : virtual public CoreDataPage<T> {
public:
    LevBaseSpeedSystemInformation1();
    uint8_t getBatteryTemperatureState();
    uint8_t getBatteryTemperatureAlert();
    uint8_t getMotorTemperatureState();
    uint8_t getMotorTemperatureAlert();
    uint8_t getErrorMessage();
};

class LevSpeedSystemInformation1 : public LevBaseSpeedSystemInformation, public LevBaseSpeedSystemInformation1<BroadcastData> {
public:
    explicit LevSpeedSystemInformation1(AntRxDataResponse& dp);
};

class LevSpeedSystemInformation1Msg : public LevBaseSpeedSystemInformationMsg, public LevBaseSpeedSystemInformation1<BroadcastDataMsg> {
public:
    LevSpeedSystemInformation1Msg();
    void setBatteryTemperatureState(uint8_t state);
    void setBatteryTemperatureAlert(uint8_t alert);
    void setMotorTemperatureState(uint8_t state);
    void setMotorTemperatureAlert(uint8_t alert);
    void setErrorMessage(uint8_t err);
};

#endif // ANTPLUS_LEVSPEEDSYSTEMINFORMATION1_h
