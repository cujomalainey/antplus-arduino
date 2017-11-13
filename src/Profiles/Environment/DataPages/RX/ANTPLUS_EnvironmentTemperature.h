#ifndef ANTPLUS_ENVIRONMENTTEMPERATURE_h
#define ANTPLUS_ENVIRONMENTTEMPERATURE_h

#include <Profiles/Environment/DataPages/Base/ANTPLUS_EnvironmentBaseDataPage.h>

class EnvironmentTemperature : public EnvironmentBaseDataPage {
public:
    EnvironmentTemperature(AntRxDataResponse& dp);
};

#endif // ANTPLUS_ENVIRONMENTTEMPERATURE_h

