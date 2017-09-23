#ifndef ANTPLUS_BASEPROFILE_h
#define ANTPLUS_BASEPROFILE_h

#include <MainClasses/ANTPLUS_AntPlusRouter.h>
#include "ANT.h"

// Handle circular dependency
class AntPlusRouter;

class BaseProfile {
public:
    BaseProfile(uint8_t channelId);
    /**
     * Returns the last Channel status byte recieved
     */
    uint8_t getChannelStatus();
    /**
     * Called on every message incoming
     */
    void onDataPage(); // TODO fill in params
    /**
     * Called if datapage recieved is not defined in the profile
     */
    void onUnknownDataPage(); // TODO fill in params
    /**
     * Called if datapage has no callback defined or
     * is a manufacturer defined page
     */
    void onOtherDataPage(); // TODO fill in params
    /**
     * Opens radio channel for RX/TX
     */
    virtual void begin() = 0;
    virtual void stop() = 0;

    /******************************************
     *LIBRARY INTERNAL ONLY FUNCTIONS BELOW
     ******************************************/
    virtual void onAcknowledgedData(AcknowledgedData& msg) {}
    virtual void onAdvancedBurstData(AdvancedBurstData& msg) {}
    virtual void onBroadcastData(BroadcastData& msg) {}
    virtual void onBurstTransferData(BurstTransferData& msg) {}
    void setRouter(AntPlusRouter router);
    void setChannelStatus(uint8_t status);
    void setChannelId(uint16_t channelId);
    void setDeviceType(uint8_t deviceType);
    void setTransmissionType(uint8_t transmissionType);
protected:
    void pushChannelConfig();
    void openChannel();
    void closeChannel();
private:
    AntPlusRouter* _router;
    uint16_t _channelId;
    uint8_t _deviceType;
    uint8_t _transmissionType;
};

#endif // ANTPLUS_BASEPROFILE_h