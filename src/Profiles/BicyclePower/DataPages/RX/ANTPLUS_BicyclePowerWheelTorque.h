#ifndef ANTPLUS_BICYCLEPOWERWHEELTORQUE_h
#define ANTPLUS_BICYCLEPOWERWHEELTORQUE_h

#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerBaseMainDataPage.h>
#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerBaseWheelTorque.h>

class BicyclePowerWheelTorque : public BicyclePowerBaseMainDataPage, public BicyclePowerBaseWheelTorque<BroadcastData> {
public:
    BicyclePowerWheelTorque(AntRxDataResponse& dp);
};

#endif // ANTPLUS_BICYCLEPOWERWHEELTORQUE_h
