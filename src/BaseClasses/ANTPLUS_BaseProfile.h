#ifndef ANTPLUS_BASEPROFILE_h
#define ANTPLUS_BASEPROFILE_h

#include <MainClasses/ANTPLUS_AntPlusRouter.h>
#include "ANT.h"

// Handle circular dependency
class AntPlusRouter;

class BaseProfile {
public:
    BaseProfile(uint8_t channelId);
    virtual void onAcknowledgedData(AcknowledgedData& msg) {}
    virtual void onAdvancedBurstData(AdvancedBurstData& msg) {}
    virtual void onBroadcastData(BroadcastData& msg) {}
    virtual void onBurstTransferData(BurstTransferData& msg) {}
    uint8_t getChannelStatus();
    void setRouter(AntPlusRouter router);
private:
    uint8_t _channelId;
    AntPlusRouter* _router;
};

#endif // ANTPLUS_BASEPROFILE_h