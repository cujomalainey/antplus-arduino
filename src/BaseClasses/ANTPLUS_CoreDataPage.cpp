#include <BaseClasses/ANTPLUS_CoreDataPage.h>

#include "ANT.h"

template<class T>
CoreDataPage<T>::CoreDataPage() : T() {

}

template class CoreDataPage<BroadcastData>;
template class CoreDataPage<AcknowledgedData>;