#ifndef _GANG_OF_FOUR_ITERATOR_H_
#define _GANG_OF_FOUR_ITERATOR_H_

template <typename T>
class GangOfFourIterator {
public:

    virtual ~GangOfFourIterator() = 0;

    virtual bool hasNext() const = 0;

    virtual T& currentElement() = 0;

    virtual const T& currentElement() const = 0;

    virtual void advance() = 0;
};

template <typename T>
GangOfFourIterator<T>::~GangOfFourIterator() {
}

#endif
