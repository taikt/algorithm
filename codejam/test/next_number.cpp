#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "include/catch.hpp"
uint32_t getNext(uint32_t positiveInteger) {
    uint32_t oneIndex = 0;   // index of the rightmost 1
    uint32_t zeroIndex = 0;  // index of the rightmost 0 that has 1s to the right of it

    if (positiveInteger == 0 || positiveInteger == UINT32_MAX) return static_cast<uint32_t>(-1);

    // find rightmost (i.e. least significant) "1" in bit sequence
    uint32_t positiveIntegerCopy = positiveInteger;
    while (positiveIntegerCopy != 0 && (positiveIntegerCopy & 1) != 1) {
        oneIndex ++;
        positiveIntegerCopy >>= 1;
    }

    // find rightmost non-trailing "0" in bit sequence that is more significant than "1" position
    positiveIntegerCopy = positiveInteger >> (oneIndex + 1);  // for zero to be non-trailing, we need to right shift before checking
    zeroIndex = oneIndex + 1;
    while (positiveIntegerCopy != 0 && (positiveIntegerCopy & 1) != 0) {
        zeroIndex ++;
        positiveIntegerCopy >>= 1;
    }

    // flip the zeroIndex bit to 1
    positiveInteger = positiveInteger | (1 << zeroIndex);

    // clear all bits to the right of zeroIndex
    positiveInteger = positiveInteger & (UINT32_MAX << zeroIndex);

    // add in zeroIndex - oneIndex - 1 number of 1s to the end of the number (this accounts for examples like
    // 0b11011001111100 where zeroIndex and oneIndex are separated by ones that need to be added in least significant
    // places.
    positiveInteger = positiveInteger | ((1 << (zeroIndex - oneIndex - 1)) - 1);
    return positiveInteger;
}

uint32_t getPrev(uint32_t positiveInteger) {
    uint32_t oneIndex = 0;   // index of the rightmost 1
    uint32_t zeroIndex = 0;  // index of the rightmost 0 that has 1s to the right of it

    if (positiveInteger == 0 || positiveInteger >= UINT32_MAX) return static_cast<uint32_t>(-1);

    // find the least significant zero
    uint32_t positiveIntegerCopy = positiveInteger;
    while (positiveIntegerCopy != 0 && (positiveIntegerCopy & 1) != 0) {
        zeroIndex ++;
        positiveIntegerCopy >>= 1;
    }

    // find the least significant 1 *to the left of* the least significant zero
    positiveIntegerCopy = positiveInteger >> (zeroIndex + 1);
    if (positiveIntegerCopy == 0) return static_cast<uint32_t>(-1);  // check for 0b0...001111 edge case
    oneIndex += zeroIndex + 1;  // account for the right shift before computing one index
    while (positiveIntegerCopy != 0 && (positiveIntegerCopy & 1) != 1) {
        oneIndex ++;
        positiveIntegerCopy >>= 1;
    }

    // flip the oneIndex bit to 0
    positiveInteger = positiveInteger & (~(1 << oneIndex));

    // clear all the bits to the right of oneIndex
    positiveInteger = positiveInteger & (UINT32_MAX << oneIndex);

    // add in zeroIndex + 1 number of ones in most significant positions to the right of oneIndex
    uint32_t ones = (1 << (zeroIndex + 1)) - 1;
    ones <<= (oneIndex - zeroIndex - 1);
    positiveInteger |= ones;
    return positiveInteger;
}


TEST_CASE("Chapter 05 - Problem 04 - nextNumber()", "test"){
    REQUIRE(getPrev(0b0001) == -1);
    REQUIRE(getNext(0b0001) == 0b0010);
    //REQUIRE(getPrev(0b0100) == 0b0010);
    REQUIRE(getPrev(0b0100) == 0b0011);
    REQUIRE(getNext(0b0100) == 0b1000);
    REQUIRE(getPrev(0b10011110000011) == 0b10011101110000);  // example from textbook
    REQUIRE(getNext(0b11011001111100) == 0b11011010001111);  // example from textbook
}      

