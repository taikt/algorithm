#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

#include "STLArray.h"

void printArray(const int* array, size_t size) {
  std::cout << "print array: ";
    for (size_t i = 0; i < size; ++i)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}

void printArrayLoopless(const int* array, size_t size) {
  std::cout << "print loopless: ";
    std::copy(array, array + size, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

void print(const int* first, const int* last) {
  std::cout << "print ";
    std::copy(first, last, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

void printInt(const int& i) {
    std::cout << i;
}

bool isOdd(const int& i) {
    return i % 2;
}

int add(const int& a, const int& b) {
    return a + b;
}

int multBy2(const int& i) {
    return i * 2;
}

struct Generator {
    int mCurrent;

    Generator(int num) : mCurrent(num) {}

    int operator()() {
        return mCurrent++;
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const STLArray<T> array) {
    std::copy(array.begin(), array.end(), std::ostream_iterator<T>(std::cout, " "));
    os << std::endl;
    return os;
}

const size_t SIZE = 10;
int data1[] = {1, 2, 3, 4, 5, 6, 7, 10, 10, 10};
int data2[] = {5, 10, 2, 10, 6, 10, 7, 4, 3, 1};

int main() {
    {
        printArray(data1, SIZE);
        printArrayLoopless(data1, SIZE);

        {
            int* array = new int[SIZE];
            std::copy(data1, data1 + SIZE, array);
            print(array, array + SIZE);
            delete[] array;
        }

        std::for_each(data1, data1 + SIZE, printInt);
        std::cout << std::endl;

        std::cout << std::count(data1, data1 + SIZE, 10) << std::endl;

        std::cout << std::count_if(data1, data1 + SIZE, isOdd) << std::endl 
		  << std::endl;


        std::cout << std::boolalpha << std::equal(data1, data1 + SIZE, data2) 
		  << std::endl;
        std::sort(data2, data2 + SIZE);
        print(data1, data1 + SIZE);
        print(data2, data2 + SIZE);
        std::cout << std::boolalpha << std::equal(data1, data1 + SIZE, data2) 
		  << std::endl << std::endl;


        std::transform(data1, data1 + SIZE, data2, multBy2);
        print(data1, data1 + SIZE);
        print(data2, data2 + SIZE);
        std::cout << std::endl;

        std::transform(data1, data1 + SIZE, data2, 
		       std::ostream_iterator<int>(std::cout, " "), add);
        std::cout << std::endl;
        print(data1, data1 + SIZE);
        print(data2, data2 + SIZE);
        std::cout << std::endl;

        std::fill(data1, data1 + SIZE, 0);
        std::generate(data2, data2 + SIZE, Generator(123));
        print(data1, data1 + SIZE);
        print(data2, data2 + SIZE);
        std::cout << std::endl << std::endl;
    }

    return 0;
}
