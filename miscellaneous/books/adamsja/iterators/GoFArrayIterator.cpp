#ifndef _GOF_ARRAY_ITERATOR_CPP_
#define _GOF_ARRAY_ITERATOR_CPP_

#include "GoFArrayIterator.h"


template <typename T>
GoFArrayIterator<T>::GoFArrayIterator(GoFArray<T>& array) : mArray(array), 
							    mIndex(0) {}

template <typename T>
bool GoFArrayIterator<T>::hasNext() const {
    return mIndex < mArray.size();
}

template <typename T>
T& GoFArrayIterator<T>::currentElement() {
    return mArray[mIndex];
}

template <typename T>
const T& GoFArrayIterator<T>::currentElement() const {
    return mArray[mIndex];
}

template <typename T>
void GoFArrayIterator<T>::advance() {
    ++mIndex;
}

#endif
