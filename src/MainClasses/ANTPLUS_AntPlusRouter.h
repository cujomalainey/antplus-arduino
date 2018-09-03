#ifndef ANTPLUS_ANTPLUSROUTER_h
#define ANTPLUS_ANTPLUSROUTER_h

#include <ANTPLUS_Defines.h>
#include <BaseClasses/ANTPLUS_BaseProfile.h>

#include "ANT.h"

// Handle circular dependency
class BaseProfile;

class AntPlusRouter {
public:
    AntPlusRouter();
    AntPlusRouter(BaseAntWithCallbacks* driver);
    AntPlusRouter(BaseAntWithCallbacks* driver, const uint8_t* key);
    /**
     * Give the router a driver to use (Ant, NativeAnt, SpiAnt)
     */
    uint8_t setDriver(BaseAntWithCallbacks* driver);
    /**
     * Give the router the ANT+ network key
     * HINT: you get this number from http://www.thisisant.com/developer/ant-plus/ant-plus-basics/network-keys/
     * DO NOT STORE THIS KEY PUBLICLY
     */
    void setAntPlusNetworkKey(const uint8_t* key);
    /**
     * Associates a profile with a channel
     */
    void setProfile(uint8_t channel, BaseProfile* profile);
    void send(AntRequest& msg);
    /**
     * Returns the maximum number of channels the radio
     * connected can support
     */
    uint8_t getMaxChannels();
    /**
     * Process any incoming messages and forward them
     * to the registered callbacks
     */
    void loop();
    /**
     * Reset the whole system back to its defaults
     * This does not remove callbacks or the driver
     * but does reset the driver and the radio.
     */
    void reset();
    /**
     * Stops all profiles and resets the radio
     */
    uint8_t resetRadio(uint8_t waitForStartup);
    /******************************************
     *LIBRARY INTERNAL ONLY FUNCTIONS BELOW
     ******************************************/
    void onPacketError(uint8_t error);
    void onAcknowledgedData(AcknowledgedData& msg);
    void onAdvancedBurstData(AdvancedBurstData& msg);
    void onBroadcastData(BroadcastData& msg);
    void onBurstTransferData(BurstTransferData& msg);
    void onAdvancedBurstCapabilitiesConfiguration(AdvancedBurstCapabilitiesConfiguration& msg);
    void onAntVersion(AntVersion& msg);
    void onCapabilities(Capabilities& msg);
    void onChannelEventResponse(ChannelEventResponse& msg);
    void onChannelIdResponse(ChannelIdResponse& msg);
    void onChannelStatus(ChannelStatus& msg);
    void onEncryptionModeParameters(EncryptionModeParameters& msg);
    void onEventFilter(EventFilter& msg);
    void onSelectiveDataUpdateMaskSetting(SelectiveDataUpdateMaskSetting& msg);
    void onStartUpMessage(StartUpMessage& msg);
private:
    void pushNetworkKey();
    // Driver callbacks

    BaseAntWithCallbacks* _ant = NULL;
    BaseProfile* _profiles[ANTPLUS_MAX_CHANNELS_POSSIBLE]; // Might be less, need to check on startup
    uint8_t _maxChannels = 0;
    const uint8_t* _networkKey = NULL;
    uint8_t _radioStarted = ANTPLUS_DRIVER_STATE_UNKNOWN;
};

#endif // ANTPLUS_ANTPLUSROUTER_h
