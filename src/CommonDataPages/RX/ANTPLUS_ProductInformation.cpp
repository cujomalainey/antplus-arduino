#include <CommonDataPages/RX/ANTPLUS_ProductInformation.h>

ProductInformation::ProductInformation(AntRxDataResponse& dp) : BaseDataPage<BroadcastData>(dp), BaseProductInformation<BroadcastData>() {
}
