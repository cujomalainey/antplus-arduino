#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

template<class T>
CoreDataPage<T>::CoreDataPage() : T() {

}

template<class T>
uint8_t CoreDataPage<T>::getDataPageNumber() {
    // TODO remove magic number
    // TODO handle shared channels
    return this->getData(0);
}

template class CoreDataPage<BroadcastData>;
template class CoreDataPage<AcknowledgedData>;