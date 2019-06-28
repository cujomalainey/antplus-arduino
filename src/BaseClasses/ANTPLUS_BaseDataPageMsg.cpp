#include <BaseClasses/ANTPLUS_BaseDataPageMsg.h>

#include "ANT.h"

template<class T>
BaseDataPageMsg<T>::BaseDataPageMsg() : CoreDataPage<T>() {
}

template class BaseDataPageMsg<BroadcastDataMsg>;
template class BaseDataPageMsg<AcknowledgedDataMsg>;
