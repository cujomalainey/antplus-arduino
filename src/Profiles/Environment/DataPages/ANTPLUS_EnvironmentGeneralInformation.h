#ifndef ANTPLUS_ENVIRONMENTGENERALINFORMATION_h
#define ANTPLUS_ENVIRONMENTGENERALINFORMATION_h

#include <Profiles/Environment/DataPages/ANTPLUS_EnvironmentBaseDataPage.h>

template<class T>
class EnvironmentBaseGeneralInformation : virtual public CoreDataPage<T> {
public:
    EnvironmentBaseGeneralInformation();
    uint8_t getTransmissionInfoLocalTime();
    uint8_t getTransmissionInfoUtcTime();
    uint8_t getTransmissionInfoDefaultTransmissionRate();
    uint32_t getSupportedPages();
};

class EnvironmentGeneralInformation : public EnvironmentBaseDataPage, public EnvironmentBaseGeneralInformation<BroadcastData> {
public:
    explicit EnvironmentGeneralInformation(AntRxDataResponse& dp);
};

#endif // ANTPLUS_ENVIRONMENTGENERALINFORMATION_h
