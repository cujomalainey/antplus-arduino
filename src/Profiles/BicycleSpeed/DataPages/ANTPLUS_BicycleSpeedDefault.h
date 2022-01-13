#ifndef ANTPLUS_BICYCLESPEEDDEFAULT_h
#define ANTPLUS_BICYCLESPEEDDEFAULT_h

#include <Profiles/BicycleSpeed/DataPages/ANTPLUS_BicycleSpeedBaseMainDataPage.h>

class BicycleSpeedDefault : public BicycleSpeedBaseMainDataPage {
public:
    explicit BicycleSpeedDefault(AntRxDataResponse& dp);
};

#endif // ANTPLUS_BICYCLESPEEDDEFAULT_h
