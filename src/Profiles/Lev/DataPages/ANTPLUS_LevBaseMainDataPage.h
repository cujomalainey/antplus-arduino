#ifndef ANTPLUS_LEVBASEMAINDATAPAGE_h
#define ANTPLUS_LEVBASEMAINDATAPAGE_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>
#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>

class LevBaseMainDataPage : public BaseDataPage<BroadcastData> {
public:
    explicit LevBaseMainDataPage(AntRxDataResponse& dp);
};

class LevBaseMainDataPageMsg : public BaseDataPageMsg<AcknowledgedDataMsg> {
public:
    explicit LevBaseMainDataPageMsg(uint8_t dataPageNumber);
protected:
    uint8_t _buffer[MESSAGE_SIZE] = {0};
};

#endif // ANTPLUS_LEVBASEMAINDATAPAGE_h
