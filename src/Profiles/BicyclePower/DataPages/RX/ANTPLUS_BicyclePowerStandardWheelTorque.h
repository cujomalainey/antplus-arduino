#ifndef ANTPLUS_BICYCLEPOWERSTANDARDWHEELTORQUE_h
#define ANTPLUS_BICYCLEPOWERSTANDARDWHEELTORQUE_h

#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerBaseMainDataPage.h>
#include <Profiles/BicyclePower/DataPages/Base/ANTPLUS_BicyclePowerBaseStandardWheelTorque.h>

class BicyclePowerStandardWheelTorque : public BicyclePowerBaseMainDataPage, public BicyclePowerBaseStandardWheelTorque<BroadcastData> {
public:
    explicit BicyclePowerStandardWheelTorque(AntRxDataResponse& dp);
};

#endif // ANTPLUS_BICYCLEPOWERSTANDARDWHEELTORQUE_h
