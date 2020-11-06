#ifndef _STL_ARRAY_H_
#define _STL_ARRAY_H_

#include <cstdlib>  // For size_t
#include "STLArrayIterator.h"

template <typename T>
class STLArray {

public:

    explicit STLArray(size_t size);

    STLArray(const STLArray<T>& src);

    const STLArray<T>& operator=(const STLArray<T>& rhs);

    ~STLArray();

    ConstSTLArrayIterator<T> begin() const;

    STLArrayIterator<T> begin();

    ConstSTLArrayIterator<T> end() const;

    STLArrayIterator<T> end();

    T& operator[](size_t index);

    const T& operator[](size_t index) const;

    size_t size() const;
 private:
    T* mData;
    size_t mSize;
};

#include "STLArray.cpp"

#endif

