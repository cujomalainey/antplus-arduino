#ifndef ANTPLUS_HEARTRATEMODESETTINGS_h
#define ANTPLUS_HEARTRATEMODESETTINGS_h

#include <CommonDataPages/RX/ANTPLUS_ModeSettings.h>

class HeartRateModeSettings : public ModeSettings {
public:
    HeartRateModeSettings();
    uint8_t getSportMode();
};

#endif // ANTPLUS_HEARTRATEMODESETTINGS_h