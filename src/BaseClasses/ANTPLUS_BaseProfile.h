#ifndef ANTPLUS_BASEPROFILE_h
#define ANTPLUS_BASEPROFILE_h

#include <MainClasses/ANTPLUS_AntPlusRouter.h>
#include "ANT.h"

// Handle circular dependency
class AntPlusRouter;

class BaseProfile {
public:
    BaseProfile(uint16_t deviceNumber, uint8_t transmissionType);
    /**
     * Called on every message incoming before any other predefined callback is called
     */
    void onDataPage(void (*func)(AntRxDataResponse&, uintptr_t), uintptr_t data = 0) { _onDataPage.set(func, data); }
    /**
     * Called if datapage has no callback defined or is an unknown datapage
     * Most profiles require a device to ignore unkown datapages, make sure
     * you are familiar with what to do according to your profile.
     */
    void onOtherDataPage(void (*func)(AntRxDataResponse&, uintptr_t), uintptr_t data = 0) { _onOtherDataPage.set(func, data); }
    /**
     * Callback when an event on this channel occurs
     */
    void onChannelEvent(void (*func)(ChannelEventResponse&, uintptr_t), uintptr_t data = 0) { _onChannelEvent.set(func, data); }
    /**
     * Notifies handler of channel config found after searching
     */
    void onChannelIdResponse(void (*func)(ChannelIdResponse&,uintptr_t), uintptr_t data = 0) { _onChannelIdResponse.set(func, data); }
    /**
     * Set the channel deviceNumber, wildcard for searching is 0
     */
    void setDeviceNumber(uint16_t deviceNumber);
    /**
     * Set the channel transmission type, wildcard for searching is 0
     */
    void setTransmissionType(uint8_t transmissionType);
    /**
     * Returns the last Channel status byte recieved
     */
    uint8_t getChannelStatus();
    /**
     * Get the channel device number, used to identify device after search
     * Wait till channelStatus() has paired with a device before checking
     * this field.
     */
    uint16_t getDeviceNumber();
    /**
     * Get the channel transmision type, used to identify device after search
     * Wait till channelStatus() has paired with a device before checking
     * this field.
     */
    uint8_t getTransmissionType();
    /**
     * Opens radio channel for RX/TX
     */
    virtual void begin() = 0;
    /**
     * Close radio channel and stop transmitting
     */
    virtual void stop() = 0;
    /**
     * Sends a message through the connected router
     */
    void send(AntRequest& msg);

    /******************************************
     *LIBRARY INTERNAL ONLY FUNCTIONS BELOW
     ******************************************/
    virtual void onAcknowledgedData(AcknowledgedData& msg);
    virtual void onAdvancedBurstData(AdvancedBurstData& msg);
    virtual void onBroadcastData(BroadcastData& msg);
    virtual void onBurstTransferData(BurstTransferData& msg);
    virtual void onChannelEventResponse(ChannelEventResponse& msg);
    virtual void onChannelIdResponse(ChannelIdResponse& msg);
    virtual void onChannelStatus(ChannelStatus& msg);
    void setRouter(AntPlusRouter* router);
    void setChannelNumber(uint8_t channel);
    // TODO this should probably have the whole message passed in so
    // profiles like bikelights don't get confused.
    // Alternative is classes requiring 2 channels will register a child
    // profile into the following slots and redirect all traffic back
    void setChannelStatus(uint8_t status);
    void setSearchTimeout(uint8_t counts);
protected:
    void callOnOtherDataPage(AntRxDataResponse& msg);
    void setChannelType(uint8_t channelType);
    void setChannelPeriod(uint16_t channelPeriod);
    void setDeviceType(uint8_t deviceType);
    void pushChannelConfig();
    void openChannel();
    void closeChannel();
    void loop();
private:
    void checkProfileStatus();
    AntPlusRouter* _router;
    Callback<AntRxDataResponse&> _onDataPage;
    Callback<AntRxDataResponse&> _onOtherDataPage;
    Callback<ChannelEventResponse&> _onChannelEvent;
    Callback<ChannelIdResponse&> _onChannelIdResponse;
    uint8_t _channel;
    uint8_t _channelType = 0;
    uint16_t _channelPeriod = 0;
    uint8_t _channelStatus = 0;
    uint16_t _deviceNumber = 0;
    uint8_t _deviceType = 0;
    uint8_t _transmissionType = 0;
    uint8_t _searchTimeout = 0;
};

#endif // ANTPLUS_BASEPROFILE_h