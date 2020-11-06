#ifndef _POOLED_VECTOR_CPP_
#define _POOLED_VECTOR_CPP_

#include "PooledVector.h"

#include <algorithm>
#include <ostream>

/**
 * Constructor. Initializes the vector to the default value for its numeric 
 * type.
 */
template <size_t DIM, typename T>
PooledVector<DIM, T>::PooledVector() {
    std::fill(data_, data_ + DIM, T());
}

/**
 * Overloaded new operator. If memory exists in the pool, it will return it.
 * Otherwise, global new will be called to allocate the necessary space.
 */
template <size_t DIM, typename T>
static inline void* PooledVector<DIM, T>::operator new(size_t bytes) {
    // If the "stack" is not empty
    if (pool_top_ > 0) {
        // Pop a memory address and return it
        void* ptr = memory_pool_[--pool_top_];
        return ptr;
    }
    
    // Else, delegate to global new.
    return ::operator new(sizeof(PooledVector<DIM, T>));
}

/**
 * Overloaded delete operator. Puts the provided pointer back in the pool.
 * Correctly handles the null pointer.
 */
template <size_t DIM, typename T>
static inline void PooledVector<DIM, T>::operator delete(void* ptr) {
    // Note: no range-checking. This could lead to an overflow
    // It should always be safe to call delete 0. So ignore if we have a null.
    if (ptr != 0)
        // Push the provided memory into our pool.
        memory_pool_[pool_top_++] = static_cast<PooledVector<DIM, T>*>(ptr);
}

/**
 * A static method that pre-allocates memory for PooledVector objects and puts 
 * them in the pool.
 */
template <size_t DIM, typename T>
void PooledVector<DIM, T>::create_pool() {
    // Fill the stack to capacity with pointers returned by global new.
    for (size_t i = 0; i < 100; ++i)
        memory_pool_[pool_top_++] = static_cast<PooledVector<DIM, T>*>(
                                  ::operator new(sizeof(PooledVector<DIM, T>)));
}

/**
 * A static method that releases all the memory held by the pool. This must be 
 * called to avoid memory leaks.
 */
template <size_t DIM, typename T>
void PooledVector<DIM, T>::destroy_pool() {
     // While the stack is not empty
   while (pool_top_ > 0) {
        // Pop the pointer and release its memory via global new.
        ::operator delete(memory_pool_[--pool_top_]);
        memory_pool_[pool_top_] = 0;
    }
}

/*
Static fields do not belong to objects but they must still be initialized. This
is where it's done.
*/
template <size_t DIM, typename T>
PooledVector<DIM, T>* PooledVector<DIM, T>::memory_pool_[];

template <size_t DIM, typename T>
int PooledVector<DIM, T>::pool_top_(0);

/**
 * The backing storage for the vector. Statically allocated.
 */
template <size_t DIM, typename T>
std::ostream& operator<<(std::ostream& os, const PooledVector<DIM, T>& v) {
    for (size_t i = 0; i < DIM; ++i)
        os << v.data_[i] << " ";
    return os;
}

#endif
