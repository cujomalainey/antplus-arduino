#ifndef ANTPLUS_LEVDISPLAYDATAMSG_h
#define ANTPLUS_LEVDISPLAYDATAMSG_h

#include <Profiles/Lev/DataPages/ANTPLUS_LevBaseMainDataPage.h>

template<class T>
class LevBaseDisplayData : virtual public CoreDataPage<T> {
public:
    LevBaseDisplayData();
    uint16_t getWheelCircumference();
    uint8_t getCurrentAssistLevel();
    uint8_t getCurrentRegenerativeLevel();
    uint8_t getCurrentRearGear();
    uint8_t getCurrentFrontGear();
    uint8_t getCurrentLightMode();
    bool getDisplayCommandTurnSignalRight();
    bool getDisplayCommandTurnSignalLeft();
    bool getDisplayCommandLightHighBeam();
    bool getDisplayCommandLightOnOff();
    uint16_t getManufacturerID();
};

class LevDisplayData : public LevBaseMainDataPage, public LevBaseDisplayData<BroadcastData> {
public:
    explicit LevDisplayData(AntRxDataResponse& dp);
};

class LevDisplayDataMsg : public LevBaseMainDataPageMsg<AcknowledgedDataMsg>, public LevBaseDisplayData<AcknowledgedDataMsg> {
public:
    LevDisplayDataMsg();
    void setWheelCircumference(uint16_t circumference);
    /**
     * TODO add special handler to set special case for TravelMode not supported/not set
     * requires changing reserved bits
     */
    void setCurrentAssistLevel(uint8_t level);
    void setCurrentRegenerativeLevel(uint8_t level);
    void setCurrentRearGear(uint8_t gear);
    void setCurrentFrontGear(uint8_t gear);
    void setDisplayCommandTurnSignalRight(bool rightSignal);
    void setDisplayCommandTurnSignalLeft(bool leftSignal);
    void setDisplayCommandLightHighBeam(bool highBeam);
    void setDisplayCommandLightOnOff(bool onOff);
    void setManufacturerID(uint16_t id);
};

#endif // ANTPLUS_LEVDISPLAYDATAMSG_h
