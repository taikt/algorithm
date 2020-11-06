/**
 * A driver file used to demonstrate the efficiency boost due to pooling.
 *
 * Author: Krzysztof Zienkiewicz.
 */
#include <iostream>
#include <ctime>

#include <memory>

#include "PooledVector.h"
#include "UnpooledVector.h"

// The size of the vectors we'll be using.
const size_t VECTOR_SIZE = 3;
// A global variable used to time the algorithms.
clock_t start_time;

/**
 * Starts the timer.
 */
void start_timer() {
    start_time = clock();
}

/**
 * Stops the timer and returns the time in milliseconds since the last call to
 * start_timer().
 */
float stop_timer() {
    clock_t diff = clock() - start_time;
    return (diff * 1000.0f / CLOCKS_PER_SEC);
}

int main() {
   /*
    We dynamically allocate 100 vectors and put their pointers into an array of
    auto_ptr's so that we don't have explicitely delete them. We do this 100,000
    times so that the time difference is more visible.
    */
    start_timer();

    PooledVector<VECTOR_SIZE>::create_pool();
    for (int i = 0; i < 100000; ++i) {
        std::auto_ptr<PooledVector<VECTOR_SIZE> >* block = 
                        new std::auto_ptr<PooledVector<VECTOR_SIZE> >[100];
                        
        for (int j = 0; j < 100; ++j)
            block[j].reset(new PooledVector<VECTOR_SIZE>);
        delete[] block;
    }
    PooledVector<VECTOR_SIZE>::destroy_pool();

    std::cerr << "Time: " << stop_timer() << " ms.\n";
    
    start_timer();

    for (int i = 0; i < 100000; ++i) {
        std::auto_ptr<UnpooledVector<VECTOR_SIZE> >* block = 
                        new std::auto_ptr<UnpooledVector<VECTOR_SIZE> >[100];
                        
        for (int j = 0; j < 100; ++j)
            block[j].reset(new UnpooledVector<VECTOR_SIZE>);
        delete[] block;
    }

    std::cerr << "Time: " << stop_timer() << " ms.\n";
}
