#ifndef ANTPLUS_BASEMASTERPROFILE_h
#define ANTPLUS_BASEMASTERPROFILE_h

#include <BaseClasses/ANTPLUS_BaseProfile.h>

class BaseMasterProfile : public BaseProfile {
public:
    BaseMasterProfile(uint16_t deviceNumber, uint8_t transmissionType);
protected:
    /**
     * Used to catch EVENT_TX and continue transmission pattern
     */
    virtual void onChannelEventResponse(ChannelEventResponse& msg);
    /**
     * This function, when called, will transmit the next message in the broadcast pattern
     */
    virtual void transmitNextDataPage() = 0;
};

#endif // ANTPLUS_BASESLAVEPROFILE_h
