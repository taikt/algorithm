#include <iostream>
#include <memory>       // for std::auto_ptr

#include "GoFArray.h"
#include "GangOfFourIterator.h"

const size_t SIZE = 10;
const int DATA[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void reverseArray(GoFArray<int>& array) {
    for (size_t i = 0; i < SIZE; ++i)
        array[i] = DATA[SIZE - i - 1];
}

template <typename T>
void printArray(const GoFArray<T>& array) {
    std::cout << "print array : ";
    for (size_t i = 0; i < array.size(); ++i)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

template <typename T>
void printArrayViaIteratorUnsafe(GoFArray<T>& array) {
    std::cout << "print unsafe iter : ";
    GangOfFourIterator<T>* iterPtr = array.createIterator();
    while (iterPtr->hasNext()) {
        std::cout << iterPtr->currentElement() << " ";
        iterPtr->advance();
    }

    std::cout << std::endl;
}

template <typename T>
void printArrayViaIteratorSafe(GoFArray<T>& array) {
    std::cout << "print safe iter :";
    std::unique_ptr<GangOfFourIterator<T> > iterPtr(array.createIterator());

    while (iterPtr->hasNext()) {
        std::cout << iterPtr->currentElement() << " ";
        iterPtr->advance();
    }

    std::cout << std::endl;
}

int main() {

    GoFArray<int> array(SIZE);
    for (size_t i = 0; i < SIZE; ++i)
        array[i] = DATA[i];

    // Why do we not have to say printArray<int>(array) ?

    printArray(array);
    printArrayViaIteratorUnsafe(array);
    printArrayViaIteratorSafe(array);

    std::cout << std::endl;

    reverseArray(array);
    printArray(array);
    printArrayViaIteratorUnsafe(array);
    printArrayViaIteratorSafe(array);

    return 0;
}
