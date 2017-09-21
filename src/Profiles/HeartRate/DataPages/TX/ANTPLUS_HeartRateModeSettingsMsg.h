#ifndef ANTPLUS_HEARTRATEMODESETTINGSMSG_h
#define ANTPLUS_HEARTRATEMODESETTINGSMSG_h

#include <CommonDataPages/TX/ANTPLUS_ModeSettingsMsg.h>

class HeartRateModeSettingsMsg : public ModeSettingsMsg {
public:
    HeartRateModeSettingsMsg();
    uint8_t getSportMode();
    void setSportMode(uint8_t mode);
};

#endif // ANTPLUS_HEARTRATEMODESETTINGSMSG_h