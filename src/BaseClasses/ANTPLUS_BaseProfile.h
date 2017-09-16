#ifndef ANTPLUS_BASEPROFILE_h
#define ANTPLUS_BASEPROFILE_h

#include "ANT.h"

class BaseProfile {
    virtual void onAcknowledgedData(AcknowledgedData& msg);
    virtual void onAdvancedBurstData(AdvancedBurstData& msg);
    virtual void onBroadcastData(BroadcastData& msg);
    virtual void onBurstTransferData(BurstTransferData& msg);
}

#endif // ANTPLUS_BASEPROFILE_h