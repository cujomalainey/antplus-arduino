#ifndef ANTPLUS_SHIFTINGBASEMAINDATAPAGE_h
#define ANTPLUS_SHIFTINGBASEMAINDATAPAGE_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>
#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>

class ShiftingBaseMainDataPage : public BaseDataPage<BroadcastData> {
public:
    explicit ShiftingBaseMainDataPage(AntRxDataResponse& dp);
};

class ShiftingBaseMainDataPageMsg : public BaseDataPageMsg<BroadcastDataMsg> {
public:
    explicit ShiftingBaseMainDataPageMsg(uint8_t dataPageNumber);
protected:
    uint8_t _buffer[MESSAGE_SIZE] = {0};
};

#endif // ANTPLUS_SHIFTINGBASEMAINDATAPAGE_h
