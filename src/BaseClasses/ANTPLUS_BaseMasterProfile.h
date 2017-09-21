#ifndef ANTPLUS_BASEMASTERPROFILE_h
#define ANTPLUS_BASEMASTERPROFILE_h

class BaseMasterProfile : public BaseProfile {
public:
    void transmit() = 0;
    // TODO add callback structure and handler for next datapage
private:
    void transmitNextDataPage() = 0;
};

#endif // ANTPLUS_BASESLAVEPROFILE_h