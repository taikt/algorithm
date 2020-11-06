#ifndef _GOF_ARRAY_ITERATOR_H_
#define _GOF_ARRAY_ITERATOR_H_

#include "GangOfFourIterator.h"

template <typename T>
class GoFArray;

template <typename T>
class GoFArrayIterator : public GangOfFourIterator<T> {

public:

    GoFArrayIterator(GoFArray<T>& array);

    virtual bool hasNext() const;

    virtual T& currentElement();

    virtual const T& currentElement() const;

    virtual void advance();

 private: 

    GoFArray<T>& mArray;
    size_t mIndex;
};

#include "GoFArrayIterator.cpp"

#endif
