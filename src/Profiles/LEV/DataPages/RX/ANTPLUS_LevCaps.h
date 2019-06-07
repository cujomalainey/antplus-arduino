#ifndef ANTPLUS_LEVCAPS_h
#define ANTPLUS_LEVCAPS_h

#include <Profiles/Lev/DataPages/Base/ANTPLUS_LevBaseMainDataPage.h>

class LevCaps : public LevBaseMainDataPage {
public:
    LevCaps(AntRxDataResponse& dp);
    uint8_t getTravelModesSupported();
    uint16_t getWheelCircumference();
};

#endif // ANTPLUS_LEVCAPS_h
