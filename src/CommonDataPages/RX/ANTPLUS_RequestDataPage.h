#ifndef ANTPLUS_REQUESTDATAPAGE_h
#define ANTPLUS_REQUESTDATAPAGE_h

#include <BaseClasses/ANTPLUS_BaseDataPage.h>

#include "ANT.h"

// Common Page 70

class RequestDataPage : public BaseDataPage<AcknowledgedData> {
    RequestDataPage(AcknowledgedData& dp);
    // TODO
};

#endif // ANTPLUS_REQUESTDATAPAGE_h