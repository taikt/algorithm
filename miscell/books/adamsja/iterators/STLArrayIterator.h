#ifndef _STL_ARRAY_ITERATOR_H_
#define _STL_ARRAY_ITERATOR_H_

#include <iterator>

// Forward declaration
template <typename T>
class STLArray;

template <typename T>
class STLArrayIterator : public std::iterator<std::forward_iterator_tag, T> {

    friend class STLArray<T>;

public:

    STLArrayIterator<T>& operator++() {
        ++mPtr;
        return *this;
    }

    STLArrayIterator<T> operator++(int) {
        STLArrayIterator<T> temp(*this);
        ++*this;
        return temp;
    }

    T& operator*() {
        return *mPtr;
    }

    const T& operator*() const {
        return *mPtr;
    }

    bool operator==(const STLArrayIterator<T>& rhs) const {
        return mPtr == rhs.mPtr;
    }

    bool operator!=(const STLArrayIterator<T>& rhs) const {
        return !(*this == rhs);
    }
 private:

    T* mPtr;
    STLArrayIterator(T* ptr) : mPtr(ptr) {}
};

template <typename T>
class ConstSTLArrayIterator : public std::iterator<std::forward_iterator_tag, T> {

    friend class STLArray<T>;

public:

    ConstSTLArrayIterator<T>& operator++() {
        ++mPtr;
        return *this;
    }

    ConstSTLArrayIterator<T> operator++(int) {
        STLArrayIterator<T> temp(*this);
        ++*this;
        return temp;
    }

    const T& operator*() const {
        return *mPtr;
    }

    bool operator==(const ConstSTLArrayIterator<T>& rhs) const {
        return mPtr == rhs.mPtr;
    }

    bool operator!=(const ConstSTLArrayIterator<T>& rhs) const {
        return !(*this == rhs);
    }
 private:

    T* mPtr;
    ConstSTLArrayIterator(T* ptr) : mPtr(ptr) {}

};

#endif
