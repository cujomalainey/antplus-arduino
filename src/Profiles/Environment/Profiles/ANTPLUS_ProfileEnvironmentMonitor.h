#ifndef ANTPLUS_PROFILEENVIRONMENTMONITOR_h
#define ANTPLUS_PROFILEENVIRONMENTMONITOR_h

#include <BaseClasses/ANTPLUS_BaseMasterProfile.h>
#include <Profiles/Environment/ANTPLUS_EnvironmentDataPages.h>
#include <CommonDataPages/ANTPLUS_CommonDataPages.h>

class ProfileEnvironmentMonitor : BaseMasterProfile {
public:
    // TODO
    ProfileEnvironmentMonitor(uint16_t deviceNumber, uint8_t transmissionType = 0);
};

#endif // ANTPLUS_PROFILEENVIRONMENTMONITOR_h
