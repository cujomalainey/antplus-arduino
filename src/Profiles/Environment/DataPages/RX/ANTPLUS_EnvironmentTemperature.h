#ifndef ANTPLUS_ENVIRONMENTTEMPERATURE_h
#define ANTPLUS_ENVIRONMENTTEMPERATURE_h

#include <Profiles/Environment/DataPages/Base/ANTPLUS_EnvironmentBaseDataPage.h>
#include <Profiles/Environment/DataPages/Base/ANTPLUS_EnvironmentBaseTemperature.h>

class EnvironmentTemperature : public EnvironmentBaseDataPage, public EnvironmentBaseTemperature<BroadcastData> {
public:
    explicit EnvironmentTemperature(AntRxDataResponse& dp);
};

#endif // ANTPLUS_ENVIRONMENTTEMPERATURE_h

