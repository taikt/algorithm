#ifndef _STL_ARRAY_CPP_
#define _STL_ARRAY_CPP_

#include <cstdlib>  // For size_t
#include "STLArray.h"
#include <algorithm>

template <typename T>
STLArray<T>::STLArray(size_t size) : mData(new T[size]), mSize(size) {}

template <typename T>
STLArray<T>::STLArray(const STLArray<T>& src) : mData(new T[src.mSize]), 
						mSize(src.mSize) {
    std::copy(src.begin(), src.end(), begin());
}

template <typename T>
const STLArray<T>& STLArray<T>::operator=(const STLArray<T>& rhs) {
    if (this != &rhs) {
        STLArray<T> copy(rhs);
        std::swap(mData, copy.mData);
        std::swap(mSize, copy.mSize);
    }

    return *this;
}

template <typename T>
STLArray<T>::~STLArray() {
    delete[] mData;
}

template <typename T>
ConstSTLArrayIterator<T> STLArray<T>::begin() const {
    return ConstSTLArrayIterator<T>(mData);
}

template <typename T>
STLArrayIterator<T> STLArray<T>::begin() {
    return STLArrayIterator<T>(mData);
}

template <typename T>
ConstSTLArrayIterator<T> STLArray<T>::end() const {
    return ConstSTLArrayIterator<T>(mData + mSize);
}

template <typename T>
STLArrayIterator<T> STLArray<T>::end() {
    return STLArrayIterator<T>(mData + mSize);
}

template <typename T>
T& STLArray<T>::operator[](size_t index) {
    return mData[index];
}

template <typename T>
const T& STLArray<T>::operator[](size_t index) const {
    return mData[index];
}

template <typename T>
size_t STLArray<T>::size() const {
    return mSize;
}

#endif
