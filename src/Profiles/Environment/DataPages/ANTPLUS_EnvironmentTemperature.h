#ifndef ANTPLUS_ENVIRONMENTTEMPERATURE_h
#define ANTPLUS_ENVIRONMENTTEMPERATURE_h

#include <Profiles/Environment/DataPages/ANTPLUS_EnvironmentBaseDataPage.h>

template<class T>
class EnvironmentBaseTemperature : virtual public CoreDataPage<T> {
public:
    EnvironmentBaseTemperature();
    uint8_t getEventCount();
    int16_t get24HourLow();
    int16_t get24HourHigh();
    int16_t getCurrentTemp();
};

class EnvironmentTemperature : public EnvironmentBaseDataPage, public EnvironmentBaseTemperature<BroadcastData> {
public:
    explicit EnvironmentTemperature(AntRxDataResponse& dp);
};

#endif // ANTPLUS_ENVIRONMENTTEMPERATURE_h

