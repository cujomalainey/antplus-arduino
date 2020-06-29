#ifndef ANTPLUS_ENVIRONMENTGENERALINFORMATION_h
#define ANTPLUS_ENVIRONMENTGENERALINFORMATION_h

#include <Profiles/Environment/DataPages/Base/ANTPLUS_EnvironmentBaseDataPage.h>
#include <Profiles/Environment/DataPages/Base/ANTPLUS_EnvironmentBaseGeneralInformation.h>

class EnvironmentGeneralInformation : public EnvironmentBaseDataPage, public EnvironmentBaseGeneralInformation<BroadcastData> {
public:
    EnvironmentGeneralInformation(AntRxDataResponse& dp);
};

#endif // ANTPLUS_ENVIRONMENTGENERALINFORMATION_h
