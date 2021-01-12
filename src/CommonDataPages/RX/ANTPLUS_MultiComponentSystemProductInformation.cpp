#include <CommonDataPages/RX/ANTPLUS_MultiComponentSystemProductInformation.h>

MultiComponentSystemProductInformation::MultiComponentSystemProductInformation(AntRxDataResponse& dp) : BaseDataPage<BroadcastData>(dp), BaseMultiComponentSystemProductInformation<BroadcastData>() {
}
