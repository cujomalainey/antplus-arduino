#ifndef ANTPLUS_LEVSPEEDDISTANCEINFORMATION_h
#define ANTPLUS_LEVSPEEDDISTANCEINFORMATION_h

#include <Profiles/Lev/DataPages/ANTPLUS_LevBaseSpeedDistanceInformation.h>

template<class T>
class LevInternalSpeedDistanceInformation : virtual public CoreDataPage<T> {
public:
    LevInternalSpeedDistanceInformation();
    uint16_t getRemainingRange(); // in km
};

class LevSpeedDistanceInformation : public LevBaseSpeedDistanceInformation, public LevInternalSpeedDistanceInformation<BroadcastData> {
public:
    explicit LevSpeedDistanceInformation(AntRxDataResponse& dp);
};

class LevSpeedDistanceInformationMsg : public LevBaseSpeedDistanceInformationMsg, public LevInternalSpeedDistanceInformation<BroadcastDataMsg> {
public:
    LevSpeedDistanceInformationMsg();
    void setRemainingRange(uint16_t remainingRange); // in km
};

#endif // ANTPLUS_LEVSPEEDDISTANCEINFORMATION_h
