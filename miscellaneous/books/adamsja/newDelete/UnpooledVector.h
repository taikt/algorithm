#ifndef _UNPOOLED_VECTOR_H_
#define _UNPOOLED_VECTOR_H_

#include <ostream>

/**
 * A class stub for a simply mathematical vector. This class is parameterized by
 * the dimension of the vector as well as the numeric type the vector should
 * store. No pooling mechanism is used in this implementation.
 *
 * Author: Krzysztof Zienkiewicz
 */

template <size_t DIM, typename T = double>
class UnpooledVector {
public:
    /**
     * Constructor. Initializes the vector to the default value for its numeric
     * type.
     */
    UnpooledVector();

    /**
     * ostream output operator. Used for printing the vector.
     */
    template <size_t D, typename U>
    friend std::ostream& operator<<(std::ostream&, const UnpooledVector<D, U>&);

private:
    /**
     * The backing storage for the vector. Statically allocated.
     */
    T data_[DIM];
};

#include "UnpooledVector.cpp"

#endif
