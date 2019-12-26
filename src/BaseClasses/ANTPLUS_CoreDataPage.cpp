#include <BaseClasses/ANTPLUS_CoreDataPage.h>
#include <ANTPLUS_PrivateDefines.h>

#include "ANT.h"

template<class T>
CoreDataPage<T>::CoreDataPage() : T() {

}

template<class T>
uint8_t CoreDataPage<T>::getDataPageNumber() {
    // TODO handle shared channels
    return this->get8BitValue(ANTPLUS_DEFAULT_DATAPAGE_BYTE);
}

template<class T>
inline int8_t CoreDataPage<T>::getByteStepDirection(uint8_t from, uint8_t to) {
    return from < to ? 1 : -1;
}

template class CoreDataPage<BroadcastData>;
template class CoreDataPage<AcknowledgedData>;
template class CoreDataPage<BroadcastDataMsg>;
template class CoreDataPage<AcknowledgedDataMsg>;
