#ifndef ANTPLUS_BICYCLESPEEDMOTIONANDSPEED_h
#define ANTPLUS_BICYCLESPEEDMOTIONANDSPEED_h

#include <Profiles/BicycleSpeed/DataPages/Base/ANTPLUS_BicycleSpeedBaseMainDataPage.h>

class BicycleSpeedMotionAndSpeed : public BicycleSpeedBaseMainDataPage {
public:
    BicycleSpeedMotionAndSpeed(AntRxDataResponse& dp);
    uint8_t getFlags();
};

#endif // ANTPLUS_BICYCLESPEEDMOTIONANDSPEED_h
