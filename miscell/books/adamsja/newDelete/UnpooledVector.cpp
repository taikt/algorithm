#ifndef _UNPOOLED_VECTOR_CPP_
#define _UNPOOLED_VECTOR_CPP_

#include "UnpooledVector.h"
#include <algorithm>
#include <ostream>

/**
 * Constructor. Initializes the vector to the default value for its numeric 
 * type.
 */
template <size_t DIM, typename T>
UnpooledVector<DIM, T>::UnpooledVector() {
    std::fill(data_, data_ + DIM, T());
}

/**
 * ostream output operator. Used for printing the vector.
 */
template <size_t DIM, typename T>
std::ostream& operator<<(std::ostream& os, const UnpooledVector<DIM, T>& v) {
    for (size_t i = 0; i < DIM; ++i)
        os << v.data_[i] << " ";
    return os;
}

#endif
