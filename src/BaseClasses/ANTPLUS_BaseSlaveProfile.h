#ifndef ANTPLUS_BASESLAVEPROFILE_h
#define ANTPLUS_BASESLAVEPROFILE_h

#include <BaseClasses/ANTPLUS_BaseProfile.h>

class BaseSlaveProfile : public BaseProfile {
public:
    BaseSlaveProfile();
    BaseSlaveProfile(uint16_t deviceNumber);
    BaseSlaveProfile(uint16_t deviceNumber, uint8_t transmissionType);
    /**
     * Will return once the device either pairs or timesout its search
     */
    uint8_t waitForPair();
private:
};

#endif // ANTPLUS_BASESLAVEPROFILE_h
