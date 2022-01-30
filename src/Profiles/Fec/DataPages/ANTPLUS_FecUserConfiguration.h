#ifndef ANTPLUS_FECUSERCONFIGURATION_h
#define ANTPLUS_FECUSERCONFIGURATION_h

#include <Profiles/Fec/DataPages/ANTPLUS_FecBaseMainDataPage.h>

template<class T>
class FecBaseUserConfiguration : virtual public CoreDataPage<T> {
public:
    FecBaseUserConfiguration();
    uint16_t getUserWeight();
    uint8_t getBicycleWheelDiameterOffset();
    uint16_t getBicycleWeight();
    uint8_t getBicycleWheelDiameter();
    uint8_t getGearRatio();
};

class FecUserConfiguration : public FecBaseMainDataPage, public FecBaseUserConfiguration<BroadcastData> {
public:
    explicit FecUserConfiguration(AntRxDataResponse& dp);
};

class FecUserConfigurationMsg : public FecBaseMainDataPageMsg, public FecBaseUserConfiguration<BroadcastDataMsg> {
public:
    FecUserConfigurationMsg();
    void setUserWeight(uint16_t userWeight);
    void setBicycleWheelDiameterOffset(uint8_t offset);
    void setBicycleWeight(uint16_t bicycleWeight);
    void setBicycleWheelDiameter(uint8_t diameter);
    void setGearRatio(uint8_t gearRatio);
};

#endif // ANTPLUS_FECUSERCONFIGURATION_h

