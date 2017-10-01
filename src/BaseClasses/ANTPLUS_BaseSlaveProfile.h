#ifndef ANTPLUS_BASESLAVEPROFILE_h
#define ANTPLUS_BASESLAVEPROFILE_h

#include <BaseClasses/ANTPLUS_BaseProfile.h>

class BaseSlaveProfile : public BaseProfile {
public:
    BaseSlaveProfile();
    BaseSlaveProfile(uint16_t deviceNumber);
    BaseSlaveProfile(uint16_t deviceNumber, uint8_t transmissionType);

    /**
     * Pass in a pointer to an array uint16_t[ANTPLUS_MAX_CHANNELS_POSSIBLE]
     *
     * Any non-0 entry after the function returned is a nearby device
     */
    void searchForDevices(uint16_t* buffer);
    /**
     * Will return once the device either pairs or timesout its search
     */
    uint8_t waitForPair();

private:
};

#endif // ANTPLUS_BASESLAVEPROFILE_h