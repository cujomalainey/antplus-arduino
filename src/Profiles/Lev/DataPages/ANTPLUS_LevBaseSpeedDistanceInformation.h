#ifndef ANTPLUS_LEVBASESPEEDDISTANCEINFORMATION_h
#define ANTPLUS_LEVBASESPEEDDISTANCEINFORMATION_h

#include <Profiles/Lev/DataPages/ANTPLUS_LevBaseMainDataPage.h>

template<class T>
class LevCoreSpeedDistanceInformation : virtual public CoreDataPage<T> {
public:
    LevCoreSpeedDistanceInformation();
    uint32_t getOdometer(); // in km
    uint16_t getLevSpeed(); // in 1/10 km/h
};

class LevBaseSpeedDistanceInformation : public LevBaseMainDataPage, public LevCoreSpeedDistanceInformation<BroadcastData> {
public:
    explicit LevBaseSpeedDistanceInformation(AntRxDataResponse& dp);
};

class LevBaseSpeedDistanceInformationMsg : public LevBaseMainDataPageMsg<BroadcastDataMsg>, public LevCoreSpeedDistanceInformation<BroadcastDataMsg> {
public:
    explicit LevBaseSpeedDistanceInformationMsg(uint8_t dataPageNumber);
    void setOdometer(uint32_t odometer); // in km
    void setLevSpeed(uint16_t speed); // in 1/10 km/h
};

#endif // ANTPLUS_LEVBASESPEEDDISTANCEINFORMATION_h
