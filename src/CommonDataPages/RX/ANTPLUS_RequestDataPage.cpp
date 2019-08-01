#include <CommonDataPages/RX/ANTPLUS_RequestDataPage.h>

RequestDataPage::RequestDataPage(AntRxDataResponse& dp) : BaseDataPage<AcknowledgedData>(dp), BaseRequestDataPage<AcknowledgedData>() {
}
