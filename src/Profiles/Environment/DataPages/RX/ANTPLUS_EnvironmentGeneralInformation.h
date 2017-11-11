#ifndef ANTPLUS_ENVIRONMENTGENERALINFORMATION_h
#define ANTPLUS_ENVIRONMENTGENERALINFORMATION_h

#include <Profiles/Environment/DataPages/Base/ANTPLUS_EnvironmentBaseDataPage.h>

class EnvironmentGeneralInformation : public EnvironmentBaseDataPage {
public:
    EnvironmentGeneralInformation(AntRxDataResponse& dp);
};

#endif // ANTPLUS_ENVIRONMENTGENERALINFORMATION_h

