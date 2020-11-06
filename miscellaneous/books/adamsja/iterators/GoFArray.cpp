#ifndef _GOF_ARRAY_CPP_
#define _GOF_ARRAY_CPP_

#include "GoFArrayIterator.h"


template <typename T>
GoFArray<T>::GoFArray(size_t size) : mData(new T[size]), mSize(size) {}

template <typename T>
GoFArray<T>::GoFArray(const GoFArray<T>& src) : mData(new T[src.mSize]), 
						mSize(src.mSize) {
    for (size_t i = 0; i < mSize; ++i)
        mData[i] = src.mData[i];
}

template <typename T>
const GoFArray<T>& GoFArray<T>::operator=(const GoFArray<T>& rhs) {
    if (this != & rhs) {
        delete[] mData;
        mData = new T[rhs.mSize];
        mSize = rhs.mSize;

        for (size_t i = 0; i < mSize; ++i)
            mData[i] = rhs.mData[i];
    }

    return *this;
}

template <typename T>
GoFArray<T>::~GoFArray() {
    delete[] mData;
}

template <typename T>
GangOfFourIterator<T>* GoFArray<T>::createIterator() {
    return new GoFArrayIterator<T>(*this);
}

template <typename T>
T& GoFArray<T>::operator[](size_t index) {
    return mData[index];
}

template <typename T>
const T& GoFArray<T>::operator[](size_t index) const {
    return mData[index];
}

template <typename T>
size_t GoFArray<T>::size() const {
    return mSize;
}

#endif
