#ifndef ANTPLUS_BASEMASTERPROFILE_h
#define ANTPLUS_BASEMASTERPROFILE_h

class BaseMasterProfile : public BaseProfile {
public:
    /**
     * Open channel and begin transmission pattern
     */
    void transmit() = 0;
    // TODO add callback structure and handler for next datapage
private:
    /**
     * This function, when called, will transmit the next message in the broadcast pattern
     */
    void transmitNextDataPage() = 0;
};

#endif // ANTPLUS_BASESLAVEPROFILE_h