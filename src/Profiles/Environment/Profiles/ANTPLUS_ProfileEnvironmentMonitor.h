#ifndef ANTPLUS_PROFILEENVIRONMENTMONITOR_h
#define ANTPLUS_PROFILEENVIRONMENTMONITOR_h

#include <BaseClasses/ANTPLUS_BaseMasterProfile.h>
#include <Profiles/Environment/ANTPLUS_ProfileEnvironmentDataPages.h>
#include <CommonDataPages/ANTPLUS_CommonDataPages.h>

class ProfileEnvironmentMonitor : BaseMasterProfile {
public:
    // TODO
    ProfileEnvironmentMonitor();
    ProfileEnvironmentMonitor(uint16_t deviceNumber);
    ProfileEnvironmentMonitor(uint16_t deviceNumber, uint8_t transmissionType);
};

#endif // ANTPLUS_PROFILEENVIRONMENTMONITOR_h
