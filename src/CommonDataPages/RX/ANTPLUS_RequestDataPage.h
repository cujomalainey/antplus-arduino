#ifndef ANTPLUS_REQUESTDATAPAGE_h
#define ANTPLUS_REQUESTDATAPAGE_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>
#include <CommonDataPages/Base/ANTPLUS_BaseRequestDataPage.h>

#include "ANT.h"

// Common Page 70

class RequestDataPage : public BaseDataPage<AcknowledgedData>, public BaseRequestDataPage<AcknowledgedData> {
public:
    RequestDataPage(AntRxDataResponse& dp);
};

#endif // ANTPLUS_REQUESTDATAPAGE_h
