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
    /******************************************
     *LIBRARY INTERNAL ONLY FUNCTIONS BELOW
     ******************************************/
    virtual void onAcknowledgedData(AcknowledgedData& msg) {}
    virtual void onAdvancedBurstData(AdvancedBurstData& msg) {}
    virtual void onBroadcastData(BroadcastData& msg) {}
    virtual void onBurstTransferData(BurstTransferData& msg) {}
    void setChannelStatus(uint8_t status);
    void setRouter(AntPlusRouter router);
private:
    uint8_t _channelId;
    AntPlusRouter* _router;
};

#endif // ANTPLUS_BASEPROFILE_h