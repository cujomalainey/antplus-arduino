#ifndef ANTPLUS_BICYCLESPEEDMOTIONANDSPEED_h
#define ANTPLUS_BICYCLESPEEDMOTIONANDSPEED_h

#include <Profiles/BicycleSpeed/DataPages/Base/ANTPLUS_BicycleSpeedBaseMainDataPage.h>
#include <Profiles/BicycleSpeed/DataPages/Base/ANTPLUS_BicycleSpeedBaseMotionAndSpeed.h>

class BicycleSpeedMotionAndSpeed : public BicycleSpeedBaseMainDataPage, public BicycleSpeedBaseMotionAndSpeed<BroadcastData> {
public:
    explicit BicycleSpeedMotionAndSpeed(AntRxDataResponse& dp);
};

#endif // ANTPLUS_BICYCLESPEEDMOTIONANDSPEED_h
