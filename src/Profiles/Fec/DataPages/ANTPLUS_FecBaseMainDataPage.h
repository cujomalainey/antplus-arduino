#ifndef ANTPLUS_FECBASEMAINDATAPAGE_h
#define ANTPLUS_FECBASEMAINDATAPAGE_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>
#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>

class FecBaseMainDataPage : public BaseDataPage<BroadcastData> {
public:
    explicit FecBaseMainDataPage(AntRxDataResponse& dp);
};

class FecBaseMainDataPageMsg : public BaseDataPageMsg<BroadcastDataMsg> {
public:
    explicit FecBaseMainDataPageMsg(uint8_t dataPageNumber);
protected:
    uint8_t _buffer[MESSAGE_SIZE] = {0};
};

#endif // ANTPLUS_FECBASEMAINDATAPAGE_h
