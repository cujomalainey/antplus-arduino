#ifndef ANTPLUS_BASESLAVEPROFILE_h
#define ANTPLUS_BASESLAVEPROFILE_h

#include <BaseClasses/ANTPLUS_BaseProfile.h>

class BaseSlaveProfile : public BaseProfile {
public:
    BaseSlaveProfile(uint8_t channelId);
    /**
     * Open channel and search for master device
     */
    virtual void connect();
    void setChannelId(uint16_t channelId);
    void setDeviceType(uint8_t deviceType);
    void setTransmissionType(uint8_t transmissionType);
private:
    uint16_t _channelId;
    uint8_t _deviceType;
    uint8_t _transmissionType;
};

#endif // ANTPLUS_BASESLAVEPROFILE_h