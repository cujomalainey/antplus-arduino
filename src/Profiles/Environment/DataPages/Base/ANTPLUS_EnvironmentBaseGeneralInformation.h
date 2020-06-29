#ifndef ANTPLUS_ENVIRONMENTBASEGENERALINFORMATION_h
#define ANTPLUS_ENVIRONMENTBASEGENERALINFORMATION_h

#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

template<class T>
class EnvironmentBaseGeneralInformation : virtual public CoreDataPage<T> {
public:
    EnvironmentBaseGeneralInformation();
    uint8_t getTransmissionInfoLocalTime();
    uint8_t getTransmissionInfoUtcTime();
    uint8_t getTransmissionInfoDefaultTransmissionRate();
    uint32_t getSupportedPages();
};

#endif // ANTPLUS_ENVIRONMENTBASEGENERALINFORMATION_h
