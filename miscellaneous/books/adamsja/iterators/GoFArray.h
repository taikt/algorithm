#ifndef _GOF_ARRAY_H_
#define _GOF_ARRAY_H_

#include <cstdlib>  // For size_t

// Forward declaration
template <typename T>
class GangOfFourIterator;

template <typename T>
class GoFArray {

public:

    explicit GoFArray(size_t size);

    GoFArray(const GoFArray<T>& src);

    const GoFArray<T>& operator=(const GoFArray<T>& rhs);

    ~GoFArray();

    GangOfFourIterator<T>* createIterator();

    T& operator[](size_t index);

    const T& operator[](size_t index) const;

    size_t size() const;

 private:
    T* mData;
    size_t mSize;
};

#include "GoFArray.cpp"

#endif
