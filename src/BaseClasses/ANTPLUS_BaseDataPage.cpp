#include <BaseClasses/ANTPLUS_BaseDataPage.h>

#include "ANT.h"

template<class T>
BaseDataPage<T>::BaseDataPage(AntRxDataResponse& msg) : CoreDataPage<T>() {
    this->setFrameData(msg.getFrameData());
    this->setMsgId(msg.getMsgId());
    this->setAvailable(msg.isAvailable());
    this->setChecksum(msg.getChecksum());
    this->setErrorCode(msg.getErrorCode());
    this->setLength(msg.getLength());
}

template class BaseDataPage<BroadcastData>;
template class BaseDataPage<AcknowledgedData>;