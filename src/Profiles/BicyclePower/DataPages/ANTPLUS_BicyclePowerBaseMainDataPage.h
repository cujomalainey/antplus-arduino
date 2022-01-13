#ifndef ANTPLUS_BICYCLEPOWERBASEMAINDATAPAGE_h
#define ANTPLUS_BICYCLEPOWERBASEMAINDATAPAGE_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>
#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>

class BicyclePowerBaseMainDataPage : public BaseDataPage<BroadcastData> {
public:
    explicit BicyclePowerBaseMainDataPage(AntRxDataResponse& dp);
    uint8_t getDataPageNumber() override;
    uint8_t getUpdateEventCount();
};

class BicyclePowerBaseMainDataPageMsg : public BaseDataPageMsg<BroadcastDataMsg> {
public:
    explicit BicyclePowerBaseMainDataPageMsg(uint8_t dataPageNumber);
protected:
    uint8_t _buffer[MESSAGE_SIZE] = {0};
};

#endif // ANTPLUS_BICYCLEPOWERPOWERONLYDATAPAGE_h
