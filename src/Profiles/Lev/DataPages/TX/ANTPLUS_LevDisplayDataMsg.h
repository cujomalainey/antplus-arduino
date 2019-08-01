#ifndef ANTPLUS_LEVDISPLAYDATAMSG_h
#define ANTPLUS_LEVDISPLAYDATAMSG_h

#include <Profiles/Lev/DataPages/Base/ANTPLUS_LevBaseMainDataPageMsg.h>

class LevDisplayDataMsg : public LevBaseMainDataPageMsg {
public:
    LevDisplayDataMsg();
    uint16_t getWheelCircumference();
    uint8_t getCurrentAssistLevel();
    uint8_t getCurrentRegenerativeLevel();
    uint8_t getCurrentRearGear();
    uint8_t getCurrentFrontGear();
    uint8_t getCurrentLightMode();
    uint16_t getManufacturerID();
    void setWheelCircumference(uint16_t circumference);
    /**
     * TODO add special handler to set special case for TravelMode not supported/not set
     * requires changing reserved bits
     */
    void setCurrentAssistLevel(uint8_t level);
    void setCurrentRegenerativeLevel(uint8_t level);
    void setCurrentRearGear(uint8_t gear);
    void setCurrentFrontGear(uint8_t gear);
    void setCurrentLightMode(uint8_t state);
    void setManufacturerID(uint16_t id);
};

#endif // ANTPLUS_LEVDISPLAYDATAMSG_h
