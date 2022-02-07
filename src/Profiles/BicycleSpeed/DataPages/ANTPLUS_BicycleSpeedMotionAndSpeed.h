#ifndef ANTPLUS_BICYCLESPEEDMOTIONANDSPEED_h
#define ANTPLUS_BICYCLESPEEDMOTIONANDSPEED_h

#include <Profiles/BicycleSpeed/DataPages/ANTPLUS_BicycleSpeedBaseMainDataPage.h>

template<class T>
class BicycleSpeedBaseMotionAndSpeed : virtual public CoreDataPage<T> {
public:
    BicycleSpeedBaseMotionAndSpeed();
    uint8_t getFlags();
};

class BicycleSpeedMotionAndSpeed : public BicycleSpeedBaseMainDataPage, public BicycleSpeedBaseMotionAndSpeed<BroadcastData> {
public:
    explicit BicycleSpeedMotionAndSpeed(AntRxDataResponse& dp);
};

#endif // ANTPLUS_BICYCLESPEEDMOTIONANDSPEED_h
