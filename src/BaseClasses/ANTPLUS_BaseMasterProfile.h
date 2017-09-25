#ifndef ANTPLUS_BASEMASTERPROFILE_h
#define ANTPLUS_BASEMASTERPROFILE_h

class BaseMasterProfile : public BaseProfile {
public:
    // TODO add callback structure and handler for next datapage
protected:
    /**
     * This function, when called, will transmit the next message in the broadcast pattern
     */
    virtual void transmitNextDataPage() = 0;
};

#endif // ANTPLUS_BASESLAVEPROFILE_h