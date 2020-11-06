#ifndef _POOLED_VECTOR_H_
#define _POOLED_VECTOR_H_
/**
 * A class stub for a simply mathematical vector. This class is parameterized by
 * the dimension of the vector as well as the numeric type the vector should
 * store. A simple pooling mechanism is used to optimize memory allocation for
 * this class.
 *
 * Disclaimer: This implementation of memory pooling is by no means safe. It is
 *             meant to simply demonstrate that the concept is possible and to
 *             provide code snippets that achieve the performance boost.
 *
 * Author: Krzysztof Zienkiewicz
 */

template <size_t DIM, typename T = double>
class PooledVector {
public:
    /**
     * Constructor. Initializes the vector to the default value for its numeric
     * type.
     */
    PooledVector();

   /**
     * Overloaded new operator. If memory exists in the pool, it will return it.
     * Otherwise, global new will be called to allocate the necessary space.
     */
    static inline void* operator new(size_t bytes);
    
    /**
     * Overloaded delete operator. Puts the provided pointer back in the pool.
     * Correctly handles the null pointer.
     */
    static inline void operator delete(void* ptr);
    
    /**
     * A static method that pre-allocates memory for PooledVector objects and
     * puts them in the pool.
     */
    static void create_pool();

    /**
     * A static method that releases all the memory held by the pool. This
     * must be called to avoid memory leaks.
     */
    static void destroy_pool();

   /**
     * ostream output operator. Used for printing the vector.
     */
    template <size_t D, typename U>
    friend std::ostream& operator<<(std::ostream&, const PooledVector<D, U>&);

private:
    /**
     * The backing storage for the vector. Statically allocated.
     */
    T data_[DIM];
    /**
     * An array of pointers to memory to be used for PooledVectors. Together 
     * with pool_top_, this will be used as a primitive stack with push and pop
     * functionality.
     */
    static PooledVector<DIM, T>* memory_pool_[100];
    static int pool_top_;
};

#include "PooledVector.cpp"

#endif
