#ifndef ANTPLUS_FECUSERCONFIGURATION_h
#define ANTPLUS_FECUSERCONFIGURATION_h

#include <Profiles/Fec/DataPages/ANTPLUS_FecBaseMainDataPage.h>

// TODO missing fields

template<class T>
class FecBaseUserConfiguration : virtual public CoreDataPage<T> {
public:
    FecBaseUserConfiguration();
    uint16_t getUserWeight();
    uint16_t getBikeWeight();
};

class FecUserConfiguration : public FecBaseMainDataPage, public FecBaseUserConfiguration<BroadcastData> {
public:
    explicit FecUserConfiguration(AntRxDataResponse& dp);
};

class FecUserConfigurationMsg : public FecBaseMainDataPageMsg, public FecBaseUserConfiguration<BroadcastDataMsg> {
public:
    FecUserConfigurationMsg();
    void setUserWeight(uint16_t UserWeight);
    void setBikeWeight(uint16_t BikeWeight);
};

#endif // ANTPLUS_FECUSERCONFIGURATION_h

