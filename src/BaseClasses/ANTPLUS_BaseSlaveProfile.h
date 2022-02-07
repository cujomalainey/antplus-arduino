#ifndef ANTPLUS_BASESLAVEPROFILE_h
#define ANTPLUS_BASESLAVEPROFILE_h

#include <BaseClasses/ANTPLUS_BaseProfile.h>

class BaseSlaveProfile : public BaseProfile {
public:
    explicit BaseSlaveProfile(uint16_t deviceNumber = 0, uint8_t transmissionType = 0);
    /**
     * Will return once the device either pairs or timesout its search
     */
    uint8_t waitForPair();
private:
};

#endif // ANTPLUS_BASESLAVEPROFILE_h
