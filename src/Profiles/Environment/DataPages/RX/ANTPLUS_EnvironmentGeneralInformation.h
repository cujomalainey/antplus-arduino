#ifndef ANTPLUS_ENVIRONMENTGENERALINFORMATION_h
#define ANTPLUS_ENVIRONMENTGENERALINFORMATION_h

#include <Profiles/Environment/DataPages/Base/ANTPLUS_EnvironmentBaseDataPage.h>

class EnvironmentGeneralInformation : public EnvironmentBaseDataPage {
public:
    EnvironmentGeneralInformation(AntRxDataResponse& dp);
    uint8_t getTransmissionInfoLocalTime();
    uint8_t getTransmissionInfoUtcTime();
    uint8_t getTransmissionInfoDefaultTransmissionRate();
    uint32_t getSupportedPages();
};

#endif // ANTPLUS_ENVIRONMENTGENERALINFORMATION_h

