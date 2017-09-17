#ifndef ANTPLUS_BASESLAVEPROFILE_h
#define ANTPLUS_BASESLAVEPROFILE_h

#include <BaseClasses/ANTPLUS_BaseProfile.h>

class BaseSlaveProfile : public BaseProfile {
public:
    BaseSlaveProfile(uint8_t channelId);
    void connect();
};

#endif // ANTPLUS_BASESLAVEPROFILE_h