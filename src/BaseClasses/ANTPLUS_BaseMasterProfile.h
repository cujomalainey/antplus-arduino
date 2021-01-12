#ifndef ANTPLUS_BASEMASTERPROFILE_h
#define ANTPLUS_BASEMASTERPROFILE_h

#include <BaseClasses/ANTPLUS_BaseProfile.h>
#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>

class BaseMasterProfile : public BaseProfile {
public:
    BaseMasterProfile(uint16_t deviceNumber, uint8_t transmissionType);
    /**
     * start profile transmission sequence
     */
    virtual void begin() override;
protected:
    /**
     * Used to catch EVENT_TX and continue transmission pattern
     * Also handles EVENT_TRANSFER_TX_COMPLETED for acknowledgement
     */
    virtual void onChannelEventResponse(ChannelEventResponse& msg) override;
    /**
     * This function, when called, will transmit the next message in the broadcast pattern
     */
    virtual void transmitNextDataPage() = 0;
    /**
     * Checks for RequestDataPage messages and handles them accordingly
     */
    virtual void onAcknowledgedData(AcknowledgedData& msg) override;
    /**
     * Checks with subclass to see if request is valid
     */
    virtual bool isDataPageValid(uint8_t dataPage) = 0;
    /**
     * returns true if pattern is currently interrupted by a request
     */
    bool isRequestedPagePending();
    /**
     * Returns the page number of the pending datapage
     */
    uint8_t getRequestedPage();
    /**
     * returns true if the request is meant to be sent as a acknowledged message
     */
    bool isRequestedPageAcknowledged();
    /**
     * Allows a profile to further validate datapage requests and invludate at a later
     * time if deemed appropriate. An example is the descriptor byte fields.
     */
    void invalidateDataPageRequest();
    /**
     * Some profiles are forbidden from replying with ACK messages, this allows the profile
     * to disable automatic request conversions;
     */
    void setAckMessageUsage(bool on);
    /**
     * Handles ack msg conversions for requests, all transmissions that are part of the broadcast pattern should be through this.
     */
    void transmitMsg(BaseDataPageMsg<BroadcastDataMsg> &msg);
    void transmitMsg(BaseDataPageMsg<AcknowledgedDataMsg> &msg);
private:
    void handleRequestDataPage(AcknowledgedData& msg);
    uint8_t _requestedPage = 0;
    uint8_t _requestedCount = 0;
    bool _ackMessagesAllowed = true;
    bool _isRequestAcknowledged = false;
    bool _requestAcked = true;
};

#endif // ANTPLUS_BASESLAVEPROFILE_h
