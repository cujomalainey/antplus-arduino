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
     * Starts a search for all devices configured with this profle
     * This will disrupt all other channels to do the search, therefore you will have to
     * call start() on all registered profiles.
     * This is a blocking method, see backgroundDeviceSearch for a non-blocking variation.
     *
     * returns the number of the ids filled.
     */
    uint8_t searchForDevices(uint16_t* buffer);

    /**
     * Pass in a pointer to an array uint16_t[ANTPLUS_MAX_CHANNELS_POSSIBLE]
     * Start a non-blocking search for the following device profile.
     * This will disrupt all other channels to do the search, therefore you will have to
     * call start() on all registered profiles.
     */
    void backgroundDeviceSearch(uint16_t* buffer);

    /**
     * Check the status of the backgroundDeviceSearch.
     */
    uint8_t backgroundDeviceSearchStatus();

    /**
     * Call this to determine the number of devices found using backgroundDeviceSearch.
     * This can be called before the search is completed.
     */
    uint8_t backgroundDeviceSearchNumberDevices();

    /**
     * TODO
     *
     * Register a callback method for when backgroundDeviceSearch completes.
     */
    void backgroundDeviceSearchCallback();

    /**
     * Will return once the device either pairs or timesout its search
     */
    uint8_t waitForPair();

private:
};

#endif // ANTPLUS_BASESLAVEPROFILE_h
