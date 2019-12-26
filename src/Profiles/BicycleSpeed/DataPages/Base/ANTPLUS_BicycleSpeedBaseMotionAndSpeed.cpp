#include <Profiles/BicycleSpeed/DataPages/Base/ANTPLUS_BicycleSpeedBaseMotionAndSpeed.h>
#include <Profiles/BicycleSpeed/ANTPLUS_BicycleSpeedPrivateDefines.h>

template<class T>
BicycleSpeedBaseMotionAndSpeed<T>::BicycleSpeedBaseMotionAndSpeed() : CoreDataPage<T>() {
}

template<class T>
uint8_t BicycleSpeedBaseMotionAndSpeed<T>::getFlags() {
    return this->get8BitValue(
            ANTPLUS_BICYCLESPEED_DATAPAGE_MOTIONANDSPEED_FLAGS_BYTE);
}

template class BicycleSpeedBaseMotionAndSpeed<BroadcastData>;
template class BicycleSpeedBaseMotionAndSpeed<BroadcastDataMsg>;
