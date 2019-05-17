#include <BaseClasses/ANTPLUS_CoreDataPage.h>
#include <ANTPLUS_PrivateDefines.h>

#include "ANT.h"

template<class T>
CoreDataPage<T>::CoreDataPage() : T() {

}

template<class T>
uint8_t CoreDataPage<T>::getDataPageNumber() {
    // TODO handle shared channels
    return this->getData(ANTPLUS_DEFAULT_DATAPAGE_BYTE);
}

template class CoreDataPage<BroadcastData>;
template class CoreDataPage<AcknowledgedData>;
template class CoreDataPage<BroadcastDataMsg>;
template class CoreDataPage<AcknowledgedDataMsg>;
